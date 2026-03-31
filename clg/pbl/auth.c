#include <stdio.h>
#include "auth.h"
#include "mystrings.h"

int login() {
    char username[50], password[50];
    printf("\n===== ADMIN LOGIN =====\n");
    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);

    if (myStrcmp(username, "admin") == 0 && myStrcmp(password, "1234") == 0) {
        printf("\nLogin Successful!\n");
        return 1;
    } else {
        printf("\nInvalid Username or Password!\n");
        return 0;
    }
}