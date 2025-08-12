#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> k;
            if(k==1){
                cout << abs(i-2)+abs(j-2);
                return 0;
            }
        }
    }
}