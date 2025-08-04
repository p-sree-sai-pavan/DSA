// #include<iostream>
// using namespace std;

// int reverse(int x, int rev= 0){
//     if(x == 0) return rev;
//     if(rev >= INT_MAX/10 || rev <= INT_MIN/10) return -1; // Handle overflow
//     return reverse(x/10, rev*10 + x % 10);
// }

// bool isPalindrome(int x) {
//     if(x < 0) return false; // Handle negative numbers
//     return x == reverse(x);
// }

// int main(){
//     int x;
//     cin >> x;
//     if(isPalindrome(x)) cout << "true" << endl;
//     else cout << "false" << endl;
//     return 0;
// }

// alternative solution using string
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0) return false;
    