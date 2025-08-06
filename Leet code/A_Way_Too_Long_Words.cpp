#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> strings(n);
    for(int i = 0; i < n; i++) {
        cin >> strings[i];
    }
    for(int i = 0; i < n; i++) {
        if(strings[i].length() > 10) {
            cout << strings[i].front() << strings[i].length() << strings[i].back() << endl;
        }
    }
    return 0;
}