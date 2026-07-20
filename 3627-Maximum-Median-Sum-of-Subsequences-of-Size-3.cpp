class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long r=0;
        for(int i=n/3;i<n;i+=2){
                r+=nums[i];
        }
        return r;
        
        
    }
};