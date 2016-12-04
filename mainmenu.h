#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED


#include "list_perumahan.h"






void mainmenu(List_parent &L,List_child &K);
void insertData(List_parent &L,List_child &K);
void searchDelete(List_parent &L,List_child &K);
void searchEdit(List_parent &L,List_child &K);
void searchView(List_parent &L,List_child &K);
void sorting(List_parent &L, List_child &K);
void viewAll(List_parent &L,List_child &K);
void reporting(List_parent &L,List_child &K);
void sortParent(List_parent &L,List_child &K);
void sortChild(List_parent &L,List_child &K);



#endif // MAINMENU_H_INCLUDED
