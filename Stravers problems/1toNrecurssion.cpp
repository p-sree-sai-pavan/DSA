// Online C++ compiler to run C++ program online
#include <iostream>
void printNumbers(int n, int i = 1) {
    if(n >= i){
      std::cout << i << std::endl;
      printNumbers(n, i+1);
    }
}
int main() {
    // Write C++ code here
    int n;
    std::cin >> n;
    printNumbers(n);
    return 0;
}