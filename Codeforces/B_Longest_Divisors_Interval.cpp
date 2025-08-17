#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        int div = 0,count = 0;

        for (int i = 1; i < 75; i++){
            if(n%i == 0 && n%(i+1)==0 ){
                count++;
            }
            else count = 0;
            div = max(div, count);
        }
        cout << div+1 << "\n";
    }
    return 0;
}