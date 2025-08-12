#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
    string b;
    cin >> a >> b;
    if(a == b) cout << 0;
    else {
        for(int i=0; i<a.size(); i++){
            a[i] = tolower((unsigned char)a[i]);
            b[i] = tolower((unsigned char)b[i]);
            if(a[i]> b[i]) cout << 1;
            if(a[i]< b[i]) cout << -1;
        }
    }
    return 0;
}