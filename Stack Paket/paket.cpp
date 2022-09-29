/******************************************************************************
               NAMA     : RIZKY SYAH GUMELAR
               NIM      : A11.2021.13304
               KELOMPOK : A11.43UG1
*******************************************************************************/

#include<iostream>
#include<conio.h>
#include<windows.h>
#include<iomanip>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


using namespace std;
struct paket
{
    char jenis_brg[30];
    int berat;
    char kota[30];
};

struct paket kirim[100];
int datake = 0;
int maxx   = 4;

void bersihlayar()
{
    for(int a=0;a<96;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}

bool isfull()
{
    if(datake>=maxx)
        return true;
    else
        return false;
}

bool isempty()
{
    if(datake==0)
        return true;
    else
        return false;
}

void tambahdata(int x)
{
    gotoxy(46,4);cout<<"Inputkan Jenis Barang   : ";
    cin>>kirim[x].jenis_brg;
    gotoxy(46,5);cout<<"Inputkan Berat          : ";
    cin>>kirim[x].berat;
    gotoxy(46,6);cout<<"Inputkan Kota Tujuan    : ";
    cin>>kirim[x].kota;
}

void tampildata(int x)
{
    gotoxy(46,1);cout<<"Daftar Kiriman Paket"<<endl;
    gotoxy(46,2);cout << "==================================================\n";
    gotoxy(46,3);cout << "| No | Jenis Barang | Berat Barang | Kota Tujuan |\n";
    gotoxy(46,4);cout << "==================================================\n";
    int i = 5;
    for(x; x>0; x--)
    {
        gotoxy(46,i);
        cout << "| " << setiosflags(ios::right) << setw(2) << x << " | ";
        cout << setiosflags(ios::right) << setw(12) << kirim[x-1].jenis_brg << " | ";
        cout << setiosflags(ios::right) << setw(9) << kirim[x-1].berat << " kg" << " | ";
        cout << setiosflags(ios::right) << setw(11) << kirim[x-1].kota << " | ";
        gotoxy(46,i+1);cout << "--------------------------------------------------\n";
        i = i+2;
    }
    gotoxy(46,i+2);
    cout<<"Press Any Key...";
    getch();
    /*harus Ijin --> #include<conio.h>*/
}

void hapusdata(int x)
{
    gotoxy(46,1);cout<<"Data Terakhir yang anda Hapus Adalah :"<<endl;
    gotoxy(46,2);cout << "==================================================\n";
    gotoxy(46,3);cout << "| No | Jenis Barang | Berat Barang | Kota Tujuan |\n";
    gotoxy(46,4);cout << "==================================================\n";
    gotoxy(46,5);
    cout << "| " << setiosflags(ios::right) << setw(2) << x+1 << " | ";
    cout << setiosflags(ios::right) << setw(12) << kirim[x].jenis_brg << " | ";
    cout << setiosflags(ios::right) << setw(9) << kirim[x].berat << " kg" << " | ";
    cout << setiosflags(ios::right) << setw(11) << kirim[x].kota << " | ";
    gotoxy(46,6);cout << "--------------------------------------------------\n";

    gotoxy(46,16);cout<<"Press Any Key...";
    getch();


}

int main()
{
    int pilih;
    do
    {
        bersihlayar();
        gotoxy(1,1); cout << "=========================================\n";
        gotoxy(1,2); cout << "|>>>>>>> PROGRAM STACK PAKET C++ <<<<<<<|\n";
        gotoxy(1,3); cout << "-----------------------------------------\n";
        gotoxy(1,4); cout << "|        1. PUSH                        |\n";
        gotoxy(1,5); cout << "|        2. POP                         |\n";
        gotoxy(1,6); cout << "|        3. TAMPILKAN STACK             |\n";
        gotoxy(1,7); cout << "|        4. CEK FULL                    |\n";
        gotoxy(1,8); cout << "|        5. CEK KOSONG                  |\n";
        gotoxy(1,9);cout <<  "|        6. UKURAN STACK                |\n";
        gotoxy(1,10);cout << "|        7. SELESAI                     |\n";
        gotoxy(1,11);cout << "=========================================\n";
        //gotoxy(1,12);cout << datake;

        gotoxy(1,13);cout<<"Pilihan Anda [1-8] : ";
        cin>>pilih;

        if(pilih==1){ /*Menambah data baru diletakan di DATAKE*/
                if(isfull()){
                    gotoxy(46,14);cout << "Stack Penuh!!";
                    gotoxy(46,16);cout<<"Press Any Key...";
                    getch();
                }else{
                    tambahdata(datake);
                    datake++;
                }
            }
        if(pilih==2){ /*Menghapus Data Terakhir (DATAKE-1*/
                if(datake>0){
                    hapusdata(datake-1);
                    datake--;
                }else{
                    gotoxy(46,14);cout << "Data Kosong!!";
                    gotoxy(46,16);cout<<"Press Any Key...";
                    getch();
                }
            }
        if(pilih==3){
             /*Menampilkan Data mulai
                        data ke-1 hingga DATAKE*/
            tampildata(datake);
        }
        if(pilih==4){
            if(isfull()){
                gotoxy(46,14);cout << "Stack Penuh!!";
                gotoxy(46,16);cout<<"Press Any Key...";
                getch();
            }else{
                gotoxy(46,14);cout << "Stack Belum Penuh, Masih Bisa Push!!";
                gotoxy(46,16);cout<<"Press Any Key...";
                getch();
            }
        }
        if(pilih==5){
            if(isempty()){
                gotoxy(46,14);cout << "Stack Kosong!!";
                gotoxy(46,16);cout<<"Press Any Key...";
                getch();
            }else{
                gotoxy(46,14);cout << "Stack Tidak Kosong, Masih Bisa Pop!!";
                gotoxy(46,16);cout<<"Press Any Key...";
                getch();
            }
        }
        if(pilih==6){
                gotoxy(46,14);cout << "Ukuran Stack Adalah : " << datake;
                gotoxy(46,16);cout<<"Press Any Key...";
                getch();
        }

    }
    while(pilih!=7);
    return 0;
}
