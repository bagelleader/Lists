#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
    int s = -1;
    int key;
    T_LISTA L;
    T_NOD_LISTA *x;

    makenull(&L); //Initializare lista

    while (s != 0) {
        printf("1: Insert | 2: Search | 3: Delete | 4: Print | 0: Exit\n");
        scanf("%d", &s);


        switch (s) {
            case 1: {
                printf("Introduceti cheia: ");
                scanf("%d", &key);
                x = (T_NOD_LISTA*)malloc(sizeof(T_NOD_LISTA));
                x->cheie = key;
                x->next = NULL;
                x->prev = NULL;
                list_insert(&L, x);
                break;
            }
            case 2: {
                printf("Cautati cheia: ");
                scanf("%d", &key);
                x = list_search(&L, key);
                if (x != NULL) {
                    printf("Cheia %d gasita.\n", x->cheie);
                } else {
                    printf("Cheie negasita.\n");
                }
                break;
            }
            case 3: {
                printf("Stergeti cheia: ");
                scanf("%d", &key);
                x = list_search(&L, key);
                if (x != NULL) {
                    list_delete(&L, x);
                    printf("Cheia %d a fost stearsa.\n", key);
                } else {
                    printf("Cheie negasita.\n");
                }
                break;
            }
            case 4: {
                printf("Lista: ");
                list_print(&L);
                break;
            }
            case 0: {
                printf("Iesire...\n");
                break;
            }
            default: {
                printf("Comanda invalida!\n");
                break;
            }
        }
    }

    list_free(&L); // Free the entire list
    return 0;
}
