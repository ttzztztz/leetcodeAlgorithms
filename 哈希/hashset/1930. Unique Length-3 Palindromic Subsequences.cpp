class Solution {
public:
    int countPalindromicSubsequence(string s) {
        const int inf = numeric_limits<int>::max() / 2, n = s.size();
        vector<int> mi(26, inf), ma(26, -inf);
        
        for (int i = 0; i < n; i++) {
            const int d = s[i] - 'a';
            
            mi[d] = min(mi[d], i);
            ma[d] = max(ma[d], i);
        }
        
        int ans = 0;
        for (int head = 0; head < 26; head++) {
            unordered_set<char> cur;
            for (int i = mi[head] + 1; i <= ma[head] - 1; i++) cur.insert(s[i]);
            ans += cur.size();
        }
        return ans;
    }
};