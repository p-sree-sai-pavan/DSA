#include <iostream>

 int countDigit(int n) {
    static int sum = 0;
    if(n>0){
        n = (n/10);
        sum++;
        countDigit(n);
    }
    return sum;
}


int main() {
    // Write C++ code here
    int n;
    std::cin >> n;
    std::cout << countDigit(n);

    return 0;
}