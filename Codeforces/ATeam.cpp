// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     if( n >=1 && n <= 1000){
//         int count = 0;
//         int arr[n][3];
//         for(int i = 0; i <n; i++){
//             for(int j = 0; j < 3; j++){
//                 cin >> arr[i][j];
//             }
//         }
//         for(int i = 0; i < n; i++){
//             if(arr[i][0] + arr[i][1] + arr[i][2] > 1){
//                 count ++;
//             }
//         }
//         cout << count << endl;
//     }
//     return 0;
// }

#include <iostream>
using namespace std;
int main() {
    int n,a,b,c,count = 0;
    cin >> n;
    if (n >= 1 && n <= 1000) {
        for (int i = 0; i < n; i++) {
            if(a+b+c > 1) count++;
        }
        cout << count << endl;
    }
    return 0;
}