class Solution {
public:
    int partition(vector<int>&nums,int l,int r){
        int i=l+1;
        int j=r;
        int p=nums[l];
        while(i<=j){
            while(i<=r && nums[i]<=p){
                i++;
            }
            while(j>=l && nums[j]>p){
                j--;
            }
            if(i<j){
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[l],nums[j]);
        return j;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>nums;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                nums.push_back(matrix[i][j]);
            }
        }
        int l=0;
        int r=nums.size()-1;
        int pivot=0;
        while(true){
            pivot=partition(nums,l,r);
            if(pivot==k-1) return nums[pivot];
            else if(pivot>k-1) r=pivot-1;
            else l=pivot+1;
        }
        return nums[pivot];
        
    }
};


























