#include <iostream>
using namespace std;

// Struct: data yang dibentuk oleh beberapa data
struct buah
{
    string nama;
    string warna;
    float berat;
    int harga;
    string rasa;
    // Pointer untuk menghubungkan node
    buah *next;
};

buah *head, *tail, *nodeSekarang, *nodeBaru, *temporaryNode;

void buatSingleLinkedList(string, string, float, int, string);
void masukkanNodeKeAwal(string, string, float, int, string);
void masukkanNodeKeAkhir(string, string, float, int, string);
void rubahDataNodePertama(string, string, float, int, string);
void rubahDataNodeTerakhir(string, string, float, int, string);
void hapusNodePertama();
void hapusNodeTerakhir();
void cetakSingleLinkedList();
void cetakSeluruhAtributNode();

// Fungsi Utama
int main()
{
    // Membuat node pertama kali
    cout << endl
         << "01. Membuat Node Pertama:" << endl;
    buatSingleLinkedList("Mangga", "Jingga", 1.1, 10000, "Manis");
    cetakSingleLinkedList(); // Menampilkan node
    cout << endl;
    cetakSeluruhAtributNode(); // Menampilkan node pert

    // Menambahkan node di awal
    cout << endl
         << "02. Menambahkan node pada posisi awal:" << endl;
    masukkanNodeKeAwal("Pisang", "Kuning", 1.3, 8000, "Manis");
    cetakSingleLinkedList(); // Menampilkan node
    cout << endl;
    cetakSeluruhAtributNode();

    // Menambahkan node di akhir
    cout << endl
         << "03. Menambahkan node pada posisi akhir:" << endl;
    masukkanNodeKeAkhir("Apel", "Merah", 2.1, 13000, "Manis");
    cetakSingleLinkedList(); // Menampilkan node

    // Menambahkan node di awal lagi
    cout << endl
         << "04. Menambahkan node pada posisi awal lagi:" << endl;
    masukkanNodeKeAwal("Anggur", "Ungu", 1, 9000, "Manis");
    cetakSingleLinkedList(); 

    cout << endl
         << "05. Menghapus node pada posisi awal:" << endl;
    hapusNodePertama();
    cetakSingleLinkedList();

    cout << endl
         << "06. Menghapus node pada posisi akhir:" << endl;
    hapusNodeTerakhir();
    cetakSingleLinkedList();

    cout << endl
         << "07. Menghapus node pada posisi akhir:" << endl;
    hapusNodeTerakhir();
    cetakSingleLinkedList();

    return 0;
}

// Fungsi Membuat Node Pertama
void buatSingleLinkedList(string nama, string warna, float berat, int harga, string rasa)
{
    // Membuat node pertama kali
    head = new buah();
    head->nama = nama;
    head->warna = warna;
    head->berat = berat;
    head->harga = harga;
    head->rasa = rasa;
    // Node tersebut akan jadi head dan tail
    head->next = NULL;
    tail = head;
}

// Fungsi Memasukkan Node di Awal
void masukkanNodeKeAwal(string nama, string warna, float berat, int harga, string rasa)
{
    // Buat node baru
    nodeBaru = new buah();
    nodeBaru->nama = nama;
    nodeBaru->warna = warna;
    nodeBaru->berat = berat;
    nodeBaru->harga = harga;
    nodeBaru->rasa = rasa;
    // Node baru di awal menunjuk ke head
    nodeBaru->next = head;
    // Head diubah menjadi node baru
    head = nodeBaru;
}

// Fungsi Memasukkan Node di Akhir
void masukkanNodeKeAkhir(string nama, string warna, float berat, int harga, string rasa)
{
    // Membuat node baru
    nodeBaru = new buah();
    nodeBaru->nama = nama;
    nodeBaru->warna = warna;
    nodeBaru->berat = berat;
    nodeBaru->harga = harga;
    nodeBaru->rasa = rasa;
    // Node di akhir harus menunjuk NULL
    nodeBaru->next = NULL;
    // Node yang sebelumnya tail harus menunjuk ke node baru
    tail->next = nodeBaru;
    // Sekarang tail adalah node baru
    tail = nodeBaru;
}

// Fungsi Rubah Data Node Pertama
void rubahDataNodePertama(string nama, string warna, float berat, int harga, string rasa)
{
    head->nama = nama;
    head->warna = warna;
    head->berat = berat;
    head->harga = harga;
    head->rasa = rasa;
}

// Fungsi Rubah Data Node Terakhir
void rubahDataNodeTerakhir(string nama, string warna, float berat, int harga, string rasa)
{
    // Ubah data node terakhir
    tail->nama = nama;
    tail->warna = warna;
    tail->berat = berat;
    tail->harga = harga;
    tail->rasa = rasa;
}

// Fungsi Hapus Node Pertama
void hapusNodePertama()
{
    // Simpan node head ke node sementara
    temporaryNode = head;
    // Node head diganti dengan node selanjutnya
    head = head->next;
    delete temporaryNode;
}

// Fungsi Hapus Node Terakhir
void hapusNodeTerakhir()
{
    // Simpan node tail ke node sementara
    temporaryNode = tail;
    // Mencari node tail
    // Pencarian dimulai dari head
    nodeSekarang = head;
    while (nodeSekarang->next != NULL)
    {
        // Jika node sekarang next-nya adalah tail
        if (nodeSekarang->next == tail)
        {
            // Node sekarang jadi tail
            // Dengan membuat next dari node sekarang menjadi NULL bukan ke node lain
            nodeSekarang->next = NULL;
            // Maka tail diubah menjadi node sekarang
            tail = nodeSekarang;
        }
        else
        {
            // Jika tidak, node sekarang diganti dengan node selanjutnya
            nodeSekarang = nodeSekarang->next;
        }
    }
    delete temporaryNode;
}

// Fungsi Cetak Linked List
void cetakSingleLinkedList()
{
    // Dimulai dari node head
    nodeSekarang = head;
    while (nodeSekarang != NULL)
    {
        cout << nodeSekarang->nama << " >> ";
        // Geser ke node selanjutnya
        nodeSekarang = nodeSekarang->next;
    }
    cout << "!!n";
}

// Fungsi Cetak Seluruh Data Node Linked List
void cetakSeluruhAtributNode()
{
    // Dimulai dari node head
    nodeSekarang = head;
    while (nodeSekarang != NULL)
    {
        cout << "nama: " << nodeSekarang->nama << endl;
        cout << "warna: " << nodeSekarang->warna << endl;
        cout << "berat: " << nodeSekarang->berat << endl;
        cout << "harga: " << nodeSekarang->harga << endl;
        cout << "rasa: " << nodeSekarang->rasa << endl;
        cout << endl;
        nodeSekarang = nodeSekarang->next;
    }
}
