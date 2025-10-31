#include <iostream>
#include <string>
using namespace std;

struct Pasien {
    string nama;
    string jenis;
    int umur;
    int darurat;
    int urutan;
};

int main() {
    int n;
    cout << "Masukkan jumlah pasien: ";
    cin >> n;

    Pasien* antrean = new Pasien[n]; 

    for (int i = 0; i < n; i++) {
        cout << "\nPasien " << i + 1 << ":\n";
        cout << "Nama hewan: ";
        cin >> ws;
        getline(cin, antrean[i].nama);
        cout << "Jenis hewan: ";
        getline(cin, antrean[i].jenis);
        cout << "Umur: ";
        cin >> antrean[i].umur;
        cout << "Tingkat darurat (1-5): ";
        cin >> antrean[i].darurat;
        antrean[i].urutan = i;
    }

    cout << "\n=== Urutan Penanganan Pasien ===\n";

    for (int i = 0; i < n; i++) {
        int idxPrioritas = -1;
        for (int j = 0; j < n; j++) {
            if (antrean[j].darurat != -1) {
                if (idxPrioritas == -1 ||
                    antrean[j].darurat > antrean[idxPrioritas].darurat ||
                    (antrean[j].darurat == antrean[idxPrioritas].darurat &&
                     antrean[j].urutan < antrean[idxPrioritas].urutan)) {
                    idxPrioritas = j;
                }
            }
        }

        if (idxPrioritas != -1) {
            cout << antrean[idxPrioritas].nama
                 << " (" << antrean[idxPrioritas].umur << ")"
                 << " - Darurat " << antrean[idxPrioritas].darurat << endl;

            antrean[idxPrioritas].darurat = -1; 
        }
    }

    delete[] antrean;
    return 0;
}
