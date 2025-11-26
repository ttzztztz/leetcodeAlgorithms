class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        unordered_map<char, int> cur, target;
        for (const char ch : p) target[ch]++;

        const int n = s.size(), m = p.size();
        for (int i = 0; i < n; i++) {
            cur[s[i]]++;

            if (i >= m) {
                cur[s[i - m]]--;
                if (cur[s[i - m]] == 0) cur.erase(s[i - m]);
            }

            if (cur == target) ans.push_back(i - m + 1);
        }

        return ans;
    }
};