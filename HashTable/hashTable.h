#pragma once
#include <iostream>

using namespace std;

template<typename Key, typename Value>
class HashTable {
private:
    static const int INITIAL_TABLE_SIZE = 10;
    int tableSize;
    struct Node {
        Key key;
        Value value;
        Node* next;

        Node(Key k, Value v) : key(k), value(v), next(nullptr) {}
    };

    Node** table;

    int hashFunction(const Key& key) {
        return key % tableSize;
    }

    void resizeTable() {
        int newTableSize = tableSize * 2;

        Node** newTable = new Node * [newTableSize] {};

        for (int i = 0; i < tableSize; ++i) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                int newIndex = hashFunction(temp->key) % newTableSize;
                temp->next = newTable[newIndex];
                newTable[newIndex] = temp;
            }
        }

        delete[] table;
        table = newTable;
        tableSize = newTableSize;
    }

public:
    HashTable() : tableSize(INITIAL_TABLE_SIZE) {
        table = new Node * [tableSize] {};
    }

    ~HashTable() {
        for (int i = 0; i < tableSize; ++i) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    void add(const Key& key, const Value& value) {
        if (loadFactor() >= 0.7) {
            resizeTable();
        }

        int index = hashFunction(key);
        Node* newNode = new Node(key, value);

        newNode->next = table[index];
        table[index] = newNode;
    }


    bool find(const Key& key) {
        int index = hashFunction(key);
        Node* current = table[index];

        while (current != nullptr) {
            if (current->key == key) {
                std::cout << "The value for key <" << current->key << "> is [" << current->value << "]\n";
                return true;
            }
            current = current->next;
        }
        std::cout << "The value for key <" << key << "> is not found\n";
        return false;
    }

    bool remove(const Key& key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                }
                else {
                    prev->next = current->next;
                }
                std::cout << "\nDeleted <" << current->value << "> \n";
                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }
        std::cout << "\nKey <" << key << "> is not found\n";
        return false;
    }

    double loadFactor() {
        int count = 0;
        for (int i = 0; i < tableSize; ++i) {
            Node* current = table[i];
            while (current != nullptr) {
                count++;
                current = current->next;
            }
        }
        return static_cast<double>(count) / tableSize;
    }

    bool isEmpty() {
        for (int i = 0; i < tableSize; ++i) {
            if (table[i] != nullptr) {
                return false;
            }
        }
        return true;
    }


    void print() {

        if (isEmpty()) {
            cout << "Hash table is empty" << endl;
            return;
        }
        for (int i = 0; i < tableSize; ++i) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << " ";
                current = current->next;
            }
        }
        cout << endl;
    }
    
};
