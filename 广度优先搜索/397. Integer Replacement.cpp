class Solution {
public:
    int integerReplacement(int n) {
        int ans = 0;
        
        typedef unsigned long long ull;
        
        deque<ull> q = { (ull) n };
        unordered_set<ull> visited;
        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                const ull t = q.front();
                q.pop_front();
                if (t == 1) return ans;
                
                visited.insert(t);
                if (t % 2 == 0) {
                    if (!visited.count(t / 2)) {
                        q.push_back(t / 2);
                        visited.insert(t / 2);
                    }
                } else {
                    if (!visited.count(t - 1)) {
                        q.push_back(t - 1);
                        visited.insert(t - 1);
                    }
                    
                    if (!visited.count(t + 1)) {
                        q.push_back(t + 1);
                        visited.insert(t + 1);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
