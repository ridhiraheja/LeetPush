
class Solution {
    int cross(vector<int>& a,vector<int>& b,vector<int>& c) {
        return (b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0]);
    }

public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(),trees.end());

        vector<vector<int>> hull;

        for(auto& p:trees) {
            while(hull.size()>=2 && cross(hull[hull.size()-2],hull.back(),p)<0)
                hull.pop_back();
            hull.push_back(p);
        }

        int lower=hull.size();

        for(int i=trees.size()-2;i>=0;i--) {
            auto& p=trees[i];

            while(hull.size()>lower && cross(hull[hull.size()-2],hull.back(),p)<0)
                hull.pop_back();

            hull.push_back(p);
        }

        set<vector<int>> s(hull.begin(),hull.end());

        return vector<vector<int>>(s.begin(),s.end());
    }
};
