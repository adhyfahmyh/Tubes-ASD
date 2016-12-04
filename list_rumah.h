#ifndef LIST_RUMAH_H_INCLUDED
#define LIST_RUMAH_H_INCLUDED

#include <iostream>
using namespace std;

#define next_child(P) P->next_child
#define prev_child(P) P->prev_child
#define first_child(L) L.first_child
#define last_child(L) L.last_child
#define info_child(P) P->info_child



struct rumah
{
    string tipe_rumah;
    int no_rumah;
    string jalan;
    int luas_rumah;
    string pemilik_rumah;
};

typedef rumah infotype_child;
typedef struct elmlist_child *address_child;

struct elmlist_child
{
    infotype_child info_child;
    address_child next_child;
    address_child prev_child;
};

struct List_child
{
    address_child first_child;
    address_child last_child;
};

void createList_child(List_child &L);
void insertFirst_child(List_child &L, address_child P);
void insertLast_child(List_child &L, address_child P);
void insertAfter_child(address_child &Prec, address_child P);
void deleteFirst_child(List_child &L, address_child &P);
void deleteLast_child(List_child &L, address_child &P);
void deleteAfter_child(address_child &Prec, address_child &P);
address_child alokasi_child(infotype_child x);
void dealokasi_child(address_child &P);
address_child findElm_child(List_child L, infotype_child x);
void printInfo_child(List_child L);
void insertchild(List_child &L, infotype_child x);
void searchdelete_child(List_child &L, infotype_child x);
void searchview_child(List_child L,infotype_child x);
void searchedit_child(List_child &L,infotype_child x);

#endif // LIST_RUMAH_H_INCLUDED
