#include<iostream>
using namespace std;

int main(){
    int t;
    cout << "enter";
    cin >> t;
    if(t >= 1 && t <=100){
        int n[1001];
        for(int i=0;i<t;i++){
            cin >> n[i];
        }
        for(int i=0;i<t;i++){
            if(n[i] >= 1 && n[i] <=1000){
                if(n[i]%3 == 0){
                    cout << "Second" << "\n";
                }
                else{
                    cout << "First" << "\n";
                }
            }
        }
    }
    return 0;
}