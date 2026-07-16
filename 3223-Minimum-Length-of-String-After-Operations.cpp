class Solution {
public:
    int minimumLength(string s) {
        vector<int>freq(26,0);
        for(auto &ch:s){
            freq[ch-'a']++;
        }
        int cnt=0;
        for(int &it:freq){
            if(it>0){
                if(it%2==0){
                    cnt+=2;
                }else{
                    cnt+=1;
                }
            }

        }
        return cnt;
        
    }
};