class Solution {
public:
    /**
     * @param words: the list of word.
     * @return: the length of the longest string chain.
     */
    int longestStrChain(vector<string> &words) {
        for (const string& w : words) {
            const int len = w.size();
            if (all.size() <= len) all.resize(len + 1);
            all[len].push_back(w);
        }
        
        memset(f, 0xff, sizeof f);
        int answer = 0;
        for (int len = 1; len < all.size(); len++) {
            for (int i = 0; i < all[len].size(); i++) {
                answer = max(answer, 1 + dfs(len + 1, i));
            }
        }
        return answer;
    }
private:
    vector<vector<string>> all;
    bool check(const string& s, const string& l) {
        const int len1 = s.size(), len2 = l.size();
        if (len1 + 1 != len2) return false;
        
        for (int ptr1 = 0, ptr2 = 0, used = 0; ptr2 < len2; ptr2++) {
            if (s[ptr1] == l[ptr2]) ptr1++;
            else {
                if (used) return false;
                else used = true;
            }
        }
        
        return true;
    }
    int f[1005][1005];
    int dfs(int len, int last) {
        if (len >= all.size()) return 0;
        int& val = f[len][last];
        if (val != -1) return val;
        
        const string& lst = all[len - 1][last];
        int answer = 0;
        for (int i = 0; i < all[len].size(); i++) {
            if (!check(lst, all[len][i])) continue;
            answer = max(answer, 1 + dfs(len + 1, i));
        }
        return val = answer;
    }
};
