#ifndef RECORDS_H
#define RECORDS_H

typedef struct {
    int id;
    char title[100];
    char author[100];
    char isbn[20];
} Book;

#endif