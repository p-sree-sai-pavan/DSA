#include <iostream>
using namespace std;

int main(){
    int n, k, count = 0;
    cin >> n >> k;
    int arr[n];
    if(k>=1 && k<=50 && n>=1 && n<=50){
        for(int i=0; i < n; i++){
            cin >> arr[i];
        }
        for (int i =0; i<n; i++){
            if(arr[i] >= 0 && arr[i] <= 100){
                if(arr[i] >= arr[k-1] && arr[i] > 0 ){
                    count++;
                }
            }
        }
     }
    cout << count;
    return 0;
}