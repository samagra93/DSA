#include <stdio.h>
#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;
}

int hashFunction(int sapID) {
    int lastThree = sapID % 1000;
    return lastThree % 10;
}

void insert(int sapID) {
    int index = hashFunction(sapID);
    int originalIndex = index;

    while (hashTable[index] != -1) {
        printf("Collision at index %d. Probing next slot...\n", index);
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("Error: Hash Table is full. Cannot insert SAP-ID %d\n", sapID);
            return;
        }
    }
    hashTable[index] = sapID;
    printf("Inserted SAP-ID %d at index %d\n", sapID, index);
}

void delete(int sapID) {
    int index = hashFunction(sapID);
    int originalIndex = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == sapID) {
            hashTable[index] = -1;
            printf("Deleted SAP-ID %d from index %d\n", sapID, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) break;
    }
    printf("SAP-ID %d not found in the hash table.\n", sapID);
}

void search(int sapID) {
    int index = hashFunction(sapID);
    int originalIndex = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == sapID) {
            printf("SAP-ID %d found at index %d\n", sapID, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) break;
    }
    printf("SAP-ID %d not found in the hash table.\n", sapID);
}

void display() {
    printf("\nHash Table State:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
        printf("Index %d: %d\n", i, hashTable[i]);
}

int main() {
    initHashTable();

    insert(590014891);
    insert(590012422);
    insert(590012761); 

    display();

    search(590012422);
    delete(590012422);
    search(590012422);

    display();

    return 0;
}
