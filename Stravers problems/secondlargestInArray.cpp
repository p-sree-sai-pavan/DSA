#include<iostream>
using namespace std;

int secondlargest(int arr[], int n){
    int max = arr[0];
    int req = -1;
    for(int i = 0; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if( arr[i] > req && arr[i] != max){
            req = arr[i];
        }
    }
    return req;
}

 int secondSmallest(int arr[], int n){
    int min = arr[0];
    int reqmin = INT_MAX;
    for(int i=0; i<n; i++){
        if(arr[i] < min){
            min = arr[i];
        }
        if(arr[i] < reqmin && arr[i] != min){
            reqmin = arr[i];
        }
    }
    return reqmin;
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
    int secondMax = secondlargest(arr, n);
    int secondMin = secondSmallest(arr, n);
    cout << "The second largest element in the array is: " << secondMin << endl;
    cout << "The second largest element in the array is: " << secondMax << endl;
    return 0;
}