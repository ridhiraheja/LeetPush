class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // Start from index 1 since the running sum at index 0 is just nums[0]
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};