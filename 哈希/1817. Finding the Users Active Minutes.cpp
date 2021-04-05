class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k, 0);
        unordered_set<string> used;
        unordered_map<int, int> a;
        
        for (auto& log : logs) {
            const int id = log[0], t = log[1];
            string h = hash(id, t);
            if (used.count(h)) continue;
            
            used.insert(h);
            a[id]++;
        }
        
        for (auto& [key, v] : a) {
            if (v - 1 < k) ans[v - 1]++;
        }
        return ans;
    }
private:
    string hash(int i, int j) {
        return to_string(i) + "," + to_string(j);
    }
};
