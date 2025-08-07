#include<iostream>
using namespace std;

int maxProfit(vector<int>& prices) {
        int pro = 0;
        int s=prices.size();
            for(int i = 0; i<s; i++){
                for(int j= i+1; j < s; j++){
                    if(prices[j]-prices[i] > pro){
                        pro = prices[j]-prices[i];
                    }
                }
            }
        return pro;
    }

int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minprice = INT_MAX;
        int s=prices.size();
            for(int i = 0; i<s; i++){
                if(minprice > prices[i]){
                    minprice = prices[i];
                }
                else if(prices[i] - minprice > profit){
                    profit = prices[i] - minprice;
                }
            }
        return profit;
    }