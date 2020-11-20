class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if (edges.size() == 0) {
            ans.push_back(0);
            return ans;
        }
        
        vector<vector<int>> graph(n, vector<int>());
        vector<int> vis(n, 0);
        vector<int> dist(n, 0);
        vector<int> dist2(n, 0);
        
        for (int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        queue<pair<int,int> > q;
        vis[0] = 1;
        q.push({0,0});
        
        while (!q.empty()) {
            int u = q.front().first;
            int step = q.front().second;
            q.pop();
            
            for (int i=0; i<graph[u].size(); i++) {
                int v = graph[u][i];
                if (vis[v] == 0) {
                    vis[v] = 1;
                    dist[v] = step + 1;
                    q.push({v,dist[v]});
                }
            }
        }
        
        int longest_node = 0;
        int max_path = 0;
        for (int i=0; i<n; i++) {
            if (dist[i] >= max_path) {
                max_path  = dist[i];
                longest_node = i;
            }
        }
        
        q.push({longest_node,0});
        for (int i=0; i<n; i++) {
            vis[i] = 0;
            dist[i] = 0;
        }
        
        vis[longest_node] = 1;
        
        while (!q.empty()) {
            int u = q.front().first;
            int step = q.front().second;
            q.pop();
            
            for (int i=0; i<graph[u].size(); i++) {
                int v = graph[u][i];
                if (vis[v] == 0) {
                    vis[v] = 1;
                    dist[v] = step + 1;
                    q.push({v,dist[v]});
                }
            }
        }
        
        max_path = 0;
        longest_node = 0;
        for (int i=0; i<n; i++) {
            if (dist[i] >= max_path) {
                max_path  = dist[i];
                longest_node = i;
            }
        }
        
        q.push({longest_node,0});
        for (int i=0; i<n; i++) {
            vis[i] = 0;
        }
        
        vis[longest_node] = 1;
        
        while (!q.empty()) {
            int u = q.front().first;
            int step = q.front().second;
            q.pop();
            
            for (int i=0; i<graph[u].size(); i++) {
                int v = graph[u][i];
                if (vis[v] == 0) {
                    vis[v] = 1;
                    dist2[v] = step + 1;
                    q.push({v,dist2[v]});
                }
            }
        }
        
        max_path = 0;
        for (int i=0; i<n; i++) max_path = max(dist[i],max_path);

        int d = (max_path+1)/2;

        for (int i=0; i<n; i++) {
            if (dist[i] == d && dist2[i] == d) ans.push_back(i);
            else if (dist[i] == d-1 && dist2[i] == d) ans.push_back(i);
            else if (dist[i] == d && dist2[i] == d-1) ans.push_back(i);
        }
        
        return ans;
    }
};