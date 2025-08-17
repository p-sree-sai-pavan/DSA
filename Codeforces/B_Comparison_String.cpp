#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n;
        cin >> s;
        int count = 2;
        int maxcount = 2;
        for (int i = 1; i < n; i++){
            if(s[i] == s[i-1]){
                count++;
            }
            else count = 2;
            maxcount = max(maxcount, count);
        }
        cout << maxcount << "\n";
    }
}