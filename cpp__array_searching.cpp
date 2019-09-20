#include<iostream>

using namespace std;

void BinSearch(int Data[], int n, int x, int *idx);
void SeqSearch(int Data[], int n, int x, int *idx);

main(){

    int 
        n,
        x,
        idx,
        i,
        pilih
    ;

    char
        pilihan
    ;

    menu:
    system("cls");

    cout<<"Pilih Menu : \n";
    cout<<"1. Squential Serching \n";
    cout<<"2. Binnary Searching \n";
    cout<<"3. exit \n"; cout<<endl;

    cout<<"Pilih : "; cin>>pilih;

    if(pilih == 1){
        cout<<"1. Squential Serching \n"; cout<<endl;

        cout<<"Masukan jumlah nilai : "; cin>>n;

        int Data[n];
        for(i=0;i<n;i++){
             cout<<"Masukan nilai "<<i+1<<": "; cin>>Data[i];
        }
        cout<<endl;
        
        cout<<"Nilai Array : \n"; 
        for(i=0;i<n;i++){
            cout<<Data[i]<<" ";
        }
        cout<<endl;

        cout<<"Masukan data yang akan dicari ?:";cin>>x;
        SeqSearch(Data,n,x,&idx);
        if(idx!=-1){
            cout<<"Data yang dicari berada pada indeks : "<<idx<<endl;
        }
        else{
            cout<<"Data yang dicari tidak ada dalam array"<<endl;
        }
    }else if(pilih == 2) {
        cout<<"2. Binnary Searching \n"; cout<<endl;

        cout<<"Masukan jumlah nilai : "; cin>>n;

        int Data[n];
        for(i=0;i<n;i++){
             cout<<"Masukan nilai "<<i+1<<": "; cin>>Data[i];
        }
        cout<<endl;
        
        cout<<"Nilai Array : \n"; 
        for(i=0;i<n;i++){
            cout<<Data[i]<<" ";
        }
        cout<<endl;

        cout<<"Masukan data yang akan dicari ?:";cin>>x;
        BinSearch(Data,n,x,&idx);
        if(idx!=-1){
            cout<<"Data yang dicari berada pada indeks : "<<idx<<endl;
        }
        else{
            cout<<"Data yang dicari tidak ada dalam array"<<endl;
        }
    }else if(pilih == 3){
        exit(0);
    }else{
        cout<<"tidak ada \n";
        cout<<"Apakah ingin kembali ke menu: [Y/T] \n"; cin>>pilihan;

        if(pilihan == 'Y') {
            goto menu;
        }else{
            exit(0);
        }
    }
}

void SeqSearch(int Data[],int n,int x, int *idx)
{
    int i=0;

    while(i<n-1 && Data[i]<x)i++;
    
    if(Data[i]==x){
        *idx=i;
    }else{
        *idx=-1;
    }
}

void BinSearch(int Data[],int n,int x, int *idx){
    bool 
        ketemu = false
    ;
    int 
        top = n-1,
        bottom = 0,
        mid
    ;

    while(bottom<=top && !ketemu)
    {
        mid=(top+bottom)/2;
        if(Data[mid]==x){
            ketemu=true;
        }else if(Data[mid]<x){
            top=mid-1;
        }else{
            bottom=mid+1;
        }
    }
    if(ketemu){
        *idx=mid;
    }else{
         *idx=-1;
    }
}