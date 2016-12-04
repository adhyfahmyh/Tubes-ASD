#include <iostream>
using namespace std;
#include "mainmenu.h"
#include "list_perumahan.h"

void mainmenu(List_parent &L,List_child &K)
{
    cout<<"                Main Menu                 "<<endl;
    cout<<"     1. Insert data                       "<<endl;
    cout<<"     2. Search and View                   "<<endl;
    cout<<"     3. Search and Delete                 "<<endl;
    cout<<"     4. Search and Edit                   "<<endl;
    cout<<"     5. Sort                              "<<endl;
    cout<<"     6. View All                          "<<endl;
    cout<<"     7. Reporting                         "<<endl;
    cout<<"     8. Exit                              "<<endl;
    int menu;
    cout<<"     Pilih Menu : ";
    cin>>menu;
    switch(menu)
    {
    case 1:
        insertData(L,K);
        break;
    case 2:
        searchView(L,K);
        break;
    case 3:
        searchDelete(L,K);
        break;
    case 4:
        searchEdit(L,K);
        break;
    case 5:
        sorting(L,K);
        break;
    case 6:
        viewAll(L,K);
        break;
    case 7:
        reporting(L,K);
        break;
    case 8:
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"Terima Kasih"<<endl;
    }
}

void insertData(List_parent &L,List_child &K)
{
    cout<<"             Menu Insert Data             "<<endl;
    cout<<"     1. Insert Data Perumahan             "<<endl;
    cout<<"     2. Insert Data Rumah                 "<<endl;
    int menu;
    infotype_parent x;
    infotype_child y;
    cout<<"     Pilih Menu : ";
    cin>>menu;
    switch(menu)
    {
    case 1:
        cout<<"Masukkan Id Perumahan= ";
        cin>>x.id_perumahan;
        cout<<"Masukkan Nama Perumahan= ";
        cin>>x.nama_perumahan;
        cout<<"Masukkan Total Jumlah Rumah= ";
        cin>>x.jumlah_rumah;
        cout<<"Masukkan Alamat Perumahan= ";
        cin>>x.alamat_perumahan;
        cout<<"Masukkan Tahun Pembuatan Perumahan= ";
        cin>>x.tahunPembuatan_perumahan;
        insert_parent(L,x);
        break;
    case 2:
        cout<<"Pilih Perumahan"<<endl;
        cout<<"Masukkan Id Perumahan= ";
        cin>>x.id_perumahan;
        address_parent P=findElm_parent(L,x);
        if (P!=NULL)
        {
            cout<<"Masukkan No rumah= ";
            cin>>y.no_rumah;
            cout<<"Masukkan Tipe Rumah= ";
            cin>>y.tipe_rumah;
            cout<<"Masukkan Alamat Rumah= ";
            cin>>y.jalan;
            cout<<"Masukkan Luas Rumah= ";
            cin>>y.luas_rumah;
            cout<<"Masukkan Pemilik Rumah= ";
            cin>>y.pemilik_rumah;
            insertchild(child(P),y);
        }
        else
        {
            cout<<"Id Perumahan yang dicari tidak ada"<<endl;
        }
        break;
    }
    mainmenu(L,K);
}

void searchView (List_parent &L,List_child &K)
{
    cout<<"           Menu Search and View           "<<endl;
    cout<<"     1. Search and View Perumahan         "<<endl;
    cout<<"     2. Search and View Rumah             "<<endl;
    int menu;
    cout<<"     Pilih Menu : ";
    cin>>menu;
    infotype_child y;
    infotype_parent x;
    switch(menu)
    {
    case 1:
        cout<<"Masukkan Id Perumahan= ";
        cin>>x.id_perumahan;
        searchview_parent(L,x);
        break;
    case 2:
        cout<<"Pilih Perumahan"<<endl;
        cout<<"Masukkan Id Perumahan= ";
        cin>>x.id_perumahan;
        address_parent P = findElm_parent(L,x);
        if (P!=NULL)
        {
            cout<<"Masukkan No Rumah= ";
            cin>>y.no_rumah;
            searchview_child(child(P),y);
        }
        else
        {
            cout<<"Perumahan yang dicari tidak ada"<<endl;
        }
        break;
    }
    mainmenu(L,K);
}

void searchDelete(List_parent &L,List_child &K)
{
    cout<<"------------------------------------------"<<endl;
    cout<<"            Menu Search and Delete        "<<endl;
    cout<<"     1. Search and Delete Perumahan       "<<endl;
    cout<<"     2. Search and Delete Rumah           "<<endl;
    cout<<"------------------------------------------"<<endl;
    int menu;
    cout<<"     Pilih Menu : ";
    cin>>menu;
    infotype_child y;
    infotype_parent x;
    switch(menu)
    {
    case 1:
        cout<<"Masukkan Id Perumahan= ";
        cin>>x.id_perumahan;
        searchdelete_parent(L,x);
        break;
    case 2:
        cout<<"Pilih Perumahan"<<endl;
        cout<<"Masukkan Id Perumahan= ";
        cin>>x.id_perumahan;
        address_parent P = findElm_parent(L,x);
        if (P!=NULL)
        {
            cout<<"Masukkan No Rumah= ";
            cin>>y.no_rumah;
            searchdelete_child(child(P),y);
        }
        else
        {
            cout<<"Perumahan yang dicari tidak ada"<<endl;
        }
        break;
    }
    mainmenu(L,K);
}

void searchEdit(List_parent &L,List_child &K)
{
    cout<<"            Menu Search and Edit          "<<endl;
    cout<<"     1. Search and Edit Perumahan         "<<endl;
    cout<<"     2. Search and Edit Rumah             "<<endl;
    int menu;
    cout<<"     Pilih Menu : ";
    cin>>menu;
    infotype_child y;
    infotype_parent x;
    switch(menu)
    {
    case 1:
        cout<<"Masukkan Id Perumahan= ";
        cin>>x.id_perumahan;
        searchedit_parent(L,x);
        break;
    case 2:
        cout<<"Pilih Perumahan"<<endl;
        cout<<"Masukkan Id Perumahan= ";
        cin>>x.id_perumahan;
        address_parent P = findElm_parent(L,x);
        if (P!=NULL)
        {
            cout<<"Masukkan No Rumah= ";
            cin>>y.no_rumah;
            searchedit_child(child(P),y);
        }
        else
        {
            cout<<"Perumahan yang dicari tidak ada"<<endl;
        }
        break;
    }
    mainmenu(L,K);
}

void sorting(List_parent &L,List_child &K)
{
    cout<<"            Sorting                       "<<endl;
    cout<<"     1. Sorting Perumahan                 "<<endl;
    cout<<"     2. Sorting Rumah                     "<<endl;
    int menu;
    cout<<"     Pilih Menu : ";
    cin>>menu;
    switch (menu)
    {
    case 1:
        sortParent(L,K);
        break;
    case 2:
        sortChild(L,K);
        break;
    }
}

void sortParent(List_parent &L,List_child &K)
{
    address_parent P=first_parent(L);
    List_parent A;
    createList_parent(A);
    if(first_parent(L)!=NULL)
    {
        while (first_parent(L)!=NULL)
        {
            address_parent P = first_parent(L);
            address_parent adrmax=first_parent(L);
            do
            {
                if (info_parent(P).id_perumahan>info_parent(adrmax).id_perumahan)
                {
                    adrmax=P;
                }
                P = next_parent(P);
            }
            while((P)!=NULL);
            insertLast_parent(A,adrmax);
            searchdelete_parent(L,info_parent(adrmax));
        }
        L=A;
    }
    else
    {
        cout<<"Tidak ada Data"<<endl;
    }
    mainmenu(L,K);
}

void sortChild(List_parent &L,List_child &K)
{
    infotype_parent x;
    address_parent Q=first_parent(L);
    address_child P=first_child(child(Q));

    if (Q!=NULL)
    {
        while(Q!=NULL)
        {
            cout<<"Id Perumahan="<<info_parent(Q).id_perumahan<<endl;
            if(first_child(child(Q))!=NULL)
            {
                List_child A;
                createList_child(A);
                while (first_child(child(Q))!=NULL)
                {
                    address_child P = first_child(child(Q));
                    address_child adrmax=first_child(child(Q));
                    do
                    {
                        if (info_child(P).no_rumah>info_child(adrmax).no_rumah)
                        {
                            adrmax=P;
                        }
                        P = next_child(P);
                    }
                    while((P)!=NULL);
                    address_child h = alokasi_child(info_child(adrmax));
                    insertLast_child(A,h);
                    searchdelete_child(child(Q),info_child(adrmax));
                }
                child(Q)=A;
            }
            else
            {
                cout<<"Tidak ada Data"<<endl;
            }
            Q=next_parent(Q);
        }

    }
    else
    {
        cout<<"Tidak ada data"<<endl;
    }
    mainmenu(L,K);
}

void viewAll(List_parent &L,List_child &K)
{
    address_parent P = first_parent(L);
    if (P!=NULL)
    {
        while(P!=NULL)
        {
            cout<<endl;
            cout<<"Data Perumahan"<<endl;
            cout<<"-------------"<<endl;
            cout<<"Id Perumahan= "<<info_parent(P).id_perumahan<<endl;
            cout<<"Nama Perumahan= "<<info_parent(P).nama_perumahan<<endl;
            cout<<"-------------"<<endl;
            cout<<"Data Rumah"<<endl;
            cout<<"-------------"<<endl;
            printInfo_child(child(P));
            P=next_parent(P);
            cout<<"-------------"<<endl;
        }
    }
    else
    {
        cout<<"Tidak ada Data"<<endl;
    }
    mainmenu(L,K);
}
void reporting(List_parent &L, List_child &K)
{

    int thnRumah=9999;
    int maxLuas=0;
    int jumlahrmh = 0;

    address_parent P = first_parent(L);
    if(P==NULL)
    {
        cout<<"Perumahan tidak ada"<<endl;
    }
    else
    {
        while (P!=NULL)
        {
            if (info_parent(P).tahunPembuatan_perumahan < thnRumah)
            {
                thnRumah = info_parent(P).tahunPembuatan_perumahan;

            }
            address_child Q = first_child(child(P));
            if (Q==NULL)
            {
                cout<<"KOSONG"<<endl;
            }
            else
            {
                while(Q != NULL)
                {
                    jumlahrmh++;
                    if (info_child(Q).luas_rumah > maxLuas)
                    {
                        maxLuas = info_child(Q).luas_rumah;
                    }

                    Q = next_child(Q);
                }

            }
            P = next_parent(P);
        }
        cout<<"Jumlah rumah             = "<<jumlahrmh<<endl;
        cout<<"Rumah yang paling Luas   = "<<maxLuas<<endl;
        cout<<"Perumahan tertua berdiri pada tahun "<<thnRumah<<endl;
    }
}

