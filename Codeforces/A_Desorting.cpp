#include<iostream>
#include<vector>
using namespace std;

int main(){
int t;
cin >> t;
for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int j=0; j<n; j++) cin >> arr[j];
    int min = arr[1]-arr[0];
    bool unsorted = false;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            unsorted = true;
            break;
        }
    }

    if (unsorted) {
        cout << 0 << "\n";
        continue;
    }
    for (int j = 0; j < n-1; j++){
            if(min > arr[j+1]-arr[j]) min = arr[j+1]-arr[j];
        }
    cout << (min + 2)/2 << "\n";
}
return 0;
}
