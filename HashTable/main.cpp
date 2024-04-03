#include "hashTable.h"

int main() {
    HashTable<int, string> hashTable;

    hashTable.print();

    hashTable.add(1, "One");
    hashTable.add(2, "Two");
    hashTable.add(3, "Three");
    hashTable.add(4, "One");
    hashTable.add(5, "Two");
    hashTable.add(6, "Three");
    hashTable.add(7, "One");
    hashTable.add(8, "Two");
    hashTable.add(9, "Three");
    hashTable.add(10, "One");
    hashTable.add(11, "Two");
    hashTable.add(12, "Three");


    hashTable.print();

    hashTable.remove(2);

    hashTable.print();

    hashTable.remove(0);

    hashTable.find(3);
    hashTable.find(6);




    return 0;
}
