/*
This program is a sample http client written 
*/
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>


int connect_to_server_with_ip(char* ip_address){
    int s = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in si;
    memset(&si, 0, sizeof(si));
    si.sin_family = PF_INET;
    si.sin_addr.s_addr = inet_addr(ip_address);
    si.sin_port = htons(80);
    connect(s, (struct sockaddr *) &si, sizeof(si));
}

int connect_to_server_with_domain(char* domain_name){
    struct addrinfo *res;
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo(domain_name, "80", &hints, &res);
    int s = socket(res->ai_family, res->ai_socktype,res->ai_protocol);
    connect(s, res->ai_addr, res->ai_addrlen);
    freeaddrinfo(res);
}

int say(int socket, char *s){
    int result = send(socket, s, strlen(s), 0);
    if (result == -1){
        fprintf(stderr, "%s: %s\n", "Error talking to the server",strerror(errno));
    }
    return result;
    }

int main(int argc, char const *argv[])
{
    /* code */
    int s = socket(PF_INET, SOCK_STREAM, 0);
    return 0;
}
