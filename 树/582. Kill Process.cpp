class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        const size_t n = pid.size();
        for (int i = 0; i < n; i++) {
            graph[ppid[i]].push_back(pid[i]);
        }
        
        dfs(kill);
        return ans;
    }
private:
    vector<int> ans;
    unordered_map<int, vector<int>> graph;
    
    void dfs(int pid) {
        ans.push_back(pid);
        
        for (int next_pid : graph[pid]) {
            dfs(next_pid);
        }
    }
};
