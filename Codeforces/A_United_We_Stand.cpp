#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int j=0; j<n; j++) cin >> arr[j];
        int min= *min_element(arr.begin(), arr.end());
        int count =0;
        for(int j=0; j<n; j++){
            if(min >= arr[j]){
                min = arr[j];
            }
        }
        for(int j=0; j<n; j++){
            if(min == arr[j]) count++;
        }
        
        if(count == n ){
            cout << -1 <<"\n";
        }
        else{
            cout << count << " " << n-count << "\n";
            for(int j=0; j<count; j++) cout << min << " ";
            cout << "\n";
            for(int j=0; j<n; j++){
                if(arr[j]!= min){
                    cout << arr[j] << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}