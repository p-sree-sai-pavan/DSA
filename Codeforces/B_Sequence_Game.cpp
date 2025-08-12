#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> result; // reserve space to make push_back slightly faster.
        result.reserve(2 * n);
        for (int j = 0; j < n; j++) cin >> arr[j];
        for (int j = 0; j < n-1; j++) {
            result.push_back(arr[j]);
            if(arr[j+1] < arr[j]){
               result.push_back(1); 
            } 
        }
        result.push_back(arr[n-1]);
        cout << result.size() << "\n";
        for (int val : result) cout << val << " ";
        cout << "\n";
    }
    return 0;
}