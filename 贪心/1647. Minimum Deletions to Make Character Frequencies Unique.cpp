class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> appear;
        for (const char ch : s) appear[ch]++;
        
        vector<int> all;
        for (auto& [k, v] : appear) all.push_back(v);
        sort(all.begin(), all.end());
        
        int ans = 0;
        for (int i = all.size() - 1, last = s.size() + 5; i >= 0; i--) {
            int t = max(0, min(last - 1, all[i]));
            ans += all[i] - t;
            last = t;
        }
        return ans;
    }
};