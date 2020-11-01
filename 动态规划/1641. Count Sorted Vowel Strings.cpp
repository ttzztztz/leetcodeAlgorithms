class Solution {
public:
    int countVowelStrings(int n) {
        this->n = n;
        memset(f, 0xff, sizeof f);
        return dfs(0, 0);
    }
private:
    vector<int> all = {'a','e','i','o','u'};
    int f[55][6];
    int n;
    int dfs(int idx, int last) {
        if (idx == n) return 1;
        int& val = f[idx][last];
        if (val != -1) return val;
        
        int ans = 0;
        for (int k = last; k < all.size(); k++) {
            ans += dfs(idx + 1, k);
        }
        return val = ans;
    }
};
