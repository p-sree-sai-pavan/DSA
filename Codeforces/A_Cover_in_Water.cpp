#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> result(t);
    if(t>=1 && t <=100){
        for(int i = 0;i < t; i++){
            int n;
            cin >> n;
            string s;
            cin >> s;
            int left =0;
            bool count = false;
            for(int j=0; j<n; j++){
                if(s[j] == '.'){
                    left ++;
                }
            }
            for(int j=0; j<n-2; j++){
                if(s[j+2] == '.' && s[j+1] == '.' && s[j] == '.'){
                    count = true;
                    break;
                }
            }
            if(count){
                result[i] = 2;
            }
            else{
                result[i] = left;
            }
        }
    }
    for(int i = 0;i < t; i++){
        cout << result[i] << "\n";
    }
    return 0;
}