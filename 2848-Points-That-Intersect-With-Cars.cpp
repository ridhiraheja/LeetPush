class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int>covered(101,0);
        for(auto car:nums){
            for(int i=car[0];i<=car[1];i++){
                covered[i]=1;

            }
            
        }
        int count=0;
        for(int i=1;i<101;i++){
            if(covered[i]){
                count++;
            }
        }
        return count;
    }
};