// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

bool isArmstrong(int n) {
    int sum = 0;
    for(int i = n; i > 0; i = i/10){
        int last = i%10;
        sum = sum + (last * last * last);
    }
    return sum == n;
}
int main() {
    // Write C++ code here
    int n;
    cin >> n;
    if(isArmstrong(n)){
        cout << "True";
    }
    else{
        cout << "False";
    }
    return 0;
}