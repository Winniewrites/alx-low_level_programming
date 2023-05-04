#include "main.h"
char* _strncat(char* dest, char* src, int n) {
    char* ptr = dest;
    // Find the end of dest
    while (*ptr != '\0') {
        ptr++;
    }
    // Append at most n bytes from src to dest
    while (*src != '\0' && n > 0) {
        *ptr = *src;
        ptr++;
        src++;
        n--;
    }
    // Add a terminating null byte
    *ptr = '\0';
    return dest;
}

