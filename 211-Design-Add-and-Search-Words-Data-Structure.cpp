
class WordDictionary {
    struct Node {
        Node* child[26];
        bool end;
        Node() {
            memset(child,0,sizeof(child));
            end=false;
        }
    };
    Node* root;

    bool searchWord(string &word,int i,Node* node) {
        if(i==word.size()) return node->end;
        if(word[i]=='.') {
            for(int j=0;j<26;j++) {
                if(node->child[j] && searchWord(word,i+1,node->child[j]))
                    return true;
            }
            return false;
        }
        int x=word[i]-'a';
        return node->child[x] && searchWord(word,i+1,node->child[x]);
    }

public:
    WordDictionary() {
        root=new Node();
    }

    void addWord(string word) {
        Node* node=root;
        for(char c:word) {
            int x=c-'a';
            if(!node->child[x]) node->child[x]=new Node();
            node=node->child[x];
        }
        node->end=true;
    }

    bool search(string word) {
        return searchWord(word,0,root);
    }
};
