class Solution {
public:
    bool solve(int i,vector<int>&nums,int sum,int n,vector<vector<int>>&dp){
        if(sum==0){
            return true;
            
        } 
        if(sum<0 || i==n){
            return false;
            
            
        } 
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum]= solve(i+1,nums,sum-nums[i],n,dp) || solve(i+1,nums,sum,n,dp);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int target=0;
        
        for(int i=0;i<n;i++){
            target +=nums[i];
        }
        if(target%2!=0) return false;
        int sum=target/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(0,nums,sum,n,dp);
    }
};