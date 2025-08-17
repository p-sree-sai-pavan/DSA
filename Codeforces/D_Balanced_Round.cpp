#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        long long n,k;
        cin >> n >> k;
        vector<long long> arr(n);
        int count = 0;
        int cou = 1;
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        for (int i = 1; i < n; i++){
            if(abs(arr[i] - arr[i-1]) <= k){
                count++;
            }
            else count = 0;
            cou = max(cou, count + 1);
        }
        cout << n - cou << "\n";
    }
    return 0;
}