#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "book.h"


int init_book(struct book* p_book, const char* p_id, const char* p_title, const char* p_author, struct date release) {
	if(strlen(p_id) > 9)
        return 0;

    p_book->title = malloc(strlen(p_title) + 1);
    p_book->author = malloc(strlen(p_author) + 1);
    strcpy(p_book->title, p_title);
    strcpy(p_book->author, p_author);
    strcpy(p_book->id, p_id);
    p_book->release_date = release;

    return 1;
}

struct book* add_to_collection(struct book* collection, unsigned int size, struct book new_book) {
    collection = realloc(collection, (size + 1) * sizeof(struct book));

    int ret = init_book(&collection[size], new_book.id, new_book.title, new_book.author, new_book.release_date);
    if(ret == 0) {
        printf("Too long id provided!");
        free(collection);
        return NULL;
    }

    return collection;
}