// Nama Program : exercise2
// Nama         : Delanika Olymiani
// NPM          : 140810180026
// Kelas        : B
// Tahun        : 2019
// Deskripsi    : Program pengunjung stand menggunakan circular queue menggunakan linked list

#include <iostream>
using namespace std;

struct data{
    char info;
    data* next;
};

struct queue{
   data *head;
   data *tail;
};

typedef data* pointer;
typedef pointer list;

queue q;

void createQueue(queue &q){
    q.head=NULL;
    q.tail=NULL;
}

void createData(pointer &pBaru){
    pBaru = new data;
    cout << "Input a word: "<<endl; cin>>pBaru->info;
    pBaru->next=NULL;
}

void insertQueue (queue &q, pointer &pBaru){
    if(q.head == NULL){
        q.head=pBaru;
        q.tail=pBaru;
    }else{
        q.tail->next=pBaru;
        q.tail=pBaru;
    }
}

void deleteQueue(queue &q, pointer pHapus){
    if(q.head == NULL){
        cout<<"The queue is empty! Nothing is deleted."<<endl;
    }
    else{
        pointer pHapus;
        pHapus=q.head;
        q.head=q.head->next;
        pHapus->next=NULL;
    }
}

void print(queue q){
    if(q.head==NULL){
        cout<<"The queue is empty! Nothing is printed."<<endl;
    }
    else{
        pointer pBantu;
        pBantu = q.head;
        
        cout<<"Queue"<<endl;
        while(pBantu!=NULL){
            cout<<pBantu->info<<" ";
            pBantu=pBantu->next;
        }
        cout<<endl;
    }
}

int main(){
    queue Q;
    pointer p, pHapus;
    int pilihan;
    
    createQueue(Q);
    
    while(1){
        cout<<"1. Add more data to the queue"<<endl;
        cout<<"2. Delete a data from the queue"<<endl;
        cout<<"3. Print the data(s)"<<endl;
        cout<<"4. Exit"<<endl;
        cout<< "Your query: "; cin >> pilihan;
        
        switch(pilihan){
            case 1:
                createData(p);
                insertQueue (q, p);
                break;
                
            case 2:
                deleteQueue(q, pHapus);
                break;
                
            case 3:
                print (q);
                break;
                
            case 4:
                return 0;
                break;
        }
    }
}
