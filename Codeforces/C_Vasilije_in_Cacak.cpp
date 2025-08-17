#include<iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n,k,x;
        cin >> n >> k >> x;
        long long a = (n*(n+1))/2;
        if(x <= a  && (k*(k+1))/2 <= x) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}