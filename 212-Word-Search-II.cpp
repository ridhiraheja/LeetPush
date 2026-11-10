
class Solution {
    struct Node {
        Node* child[26];
        string word;
        Node() {
            memset(child,0,sizeof(child));
            word="";
        }
    };

    Node* root=new Node();
    vector<string> ans;
    int m,n;

    void dfs(vector<vector<char>>& board,int i,int j,Node* node) {
        char c=board[i][j];
        if(c=='#' || !node->child[c-'a']) return;

        node=node->child[c-'a'];

        if(node->word!="") {
            ans.push_back(node->word);
            node->word="";
        }

        board[i][j]='#';

        if(i>0) dfs(board,i-1,j,node);
        if(j>0) dfs(board,i,j-1,node);
        if(i<m-1) dfs(board,i+1,j,node);
        if(j<n-1) dfs(board,i,j+1,node);

        board[i][j]=c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m=board.size();
        n=board[0].size();

        for(string& w:words) {
            Node* node=root;
            for(char c:w) {
                int x=c-'a';
                if(!node->child[x]) node->child[x]=new Node();
                node=node->child[x];
            }
            node->word=w;
        }

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                dfs(board,i,j,root);
            }
        }

        return ans;
    }
};
