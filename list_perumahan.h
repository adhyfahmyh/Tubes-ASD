#ifndef LIST_PERUMAHAN_H_INCLUDED
#define LIST_PERUMAHAN_H_INCLUDED

#include <iostream>
using namespace std;

#define first_parent(L) L.first_parent
#define next_parent(P) P->next_parent
#define info_parent(P) P->info_parent
#define child(P) P->child

#include "list_rumah.h"

struct perumahan
{
    string nama_perumahan;
    int id_perumahan;
    int jumlah_rumah;
    string alamat_perumahan;
    int tahunPembuatan_perumahan;
};
typedef perumahan infotype_parent;
typedef struct elmlist_parent *address_parent;

struct elmlist_parent
{
    infotype_parent info_parent;
    address_parent next_parent;
    List_child child;
};

struct List_parent
{
    address_parent first_parent;
};

void createList_parent(List_parent &L);
void insertFirst_parent(List_parent &L, address_parent P);
void insertAfter_parent(List_parent &L, address_parent Prec, address_parent P);
void insertLast_parent(List_parent &L, address_parent P);
void deleteFirst_parent(List_parent &L, address_parent &P);
void deleteLast_parent(List_parent &L, address_parent &P);
void deleteAfter_parent(List_parent &L, address_parent Prec, address_parent &P);
address_parent alokasi_parent(infotype_parent x);
void dealokasi_parent(address_parent &P);
address_parent findElm_parent(List_parent L, infotype_parent x);
void printInfo_parent(List_parent L);
void searchdelete_parent(List_parent &L,infotype_parent x);
void searchview_parent(List_parent L,infotype_parent x);
void insert_parent(List_parent &L, infotype_parent x);
void searchedit_parent(List_parent &L,infotype_parent x);

#endif // LIST_PERUMAHAN_H_INCLUDED
