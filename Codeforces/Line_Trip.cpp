#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    int maxVal[1001];
    if(t>= 0 && t <= 1000){
        for(int i = 0; i<t; i++){
            int n,x;
            cin >> n >> x;
            if(n >= 1 && n <= 50 && x >= 2 && x <=100){
                int arr[52];
                arr[0] = 0;
                // arr[n+1] = x;
                for(int j = 1; j<n+1; j++){
                    cin >> arr[j];
                }
                arr[n+1] = 2*x - arr[n];
                maxVal[i] = -1;
                for(int j=0; j<n + 1; j++){
                    if(maxVal[i] < arr[j+1] - arr[j]){
                        maxVal[i] = arr[j+1] - arr[j];
                    }
                }
            }
        }
        for (int i = 0; i < t; i++){
            cout << maxVal[i] << endl;
        }
    }
    return 0;
}