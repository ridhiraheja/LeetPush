class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int i=0,j=0;
        int maxvow=0;
        int vow=0;
        while(j<s.length()){
            if(isVowel(s[j])) vow++;
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                maxvow=max(maxvow,vow);
                if(isVowel(s[i])) vow--;
                i++;
                j++;
            }
        }
        return maxvow;
        


        
    }
};