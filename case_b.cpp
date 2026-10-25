#include <iostream>
using namespace std;

//memakai struct
struct Pelanggan {
    string nama;
    string kategori; // "Low-income", "Middle-income", "High-income"
    double pemakaianHarian[7];
    double totalPemakaian;
    double estimasiBulanan;
    double tagihanAkhir;
};

//deklarasi fungsi
void tambahPelanggan(Pelanggan data[], int &jumlah);
double hitungTotal7Hari(double harian[]);
double hitungTagihanProgresif(double estimasiBulanan);
double hitungDiskon(double tagihanAwal, string kategori);
int cariHariTertinggi(double harian[]);
void tampilkanLaporan(Pelanggan data[], int jumlah);

// Batas maksimal pelanggan
const int MAX_PELANGGAN = 20;

// Menghitung total penggunaan listrik selama 7 hari
int totalListrik(int hari[]) {
    int total = 0;

    for (int i = 0; i < 7; i++) {
        total += hari[i];
    }

    return total;
}

// Menghitung rata-rata penggunaan listrik selama 7 hari
float averageListrik(int total) {
    return total / 7.0;
}

// Menghitung estimasi penggunaan listrik bulanan
float listrikBulanan(int hari[]) {
    return averageListrik(totalListrik(hari)) * 30;
}

// Menghitung tarif progresif
float progresifTarif(int hari[]) {
    float bulanan = listrikBulanan(hari);

    if (bulanan <= 100) {
        return bulanan * 1000;
    } 
    else if (bulanan <= 200) {
        return (100 * 1000) + ((bulanan - 100) * 1500);
    } 
    else {
        return (100 * 1000) + (100 * 1500)
             + ((bulanan - 200) * 2000);
    }
}

// Menghitung diskon pelanggan
float diskonPelanggan(float biaya, int kategori) {
    if (kategori == 1) {
        return biaya * 0.20;
    } 
    else if (kategori == 2) {
        return biaya * 0.10;
    } 
    else {
        return 0;
    }
}

//Menghitung Final Bills
float finalBill(float biaya, float diskon) {
    return biaya - diskon;
}

//fungsi main
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

//bagian 2 
//fungsi input data pelanggan

void tambahPelanggan(Pelanggandata[], int &jumlah){
    cout << "INPUT DATA PELANGGAN BARU \n";
    cin.ignore();

    cout << "Nama Pelanggan: ";
    cin >> data[jumlah].nama;

    bool kategoriValid = false;
    while(!kategoriValid){
        cout << "Kategori (low/mid/high): ";
        cin >> data[jumlah].kategori;
        if(data[jumlah].kategori == "low" || data[jumlah].kategori == "mid" || data[jumlah].kategori == "high"){
            kategoriValid = true;
        }else{
            cout << "Kategori tidak valid! Masukkan low/mid/high \n";
        }
    }

    cout << "Masukkan pemakaian listrik harian (kWh) selama 7 hari: \n";
    for(int i = 0; i < 7; i++){
        cout << "Hari ke-" << (i+1) << ": ";
        cin >> data[jumlah].pemakaianHarian[i];
    }

    //pemanggilan fungsi hitung
    data[jumlah].totalPemakaian = hitungTotal7Hari(data[jumlah].pemakaianHarian);
    double rataRata = data[jumlah].totalPemakaian / 7.0;
    data[jumlah].estimasiBulanan = rataRata * 30.0;
    double tagihanAwal = hitungTagihanProgresif(data[jumlah].estimasiBulanan);
    data[jumlah].tagihanAkhir = hitungDiskon(tagihanAwal, data[jumlah].kategori);
    
    jumlah++;
    cout << "Data berhasil ditambahkan!n";
}


//fungsi mencari hari tertinggi
int cariHariTertinggi(double harian[]){
    int indeksMaks = 0;
    for(int i = 1; i < 7; i++){
        if(harian[i] > harian[indeksMaks]){
            indeksMaks = i;
        }
    }

    return indeksMaks + 1;
}
