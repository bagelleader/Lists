#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void makenull(T_LISTA *L) {
    L->head = (T_NOD_LISTA*)malloc(sizeof(T_NOD_LISTA));
    L->head->next = NULL;
    L->head->prev = NULL;
}

T_NOD_LISTA *list_search(T_LISTA *L, int key) {
    T_NOD_LISTA *x = L->head->next; // Start from the first element
    while (x != NULL && x->cheie != key) {
        x = x->next;
    }
    return x; // NULL if not found
}

void list_delete(T_LISTA *L, T_NOD_LISTA *x) {
    if (x == NULL) return; // If node is NULL, nothing to delete

    if (x->prev != NULL) {
        x->prev->next = x->next;
    } else {
        L->head->next = x->next; // Deleting first node
    }
    if (x->next != NULL) {
        x->next->prev = x->prev;
    }
    free(x);
}

void list_free(T_LISTA *L) {
    T_NOD_LISTA *x = L->head->next;
    while (x != NULL) {
        T_NOD_LISTA *temp = x;
        x = x->next;
        free(temp);
    }
    free(L->head); // Free the dummy node
}

void list_insert(T_LISTA *L, T_NOD_LISTA *x) {
    if (x == NULL) return;

    x->next = L->head->next; // Insert at the beginning
    if (L->head->next != NULL) {
        L->head->next->prev = x;
    }
    L->head->next = x;
    x->prev = L->head;
}

void list_print(T_LISTA *L) {
    T_NOD_LISTA *x = L->head->next; // Start from the first real node
    if (x == NULL) {
        printf("Lista e vida\n");
        return;
    }
    while (x != NULL) {
        printf("%d ", x->cheie);
        x = x->next;
    }
    printf("\n");
}
