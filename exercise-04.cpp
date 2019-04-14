/**
Nama Program    : exercise-04
Nama            : Fauzan Akmal Hariz
NPM             : 140810180005
Tanggal buat    : 26 Maret 2019
Deskripsi       : strukdat-05_Represent Phone Book Data In a Multi Linked List
**/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Contact{
	char name[10];
	char phone[12];
	Contact* next;
};

struct Index{
	char index[10];
	Index* next;
	Contact* nextContact;
};

typedef Contact* pointerCont;
typedef Index* pointerInd;
typedef pointerInd ListInd;

void createListIndex(ListInd& First)
{
    First=NULL;
}

void createElmtIndex(pointerInd& pBaru)
{
	pBaru=new Index;
    cout<<"Silahkan Masukan Index\t: "; cin.ignore(); cin.getline(pBaru->index, 10);
    pBaru->next=NULL;
    pBaru->nextContact=NULL;
}

void createElmtData(pointerCont& pBaru)
{
	pBaru = new Contact;
    cout<<"Silahkan Masukan Nama\t: "; cin.ignore(); cin.getline(pBaru->name, 10);
    cout<<"Silahkan Masukan Nomor Telepon\t: "; cin.getline(pBaru->phone, 12);
    pBaru->next = NULL;
}

void traversalIndex(ListInd First)
{
    pointerInd pBantu;
    pBantu=First;
    int x=1;
    cout<<"List Index Phone\t: "<<endl;
    while (pBantu!=NULL)
    {
        cout<<x++ <<". " <<pBantu->index <<endl;
            pBantu=pBantu->next;
    }
}

void insertLastIndex(ListInd& First, pointerInd pBaru)
{
    pointerInd last;
    if (First==NULL)
    {
        First=pBaru;
    }
    else
    {
        last=First;
        while (last->next!=NULL)
        {
            last=last->next;
        }
        last->next=pBaru;
    }
}

void deleteFirstIndex(ListInd& First, pointerInd& pHapus)
{
    if (First==NULL)
    {
        pHapus=NULL;
        cout<<"List Kosong, Tidak Ada ang Dihapus" <<endl;
	}
    else if (First->next==NULL)
    {
        pHapus=First;
        First=NULL;
    }
    else
    {
        pHapus=First;
        First=First->next;
        pHapus->next=NULL;
	}
}

void traversalIndexContact(ListInd First)
{

	pointerInd pBantuInd;
    pointerCont pBantuCont;

	cout<<"Daftar Lengkap Index dan Contact"<<endl;
    cout<<"================================"<<endl;
    cout<<"Index\t\tNama\tPhone"<<endl;

    pBantuInd=First;
    while (pBantuInd!=NULL)
    {
        cout<<pBantuInd->index<<"\t";
        pBantuCont=pBantuInd->nextContact;
        while (pBantuCont!=NULL)
        {
            cout<<pBantuCont->name<<"\t";
            cout<<pBantuCont->phone<<endl<<"\t";
            pBantuCont=pBantuCont->next;
        }
        pBantuInd=pBantuInd->next;
        cout<<endl;
    }
}

void linearSearch(ListInd& First, int cari, pointerInd& pCari)
{
    pCari = First;
    int ketemu = 0;
    cout<<"Nama kontak yang dicari: "; cin>>cari;
    while(pCari!=NULL && ketemu==0)
    {
        if (pCari->nextContact->name[10]==cari)
        {
            ketemu=1;
		}
        else
        {
            pCari=pCari->next;
        }
    }

	if (ketemu==1)
    {
        cout<<"Nama Kontak Ditemukan."<<endl;
	}
    else
    {
        cout<<"Tidak Ditemukan Nama Kontak yang Dicari."<<endl;
    }
}

void insertLastContact(ListInd& First, pointerCont pBaru, char key[10])
{
	pointerInd pAng;
    int ketemu=0;
    pAng = First;
    while(pAng!=NULL && ketemu==0)
    {
        if (strcmp(pAng->index,key)==0)
        {
            ketemu=1;
        }
        else
        {
            pAng=pAng->next;
        }
    }

    if(ketemu)
    {
        if (pAng->nextContact==NULL)
        {
            pAng->nextContact=pBaru;
        }
        else
        {
            while (pAng->nextContact->next!=NULL)
            {
                pAng->nextContact=pAng->nextContact->next;
            }
            pAng->nextContact->next=pBaru;
        }
    }
    else
    {
        cout<<"Tidak ditemukan"<<endl;
    }
}

int main()
{
	pointerInd d;
    pointerCont p;
    ListInd First;
    char key[10];
    int pilih;

    cout<<"==============================================="<<endl;
	cout<<"              Daftar List Contact              "<<endl;
    cout<<"==============================================="<<endl <<endl;


	createListIndex(First);

	do
    {
        system("cls");
		cout<<"==============Pilihan Menu============="<<endl;
        cout<<"1. Insert Index                       "<<endl;
        cout<<"2. Delete First Index                 "<<endl;
        cout<<"3. Cetak Index                        "<<endl;
        cout<<"4. Cetak Index dan Kontak             "<<endl;
        cout<<"5. Insert Kontak                      "<<endl;
        cout<<"6. Keluar                             "<<endl <<endl;
		cout<<"Silahkan Masukan Pilihan: "; cin>>pilih;
		switch(pilih)
        {
            case 1:
                createElmtIndex(d);
                insertLastIndex(First,d);
                cout<<endl<<"Index Baru Berhasil Ditambah."<<endl;
                break;
            case 2:
                deleteFirstIndex(First,d);
                cout<<endl<<"Index Terakhir Berhasil Dihapus."<<endl;
                break;
            case 3:
                traversalIndex(First);
                break;
            case 4:
                traversalIndexContact(First);
                break;
            case 5:
                cout<<"Silahkan Masukan Index\t: "; cin.ignore(); cin.getline(key, 10);
                createElmtData(p);
                insertLastIndex(First,d);
                cout<<endl<<"Kontak Baru Berhasil Ditambah."<<endl;
                break;
            case 6:
                cout<<"Terima Kasih Telah Menggunakan Program Ini" <<endl;
                return 0;
                break;
            default:
                cout<<"Maaf Pilihan Anda Tidak Tersedia" <<endl;
                break;
        }
        system("pause");
    } while(pilih!=6);
    return 0;
}
