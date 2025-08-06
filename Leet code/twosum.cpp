#include <iostream>
using namespace std;

int twoSum(int nums, int target) {
    int n = nums.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(nums[i] + nums[j] == target){
                return {i, j};
            }
        }
    }
return {};
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter target: ";
    cin >> target;

    vector<int> result = twoSum(nums, target);
    if (!result.empty()) {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
    } else {
        cout << "No two sum solution found." << endl;
    }
    return 0;
}
