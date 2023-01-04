#include "queue3.h"

bool isEmpty(Queue Q){
    return(Q.membQueue==0);
}
bool arrFull(Queue Q){
    return(Q.membArray==MAX);
}
bool queFull(Queue Q){
    return(Q.membQueue==MAX);
}
void createQueue(Queue &Q){
    Q.Head = -1;
    Q.Tail = -1;
    Q.membQueue = 0;
    Q.membArray = 0;
}
void enqueue(Queue &Q, infotype P){
    if (queFull(Q)){
        cout << "Queue penuh" << endl;
    }else if (isEmpty(Q)){
        Q.Head = 0;
        Q.Tail = 0;
        Q.membQueue = 1;
        Q.membArray = 1;
        Q.T[Q.Tail] = P;
        Q.M[0] = 0;
    }else if (Q.Head != 0 && arrFull(Q) && !queFull(Q)){
        int i = 0;
        bool dipakai = false;
        while(i<Q.Head && !dipakai){
            int j = 0;
            while(!dipakai && j < MAX){
                dipakai = Q.M[j] == i;
                j += 1;
            }
            i += 1;
        }
        Q.Tail = i-1;
        Q.T[Q.Tail] = P;
        Q.M[Q.membQueue] = Q.Tail;
        Q.membQueue += 1;
    } else if (arrFull(Q) && !(queFull(Q))){
        Q.Tail += 1;
        Q.T[Q.Tail] = P;
        Q.M[Q.membQueue] = Q.Tail;
        Q.membQueue += 1;
    }else{
        Q.Tail += 1;
        Q.T[Q.Tail] = P;
        Q.membArray += 1;
        Q.M[Q.membQueue] = Q.Tail;
        Q.membQueue += 1;
    }
}
void dequeue(Queue &Q, infotype &P){
    if (isEmpty(Q)){
        cout << "Queue kosong" << endl;
    }else if (Q.Head == Q.Tail){
        P = Q.T[Q.Head];
        Q.Head = -1;
        Q.Tail = -1;
        Q.membQueue = 0;
        Q.M[Q.membQueue] = -1;
    }else{
        P = Q.T[Q.Head];
        Q.Head += 1;
        for (int i = 0 ; i < Q.membQueue - 1; i++){
            Q.M[i] = Q.M[i+1];
        }
        Q.membQueue -= 1;
    }
}
void print(Queue Q){
    for(int i = 0; i < Q.membQueue; i++){
        int j = Q.M[i];
        cout << "Paket " << j << " - ";
        cout << Q.T[j].kode_paket << " ";
        cout << Q.T[j].asal << " to " << Q.T[j].tujuan << endl;
    }
}
