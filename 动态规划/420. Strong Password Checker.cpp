int f[51][66][21][5][2][2][2];

class Solution {
public:
    int strongPasswordChecker(string password) {
        this->pwd = password;
        init();
        
        return dfs(0, cnt - 1, 0, 0, 0, 0, 0);
    }
private:
    string pwd;
    unordered_map<char, int> char_to_idx;
    int cnt = 0;
    
    void init() {
        memset(f, 0xff, sizeof f);
        
        for (int i = 0; i < 26; i++) {
            char_to_idx['a' + i] = cnt++;
            char_to_idx['A' + i] = cnt++;
        }
        
        for (int i = 0; i <= 9; i++) {
            char_to_idx['0' + i] = cnt++;
        }
        
        char_to_idx['.'] = cnt++;
        char_to_idx['!'] = cnt++;
    }
    
    int dfs(int idx, int last, int len, int repeat, int lower_case, int upper_case, int digit) {
        if (len > 20) {
            return pwd.size() + 100;
        }
        if (repeat >= 3) {
            return pwd.size() + 100;
        }
        if (idx >= pwd.size()) {
            if (lower_case && upper_case && digit && len >= 6) return 0;
            else return pwd.size() + 100;
        }
        
        int& val = f[idx][last][len][repeat][lower_case][upper_case][digit];
        if (val != -1) return val;
        
        int ans = pwd.size() + 100;
        for (auto& [ch, id] : char_to_idx) {
            // insert
            ans = min(ans, 1 + dfs(idx, id, len + 1, last == id ? repeat + 1 : 1, lower_case || ('a' <= ch && ch <= 'z'), upper_case || ('A' <= ch && ch <= 'Z'), digit || ('0' <= ch && ch <= '9')));
            // replace
            ans = min(ans, 1 + dfs(idx + 1, id, len + 1, last == id ? repeat : 1, lower_case || ('a' <= ch && ch <= 'z'), upper_case || ('A' <= ch && ch <= 'Z'), digit || ('0' <= ch && ch <= '9')));
        }
        // delete
        ans = min(ans, 1 + dfs(idx + 1, last, len, repeat, lower_case, upper_case, digit));
        
        // keep
        ans = min(ans, dfs(idx + 1, char_to_idx[pwd[idx]], len + 1, last == char_to_idx[pwd[idx]] ? repeat + 1 : 1, lower_case || ('a' <= pwd[idx] && pwd[idx] <= 'z'), upper_case || ('A' <= pwd[idx] && pwd[idx] <= 'Z'), digit || ('0' <= pwd[idx] && pwd[idx] <= '9')));
        
        return val = ans;
    }
};
