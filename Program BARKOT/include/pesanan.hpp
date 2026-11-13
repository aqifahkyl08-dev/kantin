#ifndef PESANAN_HPP
#define PESANAN_HPP
#include <string>
using namespace std;

// Struct Menu: menyimpan nama dan harga makanan
struct Menu {
    string nama;
    int harga;
};

// Struct DataPesanan: menyimpan satu pesanan pembeli
// (banyak menu digabung jadi satu teks di "menu", "jumlah" = total porsi)
struct DataPesanan {
    int nomorAntrean;
    string namaPembeli;
    string menu;
    int jumlah;
    int totalHarga;
    string status;
};

// Array + penghitung (dipakai bersama oleh semua file)
extern Menu daftarMenu[30];
extern DataPesanan antreanPesanan[500];
extern int jumlahPesanan;   // awalnya 0

void CatatPesanan();

#endif
