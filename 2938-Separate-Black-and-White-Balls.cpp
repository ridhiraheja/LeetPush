class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        long long ans=0;
        while(i<j){
            if(i<j && s[i]=='0'){
                i++;
            }else if(i<j && s[j]=='1'){
                j--;
            }else{
                ans+=(j-i);
                i++;
                j--;
            }
        }
        return ans;

        
    }
};