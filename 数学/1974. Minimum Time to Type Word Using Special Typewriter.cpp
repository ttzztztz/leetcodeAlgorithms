class Solution {
public:
    int minTimeToType(string word) {
        int ans = 0;
        const int n = word.size();
        
        char cur = 'a';
        for (const char ch : word) {
            int d1 = min(cur - 'a', ch - 'a');
            int d2 = max(cur - 'a', ch - 'a');
            
            ans += min(d2 - d1, d1 + 26 - d2);
            cur = ch;
        }
        return ans + n;
    }
};