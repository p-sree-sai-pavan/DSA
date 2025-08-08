#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> array(t, -1);
    if(t >= 1 && t <=10000){
        for(int i=0;i<t;i++){
            int n,m;
            cin >> n >> m ;
            string x,s;
            if(n*m>=1 && n*m <= 25){
                cin >> x;
                cin >> s;
                int count=0;
                if(x.find(s) != string::npos){
                    array[i] = 0;
                    continue;
                }
                for(int j=0; j<6; j++){
                    x = x + x ;
                    count++;
                    if(x.find(s) != string::npos){
                        array[i] = count;
                        break;
                    }
                }
                if(array[i] == 6) array[i] = -1;
            }
        }
        for(int i=0;i<t;i++){
            cout << array[i] << "\n";
        }
    }
    return 0;
}