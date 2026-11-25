class Solution {
public:
    vector<int> parent, size;

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if(pa == pb) return false;

        if(size[pa] < size[pb])
            swap(pa, pb);

        parent[pb] = pa;
        size[pa] += size[pb];

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        size.assign(n + 1, 1);

        for(int i = 1; i <= n; i++)
            parent[i] = i;

        for(auto &e : edges) {
            if(!unite(e[0], e[1]))
                return e;
        }

        return {};
    }
};