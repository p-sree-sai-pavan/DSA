#include<iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int s,k;
        string n;
        cin >> s >> k;
        cin >> n;
        vector<int> freq(26, 0);
        for(int j = 0; j < s; j++){
            if (n[j] >= 'a' && n[j] <= 'z'){
                freq[n[j] - 'a']++;
            }
        }
        int odd =0;
        for (int j = 0; j < 26; j++){
            if(freq[j] % 2 !=0){
                odd++;
            }
        }
        if(k >= odd-1)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
    