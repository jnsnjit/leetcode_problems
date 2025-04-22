#include <vector>

using namespace std;
/*
    HashMap implementation with Linked List
    without hashing function, it will work basically like a linked list, working in O(n) time
    by hashing you make the while loop section of the code very small (will only occur when collision with the hashing function occurs)
    for this implementation, I will use a simple hashing function, modulus % semi large integer
*/

//create node class
class node{
    public:
        int value;
        int key;
        //pointer to next node
        node* next;

        node(int key, int value){
            this->value = value;
            this->key = key;
            //when initilized, point to null for now//
            this->next = nullptr;
        }
};
class MyHashMap {
public:
    static const int mSIZE = 10000;
    vector<node*> table;

    MyHashMap() {
        table.resize(mSIZE,nullptr);
    }
    int hash(int key){
        return (key % 10000 + 10000) % 10000;
    }
    void put(int key, int value) {
        int hkey = hash(key);

        if(!table[hkey]){
            table[hkey] = new node(key, value);
        }else{
            node* temp = table[hkey];
            //move through potential collision nodes for key value pair
            while (temp->next!=nullptr) {
                if (temp->key == key) {
                    temp->value = value;
                    return;
                }
                temp = temp->next;
            }
            temp->next = new node(key, value);
        }
    }
    
    int get(int key) {
        int hkey = hash(key);
        node* temp = table[hkey];

        while(temp){
            if(temp->key==key){
                //return key's value;
                return temp->value;
            }
            temp = temp->next;
        }
        //return negative one if not found
        return -1;
    }
    
    void remove(int key) {
        int hkey = hash(key);
        node* temp = table[hkey];
        node* prev = nullptr;

        while (temp) {
            if (temp->key == key) {
                if (prev) {
                    prev->next = temp->next;
                } else {
                    table[hkey] = temp->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */