#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct NOD_LISTA {
    int cheie;
    struct NOD_LISTA *next, *prev;
} T_NOD_LISTA;   //alias pentru struct NOD_LISTA

typedef struct {
    T_NOD_LISTA *head;
} T_LISTA;  // alt alias ca sa simplifice denumirea capului listei

// Function declarations
void makenull(T_LISTA *L);
T_NOD_LISTA *list_search(T_LISTA *L, int key);
void list_delete(T_LISTA *L, T_NOD_LISTA *x);
void list_free(T_LISTA *L);
void list_insert(T_LISTA *L, T_NOD_LISTA *x);
void list_print(T_LISTA *L);

#endif // HEADER_H_INCLUDED
