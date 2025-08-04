#include <iostream>
int factorial(int N, int fact = 1){
	if(N==0){
	    return fact;
	}
	fact = fact * N;
	return factorial(N-1, fact);
}

int main() {
    int N;
    std::cin >> N;
    std::cout << factorial(N);
    return 0;
}