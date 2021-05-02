class Solution {
public:
    bool splitString(string s) {
        str = s;
        n = str.size();
        memset(f, 0xff, sizeof f);
        return dfs(0, 21);
    }
private:
    string str;
    int n;
    typedef uint64_t ll;
    
    int f[25][25];
    bool dfs(int i, int last) {
        if (i == n) return (last != 0 && last != 21);
        
        int& val = f[i][last];
        if (val != -1) return val;
        
        ll prev = 0;
        if (last != 21) {
            try {
                prev = stoull(str.substr(last, i - last));
            } catch (std::exception e) {}
        }
        
        for (int j = i; j < n; j++) {
            try {
                ll cur = stoull(str.substr(i, j - i + 1));
                if (last == 21 || cur + 1 == prev) {
                    if (dfs(j + 1, i)) return val = true;
                }
            } catch (std::exception e) {}
        }
        return val = false;
    }
};