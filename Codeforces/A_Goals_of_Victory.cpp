#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> result(t);
    for(int j=0; j<t; j++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n-1; i++) cin >> arr[i];
        int eff = 0;
        for(int i=0; i<n-1; i++) eff = eff + arr[i];
        result[j] = eff*(-1);
    }
    for(int j =0; j<t; j++){
        cout << result[j] << "\n";
    }
}