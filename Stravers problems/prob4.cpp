#include <iostream>
using namespace std;

void nStarTriangle(int n) {
    for(int i = 0; i < n; i++) {
        // Print spaces
        for(int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        // Print stars
        for(int j = 0; j < 2 * i + 1; j++) {
            cout <<"*";
        }
        cout << "\n";
    }
}
// Sam is making a Star Triangle for a visual project.
int main() {
    int n;
    cout << "Enter the number of rows for the star triangle: ";
    cin >> n;
    
    if(n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }
    
    nStarTriangle(n);
    
    return 0;
}