class Solution {
public:
    bool isTransformable(string s, string t) {
        if (s == t) return true;
        unordered_map<int, int> a, b;
        for (const char ch : s) a[ch - '0']++;
        for (const char ch : t) b[ch - '0']++;
        if (a != b) return false;
        
        const int n = s.size();
        vector<int> idx[10];
        vector<int> pos(10, 0);
        for (int i = 0; i < n; i++) {
            idx[s[i] - '0'].push_back(i);
        }
        
        for (int i = 0; i < n; i++) {
            const int d = t[i] - '0';
            
            for (int k = 0; k < d; k++) {
                if (pos[k] < idx[k].size() && idx[k][pos[k]] < idx[d][pos[d]]) return false;
            }
            pos[d]++;
        }
        return true;
    }
};
