#include "hashTable.h"

int main() {
    HashTable<int, string> hashTable;

    hashTable.print();

    hashTable.add(1, "One");
    hashTable.add(2, "Two");
    hashTable.add(3, "Three");

    hashTable.print();
    string value;
    hashTable.find(2, value); 

    hashTable.remove(2); 

    hashTable.print();

    hashTable.find(2, value); 

    hashTable.find(4, value);

    hashTable.remove(4);

    hashTable.print();

    return 0;
}
