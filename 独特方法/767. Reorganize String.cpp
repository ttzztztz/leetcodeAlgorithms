class Solution {
public:
    string reorganizeString(string str) {
        if (str.empty()) return "";
        const int n = str.size();
        unordered_map<char, int> appear;
        
        int mx = 0;
        char mx_letter = '\0';
        for (auto& ch : str) {
            appear[ch]++;
            if (appear[ch] > mx) {
                mx = appear[ch];
                mx_letter = ch;
            }
        }
        
        string ans(n, ' ');
        int idx = 0;
        if (mx > (n + 1) / 2) return "";
        while (mx) {
            ans[idx] = mx_letter;
            idx += 2;
            mx--;
        }
        
        for (auto [k, v] : appear) {
            if (k == mx_letter) continue;
            
            while (v) {
                if (idx >= n) idx = 1;
                
                ans[idx] = k;
                idx += 2;
                v--;
            }
        }
        return ans;
    }
};
