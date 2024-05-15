class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        // Initialize all thief positions
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    dist[r][c] = 0;
                }
            }
        }

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        // Multi-source BFS to calculate minimum distance to any thief
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i=0;i<4;i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == INT_MAX) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // Use priority queue to find path with maximum safeness factor
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({dist[0][0], {0, 0}});
        vector<vector<int>> maxSafeness(n, vector<int>(n, -1));
        maxSafeness[0][0] = dist[0][0];

        while (!pq.empty()) {
            auto [d, pos] = pq.top();
            pq.pop();
            int r = pos.first, c = pos.second;
            if (r == n - 1 && c == n - 1) return d;  // Reached bottom-right corner

            for (int i=0;i<4;i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int newSafe = min(d, dist[nr][nc]);
                    if (newSafe > maxSafeness[nr][nc]) {
                        maxSafeness[nr][nc] = newSafe;
                        pq.push({newSafe, {nr, nc}});
                    }
                }
            }
        }

        return -1; 
    }
};