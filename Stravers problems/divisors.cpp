// #include <iostream>
// #include <cmath>
// using namespace std;

// int divisors(int n) {
//     printf("[1");
//     for(int i = 2; i <= n;i++){
//         if(n % i == 0){
//             printf(", %d", i );
//         }
//     }
//     printf("]");
//     return 0;
// }

// int main(){
//     int n;
//     cin >> n;
//     divisors(n);
//     return 0;
// }

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int divisors(int n) {
   vector <int> ls;
    for(int i = 1; i <= sqrt(n);i++){
        if(n % i == 0){
            ls.push_back(i);
            if(n/i != i){
                ls.push_back(n/i);
            }
        }
    }
    sort(ls.begin(),ls.end());
    for(auto it : ls) cout << it << " ";
    return 0;
}

int main(){
    int n;
    cin >> n;
    divisors(n);
    return 0;
}