class Solution {
public:
    void reverseString(vector<char>& s) {
        int k=0;
        for(int i=(s.size()-1); i>(s.size()-1)/2; i--){
            swap(s[k],s[i]);
            k++;
        }
    }
};