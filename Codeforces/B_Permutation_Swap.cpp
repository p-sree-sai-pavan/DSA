#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int mini = INT_MAX;
        int c;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)cin >> arr[i];
        int g = 0;
        for(int i = 0; i < n; i++){
            g = __gcd(g, abs(arr[i] - (i+1)));
        }
        cout << g << "\n";
    }
    return 0;
}