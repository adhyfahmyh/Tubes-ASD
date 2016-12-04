#include "list_perumahan.h"

void createList_parent(List_parent &L)
{
    first_parent(L) = NULL;
}

void insertFirst_parent(List_parent &L, address_parent P)
{
    if(first_parent(L) == NULL)
    {
        first_parent(L) = P;
    }
    else
    {
        next_parent(P) = first_parent(L);
        first_parent(L) = P;
    }
}

void insertAfter_parent(List_parent &L, address_parent Prec, address_parent P)
{
    if (next_parent(Prec)==NULL)
    {
        next_parent(Prec)=P;
    }
    else
    {
        next_parent(P)=next_parent(Prec);
        next_parent(Prec)=P;
    }
}

void insertLast_parent(List_parent &L, address_parent P)
{
    address_parent Q;
    if(first_parent(L) == NULL)
    {
        first_parent(L) = P;
    }
    else
    {
        Q = first_parent(L);
        while(next_parent(Q) != NULL)
        {
            Q = next_parent(Q);
        }
        next_parent(Q)=P;
    }
}
void deleteFirst_parent(List_parent &L, address_parent &P)
{
    if(first_parent(L) == NULL)
    {
    }
    else
    {
        P=first_parent(L);
        first_parent(L)=next_parent(P);
        next_parent(P)=NULL;
    }
}

void deleteLast_parent(List_parent &L, address_parent &P)
{
    address_parent Q;
    if(first_parent(L) == NULL)
    {
    }
    else
    {
        Q = first_parent(L);
        P = first_parent(L);
        while(next_parent(P) != NULL)
        {
            P = next_parent(P);
        }
        if (P==first_parent(L))
        {
            deleteFirst_parent(L,P);
        }
        else
        {
            while(next_parent(Q)!= P)
            {
                Q = next_parent(Q);
            }
            next_parent(Q)=NULL;
        }
    }
}

void deleteAfter_parent(List_parent &L, address_parent Prec, address_parent &P)
{
    if (next_parent(Prec)==NULL)
    {
        deleteLast_parent(L,P);
    }
    else
    {
        P=next_parent(Prec);
        next_parent(Prec)=next_parent(P);
        next_parent(P)=NULL;
    }
}
address_parent alokasi_parent(infotype_parent x)
{
    address_parent P;
    P = new elmlist_parent;
    info_parent(P) = x;
    next_parent(P) = NULL;
    createList_child(child(P));
    return P;
}

void dealokasi_parent(address_parent &P)
{
    delete P;
}

void printInfo_parent(List_parent L)
{
    address_parent P = first_parent(L);
    if(first_parent(L)!=NULL)
    {
        do
        {
            cout<<info_parent(P).id_perumahan<<endl;
            cout<<info_parent(P).nama_perumahan<<endl;
            cout<<info_parent(P).jumlah_rumah<<endl;
            cout<<info_parent(P).alamat_perumahan<<endl;
            cout<<info_parent(P).tahunPembuatan_perumahan<<endl;
            P = next_parent(P);
        }
        while((P)!=NULL);
    }
}

address_parent findElm_parent(List_parent L, infotype_parent x)
{
    address_parent P = first_parent(L);
    while(P != NULL)
    {
        if(info_parent(P).id_perumahan == x.id_perumahan)
        {
            return P;
        }
        P = next_parent(P);
    }
    return NULL;
}

void searchdelete_parent(List_parent &L,infotype_parent x)
{
    address_parent P;
    address_parent Q = findElm_parent(L,x);
    if (Q!=NULL)
    {
        if (next_parent(Q)==NULL)
        {
            deleteLast_parent(L,P);
        }
        else if (Q==first_parent(L))
        {
            deleteFirst_parent(L,P);
        }
        else
        {
            P=first_parent(L);
            while (next_parent(P)!=Q)
            {
                P=next_parent(P);
            }
            Q=P;
            deleteAfter_parent(L,Q,P);
        }
        cout<<"Finish"<<endl;
    }
    else
    {
        cout<<"Data tidak ada"<<endl;
    }
}

void searchview_parent(List_parent L,infotype_parent x)
{
    address_parent Q=findElm_parent(L,x);
    if (Q!=NULL)
    {
        cout<<"     Data Perumahan     "<<endl;
        cout<<" "<<endl;
        cout<<" "<<endl;
        cout<<"Id Perumahan          = "<<info_parent(Q).id_perumahan<<endl;
        cout<<"Nama Perumahan        = "<<info_parent(Q).nama_perumahan<<endl;
        cout<<"Total jumlah rumah    = "<<info_parent(Q).jumlah_rumah<<endl;
        cout<<"Alamat Perumahan      = "<<info_parent(Q).alamat_perumahan<<endl;
        cout<<"Tahun Pembuatan rumah = "<<info_parent(Q).tahunPembuatan_perumahan<<endl;
        cout<<" "<<endl;
        cout<<"Data Rumah"<<endl;
        cout<<" "<<endl;
        printInfo_child(child(Q));
    }
    else
    {
        cout<<"Data tidak ada!"<<endl;
    }
}
void insert_parent(List_parent &L, infotype_parent x)
{

    if (first_parent(L)==NULL)
    {
        address_parent P = alokasi_parent(x);
        insertFirst_parent(L,P);
    }
    else
    {
        address_parent P = first_parent(L);
        while (next_parent(P)!=NULL && x.id_perumahan!=info_parent(P).id_perumahan)
        {
            P=next_parent(P);
        }
        if (x.id_perumahan!=info_parent(P).id_perumahan)
        {
            address_parent Q = alokasi_parent(x);
            insertAfter_parent(L,P,Q);
        }
        else
        {
            cout<<endl;
            cout<<"Sudah ada!"<<endl;
        }
    }
}
void searchedit_parent(List_parent &L,infotype_parent x)
{
    address_parent Q = findElm_parent(L,x);
    if (Q!=NULL)
    {
        cout<<"Masukkan Id Perumahan Baru = ";
        cin>>x.id_perumahan;
        info_parent(Q).id_perumahan = x.id_perumahan;
        cout<<"Masukkan Nama Perumahan Baru= "<<endl;
        cin>>x.nama_perumahan;
        info_parent(Q).nama_perumahan = x.nama_perumahan;
        cout<<"Masukkan Total Jumlah Rumah Baru= "<<endl;
        cin>>x.jumlah_rumah;
        info_parent(Q).jumlah_rumah = x.jumlah_rumah;
        cout<<"Masukkan Alamat Perumahan Baru= "<<endl;
        cin>>x.alamat_perumahan;
        info_parent(Q).alamat_perumahan = x.alamat_perumahan;
        cout<<"Masukkan Tahun Pembuatan Perumahan Baru= "<<endl;
        cin>>x.tahunPembuatan_perumahan;
        info_parent(Q).tahunPembuatan_perumahan = x.tahunPembuatan_perumahan;
    }
    else
    {
        cout<<"Data tidak ada!"<<endl;
    }
}
