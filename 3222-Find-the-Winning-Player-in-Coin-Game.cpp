class Solution {
public:
    string winningPlayer(int x, int y) {
        int turn=0;
        while(x>=1 && y>=4){
            x-=1;
            y-=4;
            turn++;
        }
        if(turn&1){
            return "Alice";
        }
        return "Bob";
        
    }
};