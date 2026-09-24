class Solution {
public:
    vector<int>count;
    void merge(vector<pair<int,int>>&nums,int l,int mid,int r){
        vector<pair<int,int>>temp;
        int i=l;
        int j=mid+1;
        while(i<=mid && j<=r){
            if(nums[i].first<=nums[j].first){
                count[nums[i].second]+=j-(mid+1);
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }            
        }  
        while(i<=mid){
            count[nums[i].second] += j - (mid + 1);
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
    void mergeSort(vector<pair<int,int>>&nums,int l,int r){
        if(l>=r) return;
        int mid = l+(r-l)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        merge(nums,l,mid,r);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>arr;
        count.resize(n,0);
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        mergeSort(arr,0,n-1);
        return count;
        
    }
};