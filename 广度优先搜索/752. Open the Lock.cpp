class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;

        unordered_set<string> visited = { "0000" };

        deque<string> q = { "0000" };
        int ans = 0;
        while (!q.empty()) {
            const int n = q.size();
            for (int i = 0; i < n; i++) {
                string u = q.front();
                q.pop_front();

                if (u == target) return ans;
                for (string& v : next_state(u, visited, dead)) {
                    if (v == target) return ans + 1;
                    q.push_back(v);
                    visited.insert(v);
                }
            }
            ans++;
        }
        return -1;
    }
private:
    vector<string> next_state(const string& s, const unordered_set<string>& visited, const unordered_set<string>& dead) {
        vector<string> ans;
        for (int i = 0; i < 4; i++) {
            const int d = s[i] - '0';
            string s1 = s;
            s1[i] = '0' + ((d + 1) % 10);
            if (!visited.count(s1) && !dead.count(s1)) ans.push_back(s1);

            string s2 = s;
            s2[i] = '0' + ((d - 1 + 10) % 10);
            if (!visited.count(s2) && !dead.count(s2)) ans.push_back(s2);
        }

        return ans;
    }
};