#include <iostream>
using namespace std;

// Maksimum jumlah elemen dalam array
const int MAX_SIZE = 100;

// Struct untuk elemen buah
struct Buah
{
    string nama;
    string warna;
    float berat;
    int harga;
    string rasa;
};

// Array untuk menyimpan elemen-elemen buah
Buah buahArray[MAX_SIZE];

// Jumlah elemen saat ini dalam array
int jumlahElemen = 0;

// Fungsi untuk menambahkan buah ke array
void tambahBuah(string nama, string warna, float berat, int harga, string rasa)
{
    if (jumlahElemen < MAX_SIZE)
    {
        buahArray[jumlahElemen].nama = nama;
        buahArray[jumlahElemen].warna = warna;
        buahArray[jumlahElemen].berat = berat;
        buahArray[jumlahElemen].harga = harga;
        buahArray[jumlahElemen].rasa = rasa;
        jumlahElemen++;
    }
    else
    {
        cout << "Array penuh, tidak dapat menambahkan lebih banyak elemen." << endl;
    }
}

// Fungsi untuk mencetak seluruh data buah dalam array
void cetakSeluruhBuah()
{
    for (int i = 0; i < jumlahElemen; i++)
    {
        cout << "Nama: " << buahArray[i].nama << endl;
        cout << "Warna: " << buahArray[i].warna << endl;
        cout << "Berat: " << buahArray[i].berat << " kg" << endl;
        cout << "Harga: Rp " << buahArray[i].harga << endl;
        cout << "Rasa: " << buahArray[i].rasa << endl;
        cout << endl;
    }
}

int main()
{
    /* Menambahkan beberapa buah ke dalam array */
    tambahBuah("Mangga", "Jingga", 1.1, 10000, "Manis");
    tambahBuah("Pisang", "Kuning", 1.3, 8000, "Manis");
    tambahBuah("Apel", "Merah", 2.1, 13000, "Manis");
    tambahBuah("Anggur", "Ungu", 1, 9000, "Manis");

    /* Menampilkan seluruh data buah dalam array */
    cetakSeluruhBuah();

    return 0;
}
