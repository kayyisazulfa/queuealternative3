#include "queue3.h"

int main(){
    Queue Q;
    createQueue(Q);
    for(int i = 1; i <= 5; i++){
        cout << "Masukkan data paket " << i << endl;
        infotype P;
        cout << "Kode paket : ";
        cin >> P.kode_paket;
        cout << "Asal : ";
        cin >> P.asal;
        cout << "Tujuan : ";
        cin >> P.tujuan;
        enqueue(Q,P);
    }
    cout << endl;
    cout << "DAFTAR PAKET AWAL" << endl;
    print(Q);
    cout << endl;
    infotype P;
    dequeue(Q,P);
    cout << "DAFTAR PAKET SETELAH PENGHAPUSAN" << endl;
    print(Q);
    cout << endl;
    cout << "Masukkan data paket baru" << endl;
    cout << "Kode paket : ";
    cin >> P.kode_paket;
    cout << "Asal : ";
    cin >> P.asal;
    cout << "Tujuan : ";
    cin >> P.tujuan;
    enqueue(Q, P);
    cout << endl;
    cout << "DAFTAR PAKET AKHIR" << endl;
    print(Q);
}

