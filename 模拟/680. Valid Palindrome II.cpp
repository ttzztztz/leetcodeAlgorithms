class Solution {
public:
    bool validPalindrome(string s) {
        const int N = s.size();
        return dfs(s, 0, N - 1, 0);
    }
private:
    bool dfs(const string& s, int l, int r, int cnt) {
        for (; l < r;) {
            if (s[l] == s[r]) {
                l++, r--;
            } else {
                if (cnt == 1) return false;
                else return dfs(s, l + 1, r, 1) || dfs(s, l, r - 1, 1);
            }
        }
        
        return true;
    }
};
