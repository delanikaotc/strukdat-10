// Nama Program : exercise1
// Nama         : Delanika Olymiani
// NPM          : 140810180026
// Kelas        : B
// Tahun        : 2019
// Deskripsi    : Program pengunjung stand menggunakan circular queue menggunakan array

#include <iostream>

using namespace std;

const int maxElemen = 5; // membuat tipe data integer yang tidak dapat diubah

struct queue { // membuat struct dengan judul Queue
    char data[maxElemen]; // tipe data char dengan array
    char head; // untuk tipe data awal antrian
    char tail; // untuk tipe data akhir antrian
};

void createQueue (queue &q){ // fungsi untuk membuat Queue
    q.head = -1;            // deklarasi awal antrian kosong
    q.tail = -1;           // deklarasi akhir antrian kosong
}

void insertQueue(queue &q, char elm){ // fungsi untuk memasukkan data ke dalam antrian
    int temp;
    if (q.tail == -1){  // apabila isi queue kosong
        // memasukkan data pertama
        q.head = 0; // awal antrian tambah satu dari -1
        q.data[q.head] = elm; //data ke-1 = elm yang dibuat
        q.tail = 0; // akhir antrian tambah satu dari -1
    }
    else{
        temp = q.tail;
        if (q.tail < maxElemen-1){ // queue sudah berisi
            // memasukkan data lain
            q.tail = q.tail+1; // akhir antrian tambah 1
            q.data[q.tail] = elm; // data terakhir diupdate
        }
        else {
            if (q.head == q.tail){
                cout<<"The queue is full!"<<endl;
                q.tail = temp;
            }
            else {
                q.tail = 0; // akhir antrian kembali ke 0
                q.data[q.tail] = elm; // mengisi slot ke 0
            }
        }
    }
}

void deleteQueue (queue& q, char elemenHps){
    if (q.tail == -1){ // antrian kosong
        cout<<"The queue is empty, nothing is deleted!"<<endl;
    }
    else if (q.head == q.tail){ // antrian hanya isi 1 data
        elemenHps = q.data[q.head];
        q.head = -1;            // deklarasi kembali antrian menjadi kosong
        q.tail = -1;
    }
    else {
        if (q.head < maxElemen-1){ // apabila awal antrian mencapai akhir
            q.head = q.head+1;
        }
        else {
            q.head = 0;
        }
    }
}

void print (queue q){
    if (q.head == -1){
        cout<<"The queue is empty, nothing is printed!"<<endl;
    }
    else{
        cout<<"Queue"<<endl;
        if (q.head > q.tail){
            while (q.head < maxElemen){
                cout<<q.data[q.head]<<" ";
                q.head = q.head+1;
            }
            q.head = 0;
            while (q.head <= q.tail){
                cout<<q.data[q.head]<<" ";
                q.head = q.head+1;
            }
        }
        else {
            while(q.head <= q.tail){
                cout<<q.data[q.head]<<" ";
                q.head = q.head+1;
            }
        }
    }
    cout<<endl;
}

int main(){
    queue q;
    int pilihan, jumlah;
    char d, h;
    
    createQueue(q);
    
    cout<<"Input the amount of data(s) (Max "<<maxElemen<<"): "; cin>>jumlah;
    if (jumlah > maxElemen){
        cout<<"Check your amount of data(s)!"<<endl;
        return 0;
    }
    
    for(int i=0; i<jumlah; i++){
        cout<<"Input data: "; cin>>d;
        insertQueue(q, d);
    }
    
    while(1){
        cout<<"1. Add more data to queue"<<endl;
        cout<<"2. Delete data from queue"<<endl;
        cout<<"3. Print the queue"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Input your query: "; cin>>pilihan;
        
        switch(pilihan){
            case 1:
                cout<<"Input data: "; cin>>d;
                cout<<endl;
                insertQueue(q, d);
                break;
            
            case 2:
                deleteQueue(q, h);
                break;
                
            case 3:
                print(q);
                break;
                
            case 4:
                return 0;
                break;
        }
    }
}
