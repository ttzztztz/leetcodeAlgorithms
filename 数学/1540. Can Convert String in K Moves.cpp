class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        const int N = s.size(), M = t.size();
        if (N != M) return false;
        
        unordered_map<int, int> f;
        int mx = 0, mxn = 0;
        for (int i = 0; i < N; i++) {
            const int delta = (t[i] - s[i] + 26) % 26;
            if (delta == 0) continue;
            f[delta]++;
            
            if (f[delta] > mx) {
                mx = max(mx, f[delta]);
                mxn = delta;
            } else if (f[delta] == mx) {
                mxn = max(mxn, delta);
            }
        }
        
        int tmp = (mx - 1) * 26 + mxn;
        return tmp <= k;
    }
};
