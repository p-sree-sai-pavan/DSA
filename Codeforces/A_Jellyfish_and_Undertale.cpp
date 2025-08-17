#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        long long a,b,n;
        cin >> a >> b >> n;
        vector<long long> arr(n);
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
            if(arr[j] <= a-1) b += arr[j];
            else b += a-1;
        }
        cout << b << "\n";
    }
    return 0;
}