/*
This program is the basis for a security library in c
*/

// This function checks if a string has been encrypted
void encrypt(char *message){
    while (*message) {
        *message = *message ^ 31;
        message++;
    }
}


// This function checks if an encrypted string has been modified
int checksum(char *message){
    int c = 0;
    while (*message) {
        c += c ^ (int)(*message);
        message++;
    }
    return c;
}