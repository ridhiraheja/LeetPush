class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int effort = curr[0];
            int x = curr[1];
            int y = curr[2];

            if(x == m - 1 && y == n - 1) return effort;

            if(effort > dist[x][y]) continue;

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int newEffort = max(effort, abs(heights[x][y] - heights[nx][ny]));

                    if(newEffort < dist[nx][ny]) {
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort, nx, ny});
                    }
                }
            }
        }

        return 0;
    }
};