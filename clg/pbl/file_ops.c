#include <stdio.h>
#include <stdlib.h>
#include "file_ops.h"
#include "records.h"
#include "mystrings.h"

void addBook() {
    FILE *fp = fopen("books.dat", "ab");
    if (fp == NULL) return;
    Book b;

    printf("\nEnter Book ID: "); scanf("%d", &b.id);
    printf("Enter Title: "); scanf(" %[^\n]", b.title);
    printf("Enter Author: "); scanf(" %[^\n]", b.author);
    printf("Enter ISBN: "); scanf("%s", b.isbn);

    fwrite(&b, sizeof(Book), 1, fp);
    fclose(fp);
    printf("\nBook Added Successfully!\n");
}

void displayBooks() {
    FILE *fp = fopen("books.dat", "rb");
    Book b;
    if (fp == NULL) { printf("\nNo Records Found!\n"); return; }

    printf("\n===== BOOK LIST =====\n");
    while (fread(&b, sizeof(Book), 1, fp)) {
        printf("\nID: %d | Title: %s | Author: %s | ISBN: %s\n", b.id, b.title, b.author, b.isbn);
    }
    fclose(fp);
}

void searchBook() {
    FILE *fp = fopen("books.dat", "rb");
    Book b;
    char search[100];
    int found = 0;
    if (fp == NULL) return;

    printf("\nEnter Search Term (Title/Author/ISBN): ");
    scanf(" %[^\n]", search);

    while (fread(&b, sizeof(Book), 1, fp)) {
        if (myStrcmp(b.title, search) == 0 || myStrcmp(b.author, search) == 0 || myStrcmp(b.isbn, search) == 0) {
            printf("\nBook Found: ID %d, %s by %s\n", b.id, b.title, b.author);
            found = 1;
        }
    }
    if (!found) printf("\nNo Match Found.\n");
    fclose(fp);
}

void deleteBook() {
    FILE *fp = fopen("books.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    Book b;
    int id, found = 0;

    printf("\nEnter Book ID to Delete: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id != id) fwrite(&b, sizeof(Book), 1, temp);
        else found = 1;
    }

    fclose(fp); fclose(temp);
    remove("books.dat");
    rename("temp.dat", "books.dat");
    if (found) printf("\nBook Deleted Successfully!\n");
}