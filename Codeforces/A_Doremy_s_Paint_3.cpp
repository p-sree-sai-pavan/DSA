#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<string> result(t);
    for(int i =0; i<t; i++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int j = 0; j<n; j++) cin >> arr[j];

        set<int> newarr(arr.begin(), arr.end()); 
        int count1=0,count2=0;

        for(int j=0; j<n; j++){
            if(arr[j] == *newarr.begin()) count1++;
            if(arr[j] == *newarr.rbegin()) count2++;
        }

        if(newarr.size() == 1) result[i] = "Yes";
        else if(newarr.size()==2){
                if(n%2 == 0) result[i] = (count1 == count2) ? "Yes" : "No";
                else result[i] = (count1 == count2+1 || count2 == count1+1) ? "Yes" : "No";
        }
        else result[i] = "No";
    }
    for (int i = 0; i < t; i++) cout << result[i] << "\n";
}