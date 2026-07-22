#include <cmath>
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(int x:gifts){
            pq.push(x);
        }
        long long sum=0;
        while(k>0){
            pq.push(sqrt(pq.top()));
            pq.pop();
            k--;

        }
        while(pq.size()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};