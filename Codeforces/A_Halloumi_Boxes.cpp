#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int j = 0; j < n; j++){
            cin >> arr[j];
        }
        vector<int> b= arr;
        sort(b.begin(), b.end());
        if( k == 1 && b!=arr) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}