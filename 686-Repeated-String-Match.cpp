class Solution {
public:
    bool check(string a,string b){
        for(int i=0;i+b.size()<=a.size();i++){
            int j=0;
            while(j<b.size() && a[i+j]==b[j]){
                j++;
            }
            if(j==b.size()) return true;            
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int count=0;
        string temp = "";
        while(temp.size()<b.size()){
            temp+=a;
            count++;
        }
        if(check(temp,b)) return count;
        temp+=a;
        count++;
        if(check(temp,b)) return count;
        return -1;        
    }
};