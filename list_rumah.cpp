#include "list_rumah.h"

void createList_child(List_child &L)
{
    first_child(L) = NULL;
    last_child(L) = NULL;
}

void insertFirst_child(List_child &L, address_child P)
{
    if((first_child(L)!=NULL) && (last_child(L)!=NULL))
    {
        next_child(P)=first_child(L);
        prev_child(first_child(L))=P;
        first_child(L)=P;
    }
    else
    {
        first_child(L)=P;
        last_child(L)=P;
    }
}

void insertLast_child(List_child &L, address_child P)
{
    if ((first_child(L)!=NULL) && (last_child(L)!=NULL))
    {
        prev_child(P)=last_child(L);
        next_child(last_child(L))=P;
        last_child(L)=P;
    }
    else
    {
        first_child(L)=P;
        last_child(L)=P;
    }
}

void insertAfter_child(address_child &Prec, address_child P)
{
    next_child(P) = next_child(Prec);
    prev_child(P) = Prec;
    prev_child(next_child(Prec)) = P;
    next_child(Prec) = P;
}

void deleteFirst_child(List_child &L, address_child &P)
{
    P=first_child(L);
    if (first_child(L)!=last_child(L))
    {
        first_child(L)=next_child(P);
        next_child(P)=NULL;
        prev_child(first_child(L))=NULL;
    }
    else
    {
        first_child(L)=NULL;
        last_child(L)=NULL;
    }
}

void deleteLast_child(List_child &L, address_child &P)
{
    P=last_child(L);
    if (first_child(L)!=last_child(L))
    {
        last_child(L)=prev_child(last_child(L));
        prev_child(P)=NULL;
        next_child(last_child(L))=NULL;
    }
    else
    {
        first_child(L)=NULL;
        last_child(L)=NULL;
    }
}

void deleteAfter_child(address_child &Prec, address_child &P)
{
    P=next_child(Prec);
    next_child(Prec)=next_child(P);
    prev_child(next_child(P))=Prec;
    prev_child(P)=NULL;
    next_child(P)=NULL;
}


address_child alokasi_child(infotype_child x)
{
    address_child P = new elmlist_child;
    info_child(P) = x;
    next_child(P) = NULL;
    prev_child(P) = NULL;
    return P;
}

void dealokasi_child (address_child &P)
{
    delete P;
}

address_child findElm_child(List_child L, infotype_child x)
{
    address_child P = first_child(L);
    while(P != NULL)
    {
        address_child Q = P;
        while (Q!=NULL&&info_child(Q).no_rumah!=x.no_rumah)
        {
            Q=next_child(Q);
        }
        if(Q!=NULL)
        {
            return Q;
        }
        P = next_child(P);
    }
    return NULL;
}

void printInfo_child(List_child P)
{
    address_child Q = first_child(P);
    if (Q==NULL)
    {
        cout<<"KOSONG"<<endl;
    }
    else
    {
        while(Q !=NULL)
        {
            cout<<"No Rumah= "<<info_child(Q).no_rumah<<endl;
            cout<<"Tipe Rumah= "<<info_child(Q).tipe_rumah<<endl;
            cout<<"Alamat rumah= "<<info_child(Q).jalan<<endl;
            cout<<"Luas Rumah= "<<info_child(Q).luas_rumah<<endl;
            cout<<"Pemilik Rumah= "<<info_child(Q).pemilik_rumah<<endl;
            Q = next_child(Q);
        }
    }
}

void insertchild(List_child &L, infotype_child x)
{

    if (first_child(L)==NULL)
    {
        address_child P = alokasi_child(x);
        insertFirst_child(L,P);
    }
    else
    {
        address_child P = first_child(L);
        while (next_child(P)!=NULL && x.no_rumah!=info_child(P).no_rumah)
        {
            P=next_child(P);
        }
        if (x.no_rumah!=info_child(P).no_rumah)
        {
            address_child Q = alokasi_child(x);
            insertAfter_child(P,Q);
        }
        else
        {
            cout<<endl;
            cout<<"Sudah ada!"<<endl;
        }
    }
}
void searchdelete_child(List_child &L, infotype_child x)
{
    address_child P;
    address_child Q = findElm_child(L,x);
    if (Q!=NULL)
    {
        if (next_child(Q) == NULL)
        {
            deleteLast_child(L,P);
        }
        else if (Q==first_child(L))
        {
            deleteFirst_child(L,P);
        }
        else
        {
            P=first_child(L);
            while (next_child(P)!=Q)
            {
                P=next_child(P);
            }
            Q=P;
            deleteAfter_child(Q,P);
        }
        cout<<"Finish"<<endl;
    }
    else
    {
        cout<<"Data tidak ada"<<endl;
    }

}
void searchview_child(List_child L,infotype_child x)
{
    address_child Q = findElm_child(L,x);
    if (Q!=NULL)
    {
        cout<<"No Rumah     = "<<info_child(Q).no_rumah<<endl;
        cout<<"Tipe Rumah   = "<<info_child(Q).tipe_rumah<<endl;
        cout<<"Alamat Rumah = "<<info_child(Q).jalan<<endl;
        cout<<"Luas Rumah   = "<<info_child(Q).luas_rumah<<endl;
        cout<<"Pemilik Rumah= "<<info_child(Q).pemilik_rumah<<endl;
    }
    else
    {
        cout<<"Data tidak ada!"<<endl;
    }
}

void searchedit_child(List_child &L,infotype_child x)
{

    address_child Q = findElm_child(L,x);
    if (Q!=NULL)
    {
        cout<<"Masukkan No rumah Baru       = ";
        cin>>x.no_rumah;
        info_child(Q).no_rumah = x.no_rumah;
        cout<<"Masukkan Tipe Rumah Baru     = "<<endl;
        cin>>x.tipe_rumah;
        info_child(Q).tipe_rumah = x.tipe_rumah;
        cout<<"Masukkan Alamat Rumah Baru   = "<<endl;
        cin>>x.jalan;
        info_child(Q).jalan = x.jalan;
        cout<<"Masukkan Luas Rumah Baru     = "<<endl;
        cin>>x.luas_rumah;
        info_child(Q).luas_rumah = x.luas_rumah;
        cout<<"Masukkan Pemilik Rumah Baru  = "<<endl;
        cin>>x.pemilik_rumah;
        info_child(Q).pemilik_rumah = x.pemilik_rumah;
    }
    else
    {
        cout<<"Data tidak ada!"<<endl;
    }
}
