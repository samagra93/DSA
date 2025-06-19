#include <stdio.h>

void toLowercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
       
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;  
        }
    }
}

int main() {
    char str[100];

    printf("Enter an uppercase string: ");
    fgets(str, sizeof(str), stdin); 

    toLowercase(str);

    printf("Lowercase string: %s", str);

    return 0;
}

