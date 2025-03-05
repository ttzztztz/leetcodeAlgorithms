class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cur, target;
        for (const char ch : t) target[ch]++;

        int ans_l = -1, ans_r = -1;
        for (int l = 0, r = 0; r < s.size(); r++) {
            cur[s[r]]++;
            while (judge(cur, target)) {
                if (ans_l == -1 || (r - l < ans_r - ans_l)) {
                    ans_l = l, ans_r = r;
                }

                cur[s[l]]--;
                if (cur[s[l]] == 0) cur.erase(s[l]);
                l++;
            }
        }

        if (ans_l == -1) return "";
        string ans;
        for (int i = ans_l; i <= ans_r; i++) ans += s[i];
        return ans;
    }
private:
    bool judge(unordered_map<char, int>& cur, unordered_map<char, int>& target) {
        for (auto& [ch, cnt] : target) {
            if (!cur.count(ch) || cur[ch] < cnt) return false;
        }
        return true;
    }
};