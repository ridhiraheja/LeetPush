class Solution {
public:
    int count=0;
    void merge(vector<int>&nums,int l,int mid,int r){
        int j=mid+1;
        for(int i=l;i<=mid;i++){
            while(j<=r && (long long)nums[i]>2LL*nums[j]){
                j++;
            }
            count+=j-(mid+1);
        }
        int i=l;
        j=mid+1;
        vector<int>temp;
        while(i<=mid && j<=r){
            if(nums[i]<=nums[j]){               
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }            
        }  
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }   
        while(j<=r){
            temp.push_back(nums[j]);
            j++;
        }            
        for(int k=0;k<temp.size();k++){
            nums[l+k]=temp[k];
        }       
    }
    void mergeSort(vector<int>&nums,int l,int r){
        if(l>=r) return;
        int mid = l+(r-l)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        merge(nums,l,mid,r);
    }
    
    int reversePairs(vector<int>& nums) {
        count=0;
        mergeSort(nums,0,nums.size()-1);
        return count;
        
    }
};
