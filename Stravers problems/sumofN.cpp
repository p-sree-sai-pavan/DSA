#include <iostream>
int NumbersSum(int N, int sum = 0){
	if(N==0){
	    return sum;
	}
	sum = sum + N;
	return NumbersSum(N-1, sum);
}

int main() {
    int N;
    std::cin >> N;
    std::cout << NumbersSum(N);
    return 0;
}