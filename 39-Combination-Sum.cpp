class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;
    void find(int i,int curr,vector<int> &candidates,int target){
        if(curr>target) return;
        if(i>=candidates.size()){
            if(curr==target) ans.push_back(temp);
            return;
        }
        find(i+1,curr,candidates,target);
        temp.push_back(candidates[i]);
        find(i,curr+candidates[i],candidates,target);
        temp.pop_back();
        return;
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        find(0,0,candidates,target);
        return ans;

        
    }
};