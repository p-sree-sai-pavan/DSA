#include <stdio.h>
#include <stdlib.h>

void reverse(int *l, int n){
    int temp;
    for (int i = 0; i < n / 2; i++)
    {
        temp = l[i];
        l[i] = l[n - i - 1];
        l[n - i - 1] = temp;
    }
}

int toNumber(int *l, int n) {
    int number = 0;
    for (int i = 0; i < n; i++){
        number = number * 10 + l[i];
    }
    return number;
}

void toList(int*l, int n, int numb ) {
    for (int i = n - 1; i >= 0; i--) {
        l[i] = numb % 10;
        numb /= 10;
    }
}    

int sizeOfList(int numb) {
    int n = 0;
    while (numb > 0) {
        numb /= 10;
        n++;
    }
    return n;
}

int sum(int *l1, int n1, int *l2, int n2) {
    reverse(l1, n1);
    reverse(l2, n2);
    int numb = toNumber(l1, n1) + toNumber(l2, n2);
    printf("%d\n", numb);
    int n = sizeOfList(numb);
    int *l = (int *)malloc(n * sizeof(int));
    toList(l, n, numb);
    reverse(l, n);
    printf("[");
    for (int i = 0; i < n; i++){
        printf("%d", l[i]);
            if (i < n - 1)
                printf(", ");
    }
        printf("]\n");
    return 0;
}

int main() {
    int n1, n2;

    printf("Enter the lengths of the l1: ");
    scanf("%d", &n1);
    int *l1 = (int *)malloc(n1 * sizeof(int));
    printf("Enter the elements of l1: ");   
    for (int i = 0; i < n1; i++) {
        scanf("%d", &l1[i]);
    }

    printf("Enter the lengths of the l2: ");
    scanf("%d", &n2);
    int *l2 = (int *)malloc(n2 * sizeof(int));
    printf("Enter the elements of l2: ");       
    for (int i = 0; i < n2; i++) {
        scanf("%d", &l2[i]);
    }   
    sum(l1, n1, l2, n2);
}    
