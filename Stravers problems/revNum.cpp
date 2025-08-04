// Online C++ compiler to run C++ program online
#include <iostream>


// int reverseNumber(int n, int rev = 0) {
//     if(n==0){
//         return rev;
//     }
//     return reverseNumber(n/10, rev*10 + n%10);
// }
    int reverse(int x, int rev = 0) {
        if (x == 0) {
            return rev;
        }

        int lastdigit = x % 10;

        // Overflow checks before updating rev
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && lastdigit > 7)) return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && lastdigit < -8)) return 0;

        rev = rev * 10 + lastdigit;
        return reverse(x / 10, rev);
    }

int main() {
    // Write C++ code here
    int n;
    std::cin >> n;
    std::cout << reverse(n);
    return 0;
}