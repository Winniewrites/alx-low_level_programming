char* _strcat(char* dest, char* src) {
    char* ptr = dest;
    // Find the end of dest
    while (*ptr != '\0') {
        ptr++;
    }
    // Append src to dest
    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    // Add a terminating null byte
    *ptr = '\0';
    return dest;
}
