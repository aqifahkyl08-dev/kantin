#include <iostream>
#include <iomanip>
#include "antrean.hpp"
using namespace std;

void TampilkanAntrean() {
    // Belum ada pesanan, atau semua pesanan sudah Selesai
    if (jumlahPesanan == 0 || AmbilPesananTerlama() == -1) {
        cout << "Belum ada pesanan" << endl;
        return;
    }

    // Judul kolom (setw = lebar kolom, left = rata kiri, supaya rapi)
    cout << "\n====== DAFTAR ANTREAN ======" << endl;
    cout << left;
    cout << setw(12) << "Nomor Antrean" << " | "
         << setw(10) << "Nama" << " | "
         << setw(38) << "Menu" << " | "
         << setw(6) << "Jumlah" << " | "
         << setw(11) << "Total Harga" << " | "
         << "Status" << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;

    // Tampilkan semua pesanan yang belum Selesai
    for (int i = 0; i < jumlahPesanan; i++) {
        if (antreanPesanan[i].status != "Selesai") {
            cout << setw(13) << antreanPesanan[i].nomorAntrean << " | "
                 << setw(10) << antreanPesanan[i].namaPembeli << " | "
                 << setw(38) << antreanPesanan[i].menu << " | "
                 << setw(6) << antreanPesanan[i].jumlah << " | Rp"
                 << setw(11) << antreanPesanan[i].totalHarga << " | "
                 << antreanPesanan[i].status << endl;
        }
    }
}

// Mencari pesanan paling awal yang belum Selesai (FIFO)
// Hasilnya nomor posisi di array, atau -1 kalau tidak ada
int AmbilPesananTerlama() {
    for (int i = 0; i < jumlahPesanan; i++) {
        if (antreanPesanan[i].status != "Selesai") {
            return i;
        }
    }
    return -1;
}

void UbahStatus() {
    int indeks = AmbilPesananTerlama();

    // Semua pesanan sudah selesai?
    if (indeks == -1) {
        cout << "Tidak ada pesanan yang perlu diproses" << endl;
        return;
    }

    // Status naik 1 tahap: Diproses -> Siap Diambil -> Selesai
    // (pakai "else if" supaya naiknya hanya 1 tahap)
    if (antreanPesanan[indeks].status == "Diproses") {
        antreanPesanan[indeks].status = "Siap Diambil";
    } else if (antreanPesanan[indeks].status == "Siap Diambil") {
        antreanPesanan[indeks].status = "Selesai";
    }

    // Status sekarang Siap Diambil?
    if (antreanPesanan[indeks].status == "Siap Diambil") {
        cout << "\nNomor antrean " << antreanPesanan[indeks].nomorAntrean
             << " atas nama " << antreanPesanan[indeks].namaPembeli
             << ": Pesanan Siap Diambil" << endl;
    } else {
        cout << "\nNomor antrean " << antreanPesanan[indeks].nomorAntrean
             << " atas nama " << antreanPesanan[indeks].namaPembeli
             << ": Pesanan Selesai" << endl;
    }

    // Sistem otomatis menampilkan antrean terbaru
    cout << endl;
    TampilkanAntrean();
}
