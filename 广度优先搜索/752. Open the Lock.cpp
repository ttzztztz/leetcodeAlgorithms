class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.count(target) || visited.count("0000")) return -1;
        
        deque<string> q = { "0000" };
        int ans = 0;
        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                const string u = q.front();
                q.pop_front();
                if (u == target) return ans;
                
                for (int x = 0; x < 4; x++) {
                    const int d = u[x] - '0';
                    const int prev = (d - 1 + 10) % 10;
                    const int next = (d + 1) % 10;
                    
                    string a1 = u;
                    a1[x] = '0' + prev;
                    if (!visited.count(a1)) {
                        visited.insert(a1);
                        if (a1 == target) return ans + 1;
                        q.push_back(a1);
                    }
                    
                    string a2 = u;
                    a2[x] = '0' + next;
                    if (!visited.count(a2)) {
                        visited.insert(a2);
                        if (a2 == target) return ans + 1;
                        q.push_back(a2);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};