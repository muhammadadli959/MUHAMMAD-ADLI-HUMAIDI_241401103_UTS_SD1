#include <iostream>
#include <string>
using namespace std;

struct Film {
    string judul;
    int tahun;
    int rating;
    Film* next;
};

Film* head = nullptr;

void tambahBelakang(string judul, int tahun, int rating) {
    Film* baru = new Film{judul, tahun, rating, nullptr};
    if (head == nullptr) {
        head = baru;
    } else {
        Film* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void hapusFilm(string judul) {
    if (head == nullptr) {
        cout << "Daftar film kosong!\n";
        return;
    }

    Film* temp = head;
    Film* prev = nullptr;

    while (temp != nullptr && temp->judul != judul) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Film \"" << judul << "\" tidak ditemukan!\n";
        return;
    }

    if (prev == nullptr) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
}

void tampilkan() {
    Film* temp = head;
    int total = 0;

    while (temp != nullptr) {
        cout << temp->judul << " (" << temp->tahun << ") - " << temp->rating << endl;
        total++;
        temp = temp->next;
    }

    cout << "Total film tersisa: " << total << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah film awal: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string judul;
        int tahun, rating;

        cout << "\nFilm " << i + 1 << ":\n";
        cout << "Judul: ";
        getline(cin, judul);
        cout << "Tahun: ";
        cin >> tahun;
        cout << "Rating: ";
        cin >> rating;
        cin.ignore();

        tambahBelakang(judul, tahun, rating);
    }

    char hapus;
    cout << "\nApakah ingin menghapus film? (y/n): ";
    cin >> hapus;
    cin.ignore();

    if (hapus == 'y' || hapus == 'Y') {
        string target;
        cout << "Masukkan judul film yang sudah ditonton: ";
        getline(cin, target);
        hapusFilm(target);
    }

    cout << "\n=== Daftar Film Tersisa ===\n";
    tampilkan();

    return 0;
}
