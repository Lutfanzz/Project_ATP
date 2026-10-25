//A'dhomu Ni'amillah
//==================
#include <iostream>
#include <string>

using namespace std;
// 1. DEFINISI STRUKTUR DATA (STRUCT)
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

// 2. DEKLARASI FUNGSI (PROTOTYPE)
void tambahPelanggan(Pelanggan data[], int &jumlah);
double hitungTotal7Hari(double harian[]);
double hitungTagihanProgresif(double estimasiBulanan);
double hitungDiskon(double tagihanAwal, string kategori);
int cariHariTertinggi(double harian[]);
void tampilkanLaporan(Pelanggan data[], int jumlah);

// 3. FUNGSI MAIN (PROGRAM UTAMA)
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


// Fungsi untuk menginput data pelanggan baru
void tambahPelanggan(Pelanggan data[], int &jumlah) {
    cout << "INPUT DATA PELANGGAN BARU\n";
    cin.ignore(); // Membersihkan buffer enter dari input sebelumnya
    cout << "Nama Pelanggan: ";
    getline(cin, data[jumlah].nama);

    bool kategoriValid = false;
    while (!kategoriValid) {
        cout << "Kategori (low/mid/high): ";
        cin >> data[jumlah].kategori;
        if (data[jumlah].kategori == "low" || data[jumlah].kategori == "mid" || data[jumlah].kategori == "high") {
            kategoriValid = true;
        } else {
            cout << "Kategori tidak valid! Masukkan 'low', 'mid', atau 'high'.\n";
        }
    }

    cout << "Masukkan pemakaian listrik harian (kWh) selama 7 hari:\n";
    for (int i = 0; i < 7; i++) {
        cout << "Hari ke-" << (i + 1) << ": ";
        cin >> data[jumlah].pemakaianHarian[i];
    }

    // Hitung total dan estimasi saat input selesai
    data[jumlah].totalPemakaian = hitungTotal7Hari(data[jumlah].pemakaianHarian);
    
    // Rata-rata harian * 30 hari
    double rataRata = data[jumlah].totalPemakaian / 7.0;
    data[jumlah].estimasiBulanan = rataRata * 30.0;

    // Hitung tagihan
    double tagihanAwal = hitungTagihanProgresif(data[jumlah].estimasiBulanan);
    data[jumlah].tagihanAkhir = hitungDiskon(tagihanAwal, data[jumlah].kategori);

    jumlah++;
    cout << "Data berhasil ditambahkan!\n";
}

// Fungsi menghitung total pemakaian 7 hari
double hitungTotal7Hari(double harian[]) {
    double total = 0;
    for (int i = 0; i < 7; i++) {
        total += harian[i];
    }
    return total;
}

// Fungsi menghitung tarif progresif
double hitungTagihanProgresif(double estimasiBulanan) {
    double tagihan = 0;
    double sisa = estimasiBulanan;
    if (sisa > 200) {
        tagihan += (sisa - 200) * 2000;
        sisa = 200; 
    }
    if (sisa > 100) {
        tagihan += (sisa - 100) * 1500;
        sisa = 100; 
    }
    
    if (sisa > 0) {
        tagihan += sisa * 1000;
    }

    return tagihan;
}

// Fungsi menghitung diskon berdasarkan kategori
double hitungDiskon(double tagihanAwal, string kategori) {
    double diskonPersen = 0;

    if (kategori == "low") {
        diskonPersen = 0.20; 
    } else if (kategori == "mid") {
        diskonPersen = 0.10; 
    } else if (kategori == "high") {
        diskonPersen = 0.00; 
    }

    double nominalDiskon = tagihanAwal * diskonPersen;
    return tagihanAwal - nominalDiskon;
}

// Fungsi mencari hari dengan pemakaian tertinggi
int cariHariTertinggi(double harian[]) {
    int indeksMaks = 0; // Asumsi awal hari ke-1 (indeks 0) adalah yang tertinggi
    for (int i = 1; i < 7; i++) {
        if (harian[i] > harian[indeksMaks]) {
            indeksMaks = i;
        }
    }
    return indeksMaks + 1; // Kembalikan 1-7 (karena indeks array 0-6)
}

// Fungsi menampilkan laporan
void tampilkanLaporan(Pelanggan data[], int jumlah) {
    if (jumlah == 0) {
        cout << "\nBelum ada data pelanggan yang dimasukkan.\n";
        return;
    }

    cout << "\n========== LAPORAN TAGIHAN LISTRIK ==========\n";

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData pelanggan ke-" << (i + 1) << endl;
        cout << "Nama            : " << data[i].nama << endl;
        cout << "Kategori        : " << data[i].kategori << endl;
        cout << "Total 7 hari    : " << data[i].totalPemakaian << " kWh" << endl;
        cout << "Estimasi bulan  : " << data[i].estimasiBulanan << " kWh" << endl;
        cout << "Hari tertinggi  : Hari ke-"
             << cariHariTertinggi(data[i].pemakaianHarian) << endl;
        cout << "Tagihan akhir   : Rp " << data[i].tagihanAkhir << endl;
        cout << "----------------------------------------\n";
    }
}
