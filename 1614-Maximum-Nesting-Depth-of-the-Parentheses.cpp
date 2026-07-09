class Solution {
public:
    int maxDepth(string s) {
        int result=0;
        int openBrackets=0;
        for(char &ch:s){
            if(ch=='('){
                openBrackets++;
                result=max(result,openBrackets);
            }else if(ch==')'){
                openBrackets--;
            }
        }
        return result;
        
    }
};