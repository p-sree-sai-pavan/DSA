class Solution {
public:
    bool isPalindrome(string s) {
        string result = "";
        for(int i=0; i<s.size(); i++){
            if(isalnum(s[i])){
                result += tolower(s[i]);
            }
        }
        for(int right = result.size()-1, left=0; left < right;){
            if(result[left]==result[right]){
                left++;
                right--;
            }
            else return false;
        }
        return true;
    }
};