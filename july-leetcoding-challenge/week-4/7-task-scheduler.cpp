class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> q;
        priority_queue<pair<int,char>> waiting;
        unordered_map<char,int> freq;
        
        for (int i=0; i<tasks.size(); i++) freq[tasks[i]]++;
        for (unordered_map<char,int>::iterator it=freq.begin(); it!=freq.end(); ++it) {
            q.push({it->second, it->first});
        }
        
        int time = 0;
        while(!q.empty() || !waiting.empty()) {    

            if (!q.empty()) {
                pair<int, char> current_task = q.top();
                
                char task_letter = current_task.second;
                freq[task_letter]--;
                
                if (freq[task_letter]) {
                    waiting.push({-(time+n), task_letter});
                }
                
                q.pop();
            }
            
            if (!waiting.empty()) {
                pair<int, char> waiting_task = waiting.top();
                
                if (-waiting_task.first <= time) {
                    char task_letter = waiting_task.second;
                    int quantity = freq[task_letter];
                    q.push({quantity, task_letter});
                    waiting.pop();
                }
            }
            
            time++;
        }
        
        return time;
    }
};