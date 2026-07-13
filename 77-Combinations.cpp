class Solution {
public:
    void solve(int start, int n, int k, vector<int>& temp, vector<vector<int>>& result) {
        if (k == 0) {
            result.push_back(temp);
            return;
        }

        if (start > n) {
            return;
        }

    // Include the current number
        temp.push_back(start);
        solve(start + 1, n, k - 1, temp, result);
        temp.pop_back();

    // Exclude the current number
        solve(start + 1, n, k, temp, result);
}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;

        solve(1, n, k, temp, result);

        return result;
        
    }
};