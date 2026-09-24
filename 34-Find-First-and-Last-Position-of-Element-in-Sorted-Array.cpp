class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         int n = nums.size();
         int first=-1;
         int last=-1;
         int l=0;
         int r=n-1;
         while(l<=r){
            int mid = l+(r-l)/2;
            if(target==nums[mid]){
                first=mid;
                r=mid-1;
            }else if(target<nums[mid]){
                r=mid-1;
            }else{
                l=mid+1;
            }
         }
         l=0;
         r=n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(target==nums[mid]){
                last=mid;
                l=mid+1;
            }else if(target<nums[mid]){
                r=mid-1;
            }else{
                l=mid+1;
            }
            
        }
        return {first,last};
        
    }
};