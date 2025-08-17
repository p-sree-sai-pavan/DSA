#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=0;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        int odd=0,even=0;
        for(int i=0; i<n; i++){
            int a;
            cin >> a;
            if(a%2==0) even = even+a;
            if(a%2!=0) odd = odd+a;
        }
        if(even%2 == odd%2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}