class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        const int n = croakOfFrogs.size();
        unordered_map<char, int> last;
        
        int ans = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            const char ch = croakOfFrogs[i];
            switch (ch) {
                case 'c':
                    cur++;
                    last['c']++;
                    break;
                case 'r':
                    last['c']--;
                    if (last['c'] < 0) return -1;
                    last['r']++;
                    break;
                case 'o':
                    last['r']--;
                    if (last['r'] < 0) return -1;
                    last['o']++;
                    break;
                case 'a':
                    last['o']--;
                    if (last['o'] < 0) return -1;
                    last['a']++;
                    break;
                case 'k':
                    last['a']--;
                    if (last['a'] < 0) return -1;
                    cur--;
                    break;
            }
            ans = max(ans, cur);
        }
        
        for (auto&[k, v] : last) {
            if (v != 0) return -1;
        }
        return ans;
    }
};