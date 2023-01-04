#ifndef QUEUE3_H_INCLUDED
#define QUEUE3_H_INCLUDED

#include <iostream>
using namespace std;

const int MAX = 5;
struct infotype{
    string kode_paket;
    string asal;
    string tujuan;
};
typedef int address;
struct Queue{
    infotype T[MAX];
    address Head;
    address Tail;
    int membQueue;
    int membArray;
    int M[MAX];
};

bool isEmpty(Queue Q);
bool arrFull(Queue Q);
bool queFull(Queue Q);
void createQueue(Queue &Q);
void enqueue(Queue &Q, infotype P);
void dequeue(Queue &Q, infotype &P);
void print(Queue Q);

#endif // QUEUE3_INCLUDED
