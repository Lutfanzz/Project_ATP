#include <iostream>
using namespace std;

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

int main(){


return 0;
}
