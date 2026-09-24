class Solution {
public:
    int count=0;
    void merge(vector<long long>&prefix,int l,int mid,int r,int lower, int upper){
        int low=mid+1;
        int high=mid+1;
        for(int i=l;i<=mid;i++){
            while(low<=r && prefix[low]<prefix[i]+lower){
                low++;
            }
            while(high<=r && prefix[high]<=prefix[i]+upper){
                high++;
            }
            count+=high-low;
        }
        int i=l;
        int j=mid+1;
        vector<long long>temp;
        while(i<=mid && j<=r){
            if(prefix[i]<=prefix[j]){
                temp.push_back(prefix[i]);
                i++;
            }else{
                temp.push_back(prefix[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(prefix[i]);
                i++;

        }
        while(j<=r){
            temp.push_back(prefix[j]);
                j++;

        }
        for(int k=0;k<temp.size();k++){
            prefix[l+k]=temp[k];
        }
    }
    void mergeSort(vector<long long>&prefix,int l,int r,int lower, int upper){
        if(l>=r) return;
        int mid=l+(r-l)/2;
        mergeSort(prefix,l,mid,lower,upper);
        mergeSort(prefix,mid+1,r,lower,upper);
        merge(prefix,l,mid,r,lower,upper);


    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        vector<long long>prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        count=0;
        mergeSort(prefix,0,n,lower,upper);
        return count;
        
    }
};