class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        const int n = a.size();
        
        if (isP(a)) return true;
        if (isP(b)) return true;
        this->a = a, this->b = b;
        
        return dfs(0, n - 1, 0, 1) || dfs(0, n - 1, 1, 0);
    }
private:
    string a, b;
    bool dfs(int i, int j, int v1, int v2) {
        if (i >= j) return true;
        const string& s1 = v1 == 0 ? a : b;
        const string& rev_s1 = v1 == 0 ? b : a;
        const string& s2 = v2 == 0 ? a : b;
        const string& rev_s2 = v2 == 0 ? b : a;
        
        if (s1[i] == s2[j]) return dfs(i + 1, j - 1, v1, v2);
        else {
            if (a == b) return false;
            if (rev_s1[i] == s2[j] && dfs(i, j, v1 ^ 1, v2)) return true;
            if (rev_s2[j] == s1[i] && dfs(i, j, v1, v2 ^ 1)) return true;
        }
        return false;
    }
    bool isP(const string& str) {
        const int n = str.size();
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (str[i] != str[j]) return false;
        }
        return true;
    }
};