#include<iostream>
using namespace std;

int main(){
    int t=0;
    cin >> t;
    for(int i=0; i<t; i++){
        int a,b,c;
        cin >> a >> b >> c ;
        if(c%2 !=0 && a >= b) cout << "First\n";
        else if(c%2 ==0 && a > b) cout << "First\n";
        else cout << "Second\n";
    }
    return 0;
}