#include<iostream>
using namespace std;

#define MAX 10

class Deque{
    int arr[MAX];
    int front;
    int rear;
    int size;

    public:
    Deque(int size){
        front = -1;
        rear = 0;
        this->size = size;
    }

    void insertfront(int key);
    void insertrear(int key);
    void removefront();
    void removerear();
    bool isFull();
    bool isEmpty();
    int getfront();
    int getrear();
};

bool Deque::isFull(){
    return((front == 0 && rear == size - 1) || front == rear + 1);
}

bool Deque::isEmpty(){
    return(front == -1);
}

void Deque::insertfront(int key){
    if(isFull()) {
        cout << "Overflow\n" << endl;
        return ;
    }

    if(front == -1){
        front = 0;
        rear = 0;
    }    

    else if(front == 0){
        front = size-1;
    }

    else
       front = front - 1;
    arr[front] = key;  
}

void Deque::insertrear(int key){
    if(isFull()){
        cout<<"Overflow\n"<<endl;
        return;
    }
    if(front == -1){
        front = 0;
        rear = 0;
    }
    else if (rear = size - 1)
       rear = 0;

    else 
      rear = rear + 1;

    arr[rear] = key;     
       
}

void Deque :: removefront(){
    if(isEmpty()){
        cout<<"Queue Underflown"<<endl;
    }
    if ( front == rear ){
        front = -1;
        rear = -1;
    }else if (front = size -1)
        front = 0;

    else
       front = front + 1 ;
}

void Deque :: removerear(){
    if(isEmpty()){
        cout <<"Underflow\n"<<endl;
        return;
    }
    if(front == rear){
        front = -1;
        rear = -1;        
    }
    else if(rear == 0)
      rear = size - 1;
    else 
      rear = rear - 1;  
}

int Deque :: getfront(){
    if(isEmpty()){
        cout<< "Underflown\n"<<endl;
        return -1;
    }
    return arr[front];
}

int Deque :: getrear(){
    if(isEmpty() || rear <0){
        cout<< "Underflow\n"<<endl;
        return -1;
    }
    return arr[rear];  
}

int main(){
    Deque dq(4);
    
    cout<<"Insert an element at rear end";
    dq.insertrear(5);

    cout<<"Insert an element at rear end";
    dq.insertrear(11);

    cout<<"rear element: "<< dq.getrear()<<endl;

    dq.removerear();
    cout<<"after deletion of element , the new rear element is: "<<dq.getrear()<<endl;

    cout<<"insert element at front end";

    dq.insertfront(8);

    cout<<"from element: "<<dq.getfront()<<endl;

    dq.removefront();

    cout <<"after deletion of element , the new front element is: "<<dq.getfront()<<endl;

}
    
