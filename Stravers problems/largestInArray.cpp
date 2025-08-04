#include<iostream>
using namespace std;

int largest(int arr[], int n){
    int max = arr[0];
    for(int i = 0; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";   
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int maxElement = largest(arr, n);
    cout << "The largest element in the array is: " << maxElement << endl;
    return 0;
}