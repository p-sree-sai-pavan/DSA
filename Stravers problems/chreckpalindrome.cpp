#include <iostream>
#include <climits>
using namespace std;

int reverse(int n, int rev = 0) {
    if (n == 0) {
        return rev;
    }
    int lastdigit = n % 10;
    // Overflow checks before updating rev
    if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && lastdigit > 7)) return 0;
    if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && lastdigit < -8)) return 0;

    rev = rev * 10 + lastdigit;
    return reverse(n / 10, rev);
}

bool isPalindrome(int n ) {
    return n==reverse(n);
}
int main() {
    // Write C++ code here
    int n;
    cin >> n;
    if(isPalindrome(n)){
        cout << "True";
    }
    else{
        cout << "False";
    }

    return 0;
}