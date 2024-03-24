#include <stdio.h>
#include <ctype.h>
#include <string.h>


void standardizeName(char *name) {
    int i;
    int len = strlen(name);
    int capitalizeNext = 1;

  
    for (i = 0; i < len; i++) {
        name[i] = tolower(name[i]);
    }


    for (i = 0; i < len; i++) {
        if (isspace(name[i])) {
            capitalizeNext = 1;
        } else {
            if (capitalizeNext) {
                name[i] = toupper(name[i]);
                capitalizeNext = 0;
            }
        }
    }
}

int main() {
    char name[100];

    printf("Nhap ten cua ban: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; 

    standardizeName(name);

    printf("Hello %s\n", name);

    return 0;
}
