#include<iostream>
#include<list>
using namespace std;

class Hashtable{
int capacity;
list<int> *table;

public:
    Hashtable(int V);
    void insertItem(int key, int data);
    void deleteItem(int key );

    int checkprime(int n){
    int i;
    if(n ==1 || n == 0)
    {
        return 0;
    }
    for(i = 2;i< n/2; i++){
        if (n% i == 0){
            return 0;
        }
    }
    return 1;
}

int getPrime(int n){
    if(n % 2 == 0){
        n++;
    }
    while(!checkprime(n)){
        n += 2;
    }
    return n;
}

int hashfunction(int key)
{
    return (key % capacity);
}

void displayHash();
};
Hashtable::Hashtable(int c){
    int size = getPrime(c);
    this -> capacity = size ;
    table = new list<int>[capacity];
}
void Hashtable::insertItem(int key, int data){
    int index = hashfunction(key);
    table[index].push_back(data);
}

void Hashtable::deleteItem(int key){
    int index = hashfunction(key);

    list<int>::iterator i;
    for(i = table[index].begin();
    i != table[index].end();i++){
        if (*i == key)
          break;
    }
    if( i != table[index].end())
       table[index].erase(i);

}

void Hashtable::displayHash(){
    for (int i = 0; i< capacity ;i++){
        cout<<"table["<<i<<"]";
        for (auto x: table[i]){
            cout << "-->"<<x ;   
        }
        cout<<endl;
    }
}

int main(){
    int key[] = {211,321,234,256,278 ,289};
    int data[] = {411,412,413,414,415,416};
    int size = sizeof(key)/sizeof(key[0]);

    Hashtable h(size);

    for(int i = 0; i<size;i++){
        h.insertItem(key[i],data[i]);
    }

   h.deleteItem(21);
   h.displayHash();

};