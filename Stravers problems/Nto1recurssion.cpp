#include <iostream>
void printNumbers(int n) {
    if(n >= 1){
      std::cout << n << std::endl;
      printNumbers(n-1);
    }
}
int main() {
    int n;
    std::cin >> n;
    printNumbers(n);
    return 0;
}