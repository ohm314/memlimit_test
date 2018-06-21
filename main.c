#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    size_t sz = 1024; // 1kB
    char szstr[20];
    long i;
    char* arr;
    if (argc == 2) {
        int szl = strlen(argv[1]) - 1;
        char unit = argv[1][szl];
        memcpy(szstr, argv[1],szl);
        sz = atoi(szstr);
        switch (unit) {
            case 'k':
                sz *= 1024;
                break;
            case 'm':
                sz *= 1024*1024;
                break;
            case 'g':
                sz *= 1024*1024*1024;
                break;
        }
    }
    arr = (char*)malloc(sizeof(char)*sz);
    for (i = 0; i < sz; ++i) {
        arr[i] = 42;
    }
    printf("%ld %d\n",sz, arr[sz/2]);
    free(arr);

    return 0;
}