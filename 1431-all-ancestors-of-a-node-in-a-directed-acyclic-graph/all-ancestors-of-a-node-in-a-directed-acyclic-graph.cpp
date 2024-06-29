class Solution {
public:
    void dfs(vector<vector<int>> &adj, int i, int j, vector<vector<int>> &ans, vector<bool> &vis) {
        vis[j] = true;
        for (auto &x : adj[j]) {
            if (!vis[x]) {
                ans[x].push_back(i);
                dfs(adj, i, x, ans, vis);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n), adj(n);
        for (auto &v : edges) {
            adj[v[0]].push_back(v[1]);
        }
        for (int i = 0; i < n; i++) {
            vector<bool> vis(n);
            dfs(adj, i, i, ans, vis);
        }
        return ans;
    }
};