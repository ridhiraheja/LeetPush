class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int len=1;len<=n/2;len++){
            if(n%len!=0) continue;
            bool possible=true;
            for(int i=len;i<n;i++){
                if(s[i]!=s[i%len]){
                    possible=false;
                    break;
                }
            }
            if(possible) return true;            
        }
        return false;        
    }
};