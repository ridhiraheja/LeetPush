class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int i=0,j=n;
        int sum=0;
        while(i<j){
            j-=2;
            sum+=piles[j];
            i++;


        }
        return sum;
        
    }
};