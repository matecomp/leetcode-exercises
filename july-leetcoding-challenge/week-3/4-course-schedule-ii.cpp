class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);
        vector<int> ans;
        
        for (int i=0; i<prerequisites.size(); i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        
        for (int i=0; i<degree.size(); i++) {
            if (degree[i] == 0) q.push(i);
        }
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            degree[cur] = -1;
            ans.push_back(cur);
            for (int i=0; i<graph[cur].size(); i++) {
                int next = graph[cur][i];
                
                if (degree[next]) degree[next]--;
                if (degree[next] == 0) q.push(next);
            }
        }
        
        if (ans.size() == numCourses) return ans;
        return vector<int>();
    }
};