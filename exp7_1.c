#include <stdio.h>

int hashFunction(int sapID) {
    int lastThree = sapID % 1000;
    return lastThree % 10;
}

int main() {
    int sapID;
    printf("Enter SAP-ID: ");
    scanf("%d", &sapID);

    int family = hashFunction(sapID);
    printf("SAP-ID %d belongs to Family %d\n", sapID, family);

    return 0;
}
