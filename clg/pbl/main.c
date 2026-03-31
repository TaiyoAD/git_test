#include <stdio.h>
#include "auth.h"     // User Authentication Module
#include "file_ops.h" // File Handling Module

int main() {
    int choice;

    // 1. User Authentication Module
    if (!login()) {
        return 0; 
    }

    // 5. Main Driver Module Logic
    do {
        printf("\n===== LIBRARY MENU =====\n");
        printf("1. Add Book\n2. Display Books\n3. Search Book\n4. Delete Book\n5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;    // From File Handling Module
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: printf("\nExiting...\n"); break;
            default: printf("\nInvalid Choice!\n");
        }
    } while (choice != 5);

    return 0;
}