//A'dhomu Ni'amillah
//==================
#include <iostream>
#include <string>
#include <iomanip> // Untuk merapikan output (setw)

using namespace std;

// ==========================================
// 1. DEFINISI STRUKTUR DATA (STRUCT)
// ==========================================
struct Pelanggan {
    string nama;
    string kategori; // "Low-income", "Middle-income", "High-income"
    double pemakaianHarian[7];
    double totalPemakaian;
    double estimasiBulanan;
    double tagihanAkhir;
};

// Batas maksimal pelanggan
const int MAX_PELANGGAN = 20;

// ==========================================
// 2. DEKLARASI FUNGSI (PROTOTYPE)
// ==========================================
void tambahPelanggan(Pelanggan data[], int &jumlah);
double hitungTotal7Hari(double harian[]);
double hitungTagihanProgresif(double estimasiBulanan);
double hitungDiskon(double tagihanAwal, string kategori);
int cariHariTertinggi(double harian[]);
void tampilkanLaporan(Pelanggan data[], int jumlah);

// ==========================================
// 3. FUNGSI MAIN (PROGRAM UTAMA)
// ==========================================
int main() {
    Pelanggan dataPelanggan[MAX_PELANGGAN];
    int jumlahPelanggan = 0;
    int pilihan;

    do {
        cout << "\n===================================\n";
        cout << "   SISTEM TAGIHAN LISTRIK RUMAH    \n";
        cout << "===================================\n";
        cout << "1. Tambah Data Pelanggan\n";
        cout << "2. Tampilkan Laporan Tagihan\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu (1-3): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (jumlahPelanggan < MAX_PELANGGAN) {
                    tambahPelanggan(dataPelanggan, jumlahPelanggan);
                } else {
                    cout << "Maaf, kapasitas maksimal 20 rumah tangga sudah penuh!\n";
                }
                break;
            case 2:
                tampilkanLaporan(dataPelanggan, jumlahPelanggan);
                break;
            case 3:
                cout << "Terima kasih telah menggunakan program ini.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 3);

    return 0;
}
