class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea=0;
            for(int l=0,r=height.size()-1; l < r;){
                int w = r-l;
                int h=min(height[l], height[r]);
                maxarea = max(maxarea, w*h);
                if(height[l] < height[r]){
                    l++;
                }
                else{
                    r--;
                }
            }
        return maxarea;
    }
};