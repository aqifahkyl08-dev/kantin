#include <iostream>
#include "pesanan.hpp"
using namespace std;

// ===================== DEKLARASI DATA =====================
Menu daftarMenu[30] = {
    {"Mie Telur", 13000},
    {"Rice Bowl Ayam Suwir", 15000},
    {"Nasi Kuning", 15000},
    {"Nasi Goreng", 20000},
    {"Soto Ayam", 20000},
    {"Ayam Geprek", 15000},
    {"Ayam Goreng", 12000},
    {"Nasi", 10000},
    {"Ayam Bakar", 12000},
    {"Gado-gado", 20000},
    {"Bakso", 20000},
    {"Mie Ayam", 20000},
    {"Pisang Goreng", 2000},
    {"Risol", 3000},
    {"Bakwan", 1000},
    {"Mochi", 15000},
    {"Donat", 3000},
    {"Basreng", 10000},
    {"Puding Coklat", 5000},
    {"Salad Buah", 10000},
    {"Air Mineral", 5000},
    {"Es Teh Manis", 10000},
    {"Es Jeruk", 12000},
    {"Es Kelapa Muda", 15000},
    {"Jus Alpukat", 20000},
    {"Teh Hangat", 5000},
    {"Matcha", 20000},
    {"Cappucino", 15000},
    {"Thai Tea", 13000},
    {"Es Milo", 10000}
};

DataPesanan antreanPesanan[500];
int jumlahPesanan = 0;

// ===================== FUNGSI =====================

void CatatPesanan() {
    string namaPembeli, daftarPesan, jawab;
    int pilihan, jumlah;
    int jumlahTotal = 0, totalHarga = 0;
    bool valid, jawabanValid;

    do {
        cout << "Nama pembeli: ";
        getline(cin, namaPembeli);

        // Buang spasi/tab di depan nama, jadi kalau isinya cuma spasi/tab, nama jadi kosong
        namaPembeli.erase(0, namaPembeli.find_first_not_of(" \t"));

        // Validasi: nama tidak boleh kosong
        if (namaPembeli.empty()) {
            cout << "Nama tidak valid! Silahkan isi ulang" << endl;
        }
    } while (namaPembeli.empty());
    
    // 2. Pilih menu dan jumlah (diulang selama pembeli menjawab y)
    do {
        // Diulang selama menu atau jumlah tidak valid
        do {
            // Tampilkan daftarMenu[]
            cout << "\nDaftar Menu:" << endl;
            for (int i = 0; i < 30 && daftarMenu[i].nama != ""; i++) {
                cout << i + 1 << ". " << daftarMenu[i].nama
                     << " - Rp" << daftarMenu[i].harga << endl;
            }
            // Input pilihan menu dan jumlah (kalau yang diketik bukan angka, dianggap 0 = tidak valid)
            cout << "Pilih menu: ";
            cin >> pilihan;
            if (cin.fail() || cin.peek() != '\n') { cin.clear(); pilihan = 0; }
            cin.ignore(1000, '\n');

            cout << "Jumlah: ";
            cin >> jumlah;
            if (cin.fail() || cin.peek() != '\n') { cin.clear(); jumlah = 0; }
            cin.ignore(1000, '\n');
            
            if (pilihan < 1 || pilihan > 30 || daftarMenu[pilihan - 1].nama == "" || jumlah <= 0) {
                valid = false;
                cout << "Menu atau jumlah tidak valid! Silahkan isi ulang" << endl;
            } else {
                valid = true;
            }
        } while (valid == false);

        // Tambahkan menu ke pesanan
        if (daftarPesan != "") {
            daftarPesan += ", ";
        }
        
        daftarPesan += daftarMenu[pilihan - 1].nama + " x" + to_string(jumlah);
        jumlahTotal += jumlah;
        totalHarga += daftarMenu[pilihan - 1].harga * jumlah;

        // Tambah menu lagi? (diulang sampai jawabannya y/Y/n/N)
        do {
            cout << "Tambah menu lagi (y/n)? : ";
            getline(cin, jawab);

            if (jawab == "y" || jawab == "Y" || jawab == "n" || jawab == "N") {
                jawabanValid = true;
            } else {
                jawabanValid = false;
                cout << "Jawaban tidak valid! Ketik y atau n" << endl;
            }
        } while (jawabanValid == false);

    } while (jawab == "y" || jawab == "Y");

    // 3. Isi DataPesanan
    DataPesanan pesanan;
    pesanan.nomorAntrean = jumlahPesanan + 1;
    pesanan.namaPembeli = namaPembeli;
    pesanan.menu = daftarPesan;
    pesanan.jumlah = jumlahTotal;
    pesanan.totalHarga = totalHarga;
    pesanan.status = "Diproses";

    // Simpan ke antrean
    antreanPesanan[jumlahPesanan] = pesanan;
    jumlahPesanan++;

    // Tampilkan nomor antrean dan total harga
    cout << "\nNomor antrean : " << pesanan.nomorAntrean << endl;
    cout << "Total harga   : Rp" << pesanan.totalHarga << endl;
}
