#include <iostream>
#include "list_perumahan.h"
#include "list_rumah.h"
#include "mainmenu.h"
using namespace std;

int main()
{
    List_parent L;
    List_child K;
    createList_child(K);
    createList_parent(L);
    cout << "Hello world!" << endl;
    mainmenu(L,K);
    return 0;
}

