#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    if( n >=1 && n <= 100){
        vector<string> strings(n);
        for(int i = 0; i < n; i++) {
            cin >> strings[i];
        }
        for(int i = 0; i < n; i++) {
            if(strings[i].length() > 10) {
                cout << strings[i].front() << strings[i].length() - 2 << strings[i].back() << endl;
            }
            else {
                cout << strings[i] << endl;
            }
        }
    }
    return 0;
}