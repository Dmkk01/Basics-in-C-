#include "queue.h"
#include <stdlib.h>
#include <string.h>

int enqueue(struct studentqueue* q, const char* name) {
    while(q->next)
        q = q->next;

    q->next = malloc(sizeof(struct studentqueue));
    q->next->name = malloc(strlen(name) + 1);
    strcpy(q->next->name, name);
    q->next->next = NULL;

    return 1;
}

int dequeue(struct studentqueue* q, char* buffer, unsigned int size) {
    if(q->next == NULL)
        return 0;

    strncpy(buffer, q->next->name, size);
    buffer[size] = 0;

    struct studentqueue* del = q->next;
    q->next = q->next->next;

    free(del->name);
    free(del);

    return 1;
}