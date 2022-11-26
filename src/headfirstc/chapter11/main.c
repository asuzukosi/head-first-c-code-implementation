/*
This program is responsible for network communication
*/

#include<stdio.h>
#include<sys/socket.h>
#include"error.h"
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

int listener_d;

void shut_down_server(int sig){
    if (listener_d){
        close(listener_d);
    }

    fprintf(stderr, "Shutting Down Server, ...Bye!\n");
    exit(0);
}


int bind_to_port(int port_number){
    listener_d = socket(PF_INET, SOCK_STREAM, 0);

    if (listener_d == -1)
        error("Can't open socket");
    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t)htons(port_number);
    name.sin_addr.s_addr = htonl(INADDR_ANY);

    int reuse = 1;
    if (setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
        error("Can't set the reuse option on the socket");
    
    int c = bind (listener_d, (struct sockaddr *) &name, sizeof(name));
    if (c == -1){
            error("Can't bind to socket");

    }
    
    printf("Successfully bound to port %i \n", port_number);
}

int accept_client(int listener_d){
    puts("connection accepted");
    struct sockaddr_storage client_addr;
    unsigned int address_size = sizeof(client_addr);
    int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);

    if (connect_d == -1)
        error("Can't open secondary socket");

    return connect_d;
}


void handle_connection(int connect_d, char *msg){
    if(msg == NULL){
        msg = "Internet Knock-Knock Protocol Server\r\nVersion 1.0\r\nKnock! Knock! from Kosi Asuzu\r\n> ";
    }
    if(send(connect_d, msg, strlen(msg), 0) == -1)
        error("send");
}

int catch_signal(int sig, void (*handler)(int)){
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);

    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}


int main(int argc, char const *argv[])
{   
    if(catch_signal(SIGINT, shut_down_server) == -1){
        error("Can't map the handler");
    }

    printf("This application is used for networked communication \n");
    bind_to_port(3000);

    if (listen(listener_d, 10) == -1)
        error("Can't listen");
    while (1)
    {   

        int connect_d = accept_client(listener_d);
        if(fork() != -1){
            handle_connection(connect_d, NULL);   
        }
    }
    
    return 0;
}
