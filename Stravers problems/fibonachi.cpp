#include<bits/stdc++.h>
using namespace std;

// using multiple recurssions

int f(int n){
    if(n<=1){
        return n;
    }
    int last = f(n-1);
    int slast = f(n-2);
    return last + slast;
}

int main(){
    int n;
    cout << "Enter the number of Fibonacci terms: ";
    cin >> n;
    cout << f(n-1);
}

// void fib(int arr[], int i, int n) {
//     if(i<n && i > 1) {
//         arr[i] = arr[i-1] + arr[i-2];
//         fib(arr, i+1, n);
//     }
// }

// int main(){
//     int n;
//     cout << "Enter the number of Fibonacci terms: ";
//     cin >> n;
//     int arr[n];
//     arr[0] = 0;
//     arr[1] = 1;
//     fib(arr, 2, n);
//     for(int i=0; i < n; i++) {
//         cout << arr[i] << " " ;
//     }
//     return 0;
// }