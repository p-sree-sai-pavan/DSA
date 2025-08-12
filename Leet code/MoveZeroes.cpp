int removeDuplicates(vector<int>& nums) {
        vector<int> result;
        result.reserve(nums.size());
        result.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            if(nums[i] != nums[i-1]){
                result.push_back(nums[i]);
            }
        }
        return result.size();
    }