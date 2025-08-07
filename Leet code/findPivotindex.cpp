int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int leftsum = 0;
            int rightsum = 0;
            for(int j = i-1; j >= 0; j--){
                leftsum = leftsum + nums[j];
            }
            for(int k = i + 1; k < n; k++){
                rightsum = rightsum + nums[k];
            }
            if(leftsum == rightsum ){
                return i;
        }
        }
        return -1;
    }

    // time complexity

    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int leftsum = 0;
        for(int i = 0; i <n; i++){
            sum += nums[i];
        }
        for(int i = 0; i < n; i++){
            leftsum = leftsum + nums[i];
            if(leftsum - nums[i] == sum - leftsum){
                return i;
            }
        }
        return -1;
    }

    // or
    int pivotIndex(vector<int>& nums) {
        int sum = 0,leftsum = 0; 
        for(int i = 0; i <nums.size(); i++) sum += nums[i];
        for(int i = 0; i < nums.size(); i++){
            if(leftsum == sum - leftsum - nums[i]) return i;
            leftsum = leftsum + nums[i];
        }
        return -1;
    }