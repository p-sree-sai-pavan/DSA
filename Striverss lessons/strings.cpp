#include<iostream>
#include<string>
using namespace std;

int main() {
    // Different ways to create strings
    string s1;                    // Empty string
    string s2 = "Hello";          // Direct initialization
    string s3("World");           // Constructor
    string s4(5, 'A');           // "AAAAA" - 5 A's
    string s5 = s2;              // Copy from another string
    string s6, s7, s8;
    
    // Single word input
    cin >> s6;           // Stops at whitespace
    
    // Full line input (including spaces)
    getline(cin, s7);    // Reads entire line
    
    // Skip whitespace then read line
    cin.ignore();        // Clear buffer
    getline(cin, s8);
    
    cout << "Word: " << s6 << endl;
    cout << "Line: " << s7 << endl;
    
    cout << s1 << "|" << s2 << "|" << s3 << "|" << s4 << "|" << s5 << endl;
    return 0;
}