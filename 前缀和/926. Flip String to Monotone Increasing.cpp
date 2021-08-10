class Solution {
public:
    int minFlipsMonoIncr(string s) {
        init(s);
        const int n = s.size();
        int ans = n;
        for (int i = -1; i < n; i++) {
            // [0...i]    -> 0
            // [i + 1, n] -> 1
            
            ans = min(ans, sum(0, i, 1) + sum(i + 1, n - 1, 0));
        }
        return ans;
    }
private:
    vector<int> pref;
    
    void init(const string& s) {
        const int n = s.size();
        pref = vector<int>(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0) pref[i] = pref[i - 1];
            pref[i] += (s[i] == '0');
        }
    }
    
    int sum(int l, int r, int num) {
        if (l > r) return 0;
        int ans = pref[r];
        if (l - 1 >= 0) ans -= pref[l - 1];
        
        if (num == 1) ans = (r - l + 1) - ans;
        return ans;
    }
};