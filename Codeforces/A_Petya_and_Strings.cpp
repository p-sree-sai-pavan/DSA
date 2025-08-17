#include<iostream>
#include<vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
    string b;
    cin >> a >> b;
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    if(a == b){
        cout << 0;
        return 0;
    } 
    else {
        for(int i=0; i<a.size(); i++){
            if(a[i]> b[i]){
                cout << 1;
                return 0;
            } 
            if(a[i]< b[i]){
                cout << -1;
                return 0;
            } 
        }
    }
    return 0;
}