#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> result(t);
    for(int i=0; i<t; i++){
        char arr[10][10];
        for (int j = 0; j < 10; j++){
            for(int k=0; k<10; k++){
                cin >> arr[j][k];
            }
        }
        int score=0;
        for (int j = 0; j < 10; j++){
            for(int k=0; k<10; k++){
                if(arr[j][k]=='X'){
                    int min_dist = min({j, k, 9-j, 9-k});
                    int ring_score = min_dist + 1;
                    score += ring_score;
                } 
            }
        }
        result[i]=score;
    }
    for(int i=0; i<t; i++){
        cout<<result[i]<<"\n";
    }
}