#include <iostream>

using namespace std;

struct mahasiswa
{
    string nama;
    int NIM;
    float IPK;

    mahasiswa *next;
};

mahasiswa *head, *tail, *nodesekarang, *nodebaru, *temp;

void tambah()
{
    nodebaru = new mahasiswa;
    cout << "Masukkan Nama : ";
    cin >> nodebaru->nama;
    cout << "Masukkan NIM : ";
    cin >> nodebaru->NIM;
    cout << "Masukkan IPK : ";
    cin >> nodebaru->IPK;
    nodebaru->next = NULL;
    if (head == NULL)
    {
        head = nodebaru;
    }
    else
    {
        mahasiswa *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = nodebaru;
    }
}

void tampil()
{
    mahasiswa *p;
    p = head;
    while (p != NULL)
    {
        cout << "nama : " << p->nama << "\t NIM : " << p->NIM << "\t IPK : " << p->IPK << endl;
        p = p->next;
    }
}

void urut()
{
    mahasiswa *p, *q, *r;
    p = head;
    while (p != NULL)
    {
        q = p->next;
        while (q != NULL)
        {
            if (p->IPK > q->IPK)
            {
                r = q;
                q = q->next;
                r->next = p;
                p = r;
            }
            else
            {
                break;
            }
        }
        p = q;
    }
}

int main()
{
    int pilih;
    cout << "=========================Menu========================" << endl;
    cout << "1. Tambah Mahasiswa" << endl;
    cout << "2. Tampilkan Mahasiswa" << endl;
    cout << "3. Urutkan Mahasiswa Berdasarkan NIM" << endl;
    cout << "4. Keluar" << endl;
    cout << "================================================================\n";
    cout << "Pilih menu :";
    cin >> pilih;
    if (pilih == 1)
    {

        tambah();
        system("pause");
        system("cls");
        return main();
    }
    else if (pilih == 2)
    {
        tampil();
        system("pause");
        system("cls");
        return main();
    }
    else if (pilih == 3)
    {
        urut();
        system("pause");
        system("cls");
        return main();
    }
    else if (pilih == 0)
    {
        return 0;
    }
}

// int main()
// {
//     int pilih;
//     do
//     {
//         Print();
//         cout << "=========================Menu========================" << endl;
//         cout << "1. Tambah Mahasiswa" << endl;
//         cout << "2. Tampilkan Mahasiswa" << endl;
//         cout << "3. Urutkan Mahasiswa Berdasarkan NIM" << endl;
//         cout << "4. Keluar" << endl;
//         cout << "Pilih menu";
//         cin >> pilih;
//         cout << "================================================================\n";
//         switch (pilih)
//         {
//         case 1:
//             tambah();
//             getch();
//             break;
//         case 2:
//             tampil();
//             getch();
//             break;
//         case 3:
//             urut();
//             getch();
//             break;
//         case 4:
//             exit(0);
//             getch();
//             break;
//         default:
//             cout << "Pilihan yang anda masukan salah" << endl;
//             break;
//         }
//         system("cls");
//     } while (pilih != 4);
// }