class Solution {
public:
    /**
     * @param colors: the colors of grids
     * @return: return the minimum step from position 0 to position n - 1
     */
    int minimumStep(vector<int> &arr) {
        int answer = 0;
        const int N = arr.size();
        vector<bool> visited(N, false);
        
        unordered_map<int, vector<int>> hashmap;
        for (int i = 0; i < N; i++) hashmap[arr[i]].push_back(i);
        
        deque<int> queue;
        queue.push_back(0);
        while (!queue.empty()) {
            const int M = queue.size();
            for (int _ = 0; _ < M; _++) {
                const int u = queue.front();
                
                queue.pop_front();
                visited[u] = true;

                if (u == N - 1) return answer;
                
                if (u - 1 >= 0 && !visited[u - 1]) {
                    visited[u - 1] = true;
                    queue.push_back(u - 1);
                }
                if (u + 1 < N && !visited[u + 1]) {
                    visited[u + 1] = true;
                    queue.push_back(u + 1);
                }
                
                for (int v : hashmap[arr[u]]) {
                    if (v == u || visited[v]) continue;
                    
                    visited[v] = true;
                    queue.push_back(v);
                }
                hashmap[arr[u]].clear();
            }
            answer++;
        }
        
        return answer;
    }
};
