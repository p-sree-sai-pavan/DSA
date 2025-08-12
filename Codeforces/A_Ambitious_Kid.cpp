#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<n; i++) if(arr[i] < 0 ) arr[i] = arr[i]*(-1);
    int mini= *min_element(arr.begin(),arr.end());
    cout<< mini;
    return 0;
}