#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> array(t);
    int n,k;
    if(t >= 1 && t <= 1000){
        for (int j = 0; j < t; j++){
            cin >> n >> k;

            if(n >=1 && n <= 100 && k >=1 && k <= 100){
                vector<int> arr(n);
                bool found = false;
                for(int i  = 0; i < n; i++){
                    cin >> arr[i];
                    if(arr[i] == k) found = true;
                }
                array[j] = found;
            }
        }
        for (int j = 0; j < t; j++){
            if(array[j]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}