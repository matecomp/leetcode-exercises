class Solution {
public:
    void dfs(vector<vector<int>>&allPaths, vector<vector<int>>& graph, int idx, vector<int> path, vector<int>& vis) {
        if (idx == graph.size() - 1) {
            path.push_back(idx);
            allPaths.push_back(path);
            return;
        }
        
        if (vis[idx]) return;
        
        vis[idx] = 1;
        path.push_back(idx);
        for (int i=0; i<graph[idx].size(); i++) {
            int next_idx = graph[idx][i];
            dfs(allPaths, graph, next_idx, path, vis);
        }
        vis[idx] = 0;
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), 0);
        vector<vector<int>> allPaths;
        
        dfs(allPaths, graph, 0, vector<int>(), vis);
        
        return allPaths;
    }
};