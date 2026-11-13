#include <iostream>
#include "pesanan.hpp"
#include "antrean.hpp"
#include "rekap.hpp"
using namespace std;

int main() {
    int pilihan;
    int jumlah;
    DataPesanan hasil[500];   // dipakai untuk menu Simpan Rekap

    do {
        cout << "\n=== SISTEM ANTREAN KANTIN ===" << endl;
        cout << "1. Catat Pesanan" << endl;
        cout << "2. Tampilkan Antrean" << endl;
        cout << "3. Ubah Status" << endl;
        cout << "4. Simpan Rekap" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih(1-5): ";

        // Input pilihan (kalau yang diketik bukan angka, dianggap 0 = tidak valid)
        cin >> pilihan;
        if (cin.fail() || cin.peek() != '\n') { cin.clear(); pilihan = 0; }
        cin.ignore(1000, '\n');

        if (pilihan < 1 || pilihan > 5) {
            cout << "Inputan tidak valid" << endl;
        } else {
            switch (pilihan) {
                case 1: CatatPesanan(); break;
                case 2: TampilkanAntrean(); break;
                case 3: UbahStatus(); break;
                case 4:
                    // Simpan Rekap
                    jumlah = KumpulkanDataPesanan(hasil);
                    
                    if (jumlah == 0) {
                        cout << "Belum ada pesanan selesai untuk direkap" << endl;
                    } else {
                        bool berhasil = SimpanRekapKeFile(hasil, jumlah);
                        if (berhasil) {
                            cout << "Rekap sudah tersimpan" << endl;
                        } else {
                            cout << "File rekap gagal disimpan" << endl;
                        }
                    }
                    break;
                case 5:
                    cout << "HAVE A GOOD DAY!" << endl;
                    break;
            }
        } 
    } while (pilihan != 5);
    
    return 0;
}
