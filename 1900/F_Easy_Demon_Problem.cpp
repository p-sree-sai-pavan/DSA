#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int main( ){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,q;
    cin >> n >> m >> q;
    vector<long long> a(n), b(m);
    long long suma=0, sumb=0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        suma = suma + a[i];
    } 
    for (int i = 0; i < m; i++){
        cin >> b[i];
        sumb = sumb + b[i];
    }

    unordered_set<long long> setA(a.begin(), a.end());
    unordered_set<long long> setB(b.begin(), b.end());

    for(int i =0; i<q; i++){
        long long x;
        cin >> x;
        long long D = suma * sumb - x;
        bool found = false;
        for (long long ar : setA){
            long long deno = suma - ar;
                if (deno == 0) continue;
                long long nume = D - ar * sumb;
                if (nume % deno != 0) continue;
                long long bc = nume / deno;
                if (setB.count(bc)) {
                    found = true;
                    break;
                }
        }
        cout << (found ? "YES\n" : "NO\n");
    }
    return 0;
}



// int main( ){

//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n,m,q;
//     cin >> n >> m >> q;
//     vector<int> a(n), b(m);
//     for (int i = 0; i < n; i++) cin >> a[i];
//     for (int i = 0; i < m; i++) cin >> b[i];
//     for(int i =0; i<q; i++){
//         int x;
//         bool found = false;
//         cin >> x;
//         for (int r = 0; r < n && !found; r++){
//             for (int c = 0; c < m && !found; c++){
//                 int sum =0;
//                 for (int p = 0; p < n && !found; p++){
//                     for (int q = 0; q < m && !found; q++){
//                         if(p != r && q !=c){
//                         sum = sum+a[p]*b[q];
//                         }
//                     }     
//                 }
//                 if(sum == x){
//                     found = true;
//                     cout << "YES\n";
//                 } 
//             }
//         }
//         if(!found) cout<< "NO\n";
//     }
// return 0;
// }

