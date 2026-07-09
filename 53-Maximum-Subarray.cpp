class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0){
                sum=0;
            }
        }

    return maxi;    
    }
};
//subarr is a part of arr it must be continuous and order must be maintained eg -3,4,-1
//-2,3,4 like this which is not continuous is sub sequence  
//the whole arr can also be a sub array