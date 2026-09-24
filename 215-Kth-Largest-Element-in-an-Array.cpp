class Solution {
public:
    int partition(vector<int>&nums,int l,int r){
        int i=l+1;
        int j=r;
        int p=nums[l];
        while(i<=j){
            while(i<=r && nums[i]<=p) {
                i++;
            }
            while(j>=l && nums[j]>p) {
                j--;
            }
            if(i<j) {
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[l],nums[j]);
        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int target = n-k;
        while(true){
            int pivot=partition(nums,l,r);
            if(pivot==target) return nums[pivot];
            else if(pivot>target) r=pivot-1;
            else l=pivot+1;
        }
        
    }
};


























