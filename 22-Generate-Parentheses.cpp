class Solution {
public:
    bool isValid(string str){
        int count=0;
        for(char &ch:str){
            if(ch=='('){
                count++;

            }else{
                count--;
            }
            if(count<0){
                return false;
            }

        }
        return count==0;
    }
    void solve(int n,string str,vector<string>&result){
        if(str.size()==2*n){
            if(isValid(str)){
                result.push_back(str);
            }
            return;
        }
        str.push_back('(');
        solve(n,str,result);
        str.pop_back();
        str.push_back(')');
        solve(n,str,result);
        str.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string str="";
        solve(n,str,result);
        return result;


        
    }
};