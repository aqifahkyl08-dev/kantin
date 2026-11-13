#include <iostream>
#include <fstream>
#include "rekap.hpp"
using namespace std;

// Mengumpulkan pesanan berstatus Selesai ke array hasil[]
// Hasilnya banyaknya pesanan yang terkumpul
int KumpulkanDataPesanan(DataPesanan hasil[]) {
    int jumlah = 0;

    for (int i = 0; i < jumlahPesanan; i++) {
        if (antreanPesanan[i].status == "Selesai") {
            hasil[jumlah] = antreanPesanan[i];
            jumlah++;
        }
    }
    return jumlah;
}

// Menulis rekap ke file. Hasilnya true kalau berhasil, false kalau gagal
bool SimpanRekapKeFile(DataPesanan hasil[], int jumlah) {
    // ios::app = mode tambah, isi lama tidak terhapus
    ofstream file("rekap_penjualan.txt", ios::app);

    // File berhasil dibuka?
    if (!file.is_open()) {
        return false;
    }

    int totalPendapatan = 0;

    file << "No | Nama | Menu | Total Harga" << endl;
    for (int i = 0; i < jumlah; i++) {
        file << hasil[i].nomorAntrean << " | "
             << hasil[i].namaPembeli << " | "
             << hasil[i].menu << " | Rp"
             << hasil[i].totalHarga << endl;
        totalPendapatan += hasil[i].totalHarga;
    }
    file << "Jumlah pesanan : " << jumlah << endl;
    file << "Total pendapatan : Rp" << totalPendapatan << endl;
    file << "------------------------------------------" << endl;

    file.close();

    // Penulisan berhasil?
    if (!file.fail()) {
        return true;
    } else {
        return false;
    }
}
