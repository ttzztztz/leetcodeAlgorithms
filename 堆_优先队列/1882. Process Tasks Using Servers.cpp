class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        const int n = servers.size(), m = tasks.size();
        vector<int> ans(m);
        typedef tuple<int, int, int> State;
        
        priority_queue<State, vector<State>, greater<>> free_heap, busy_heap;
        for (int i = 0; i < n; i++) free_heap.emplace(0, servers[i], i);
        for (int i = 0, cur_time = 0; i < m; i++) {
            cur_time = max(cur_time, i);
            while (!busy_heap.empty() && get<0>(busy_heap.top()) <= cur_time) {
                auto [free_time, weight, idx] = busy_heap.top();
                busy_heap.pop();
                
                free_heap.emplace(0, weight, idx);
            }
            
            if (!free_heap.empty()) {
                auto [free_time, weight, idx] = free_heap.top();
                free_heap.pop();
                
                ans[i] = idx;
                busy_heap.emplace(cur_time + tasks[i], weight, idx);
            } else {
                cur_time = get<0>(busy_heap.top());
                while (!busy_heap.empty() && get<0>(busy_heap.top()) == cur_time) {
                    auto [free_time, weight, idx] = busy_heap.top();
                    busy_heap.pop();
                    
                    free_heap.emplace(0, weight, idx);
                    cur_time = max(cur_time, free_time);
                }
                
                auto [free_time, weight, idx] = free_heap.top();
                free_heap.pop();
                
                ans[i] = idx;
                busy_heap.emplace(cur_time + tasks[i], weight, idx);
            }
        }
        return ans;
    }
};