class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int total=0;
        
        int i=0;
        int cnt=0;
        while(i<costs.size()){
            total+=costs[i];
            if(total<=coins){
                i++;
                cnt++;

            }else{
                break;
            }

        }
        return cnt;
        
    }
};