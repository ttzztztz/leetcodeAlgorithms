class Solution {
public:
    /**
     * @param stickers: a string array
     * @param target: a string
     * @return: the minimum number of stickers that you need to spell out the target
     */
    int minStickers(vector<string> &stickers, string &target) {
        const int n = target.size(), MAX = 0x3f3f3f3f;
        int f[(1 << n) + 5];
        memset(f, 0x3f, sizeof f);
        const int mask = (1 << n) - 1;
        f[0] = 0;
        
        for (int i = 0; i <= mask; i++) {
            if (f[i] == MAX) continue;
            
            for (const string& s : stickers) {
                int state = i;
                for (const auto& c : s) {
                    for (int k = 0; k < n; k++) {
                        if (target[k] == c && !(state & (1 << k))) {
                            state |= 1 << k;
                            break;
                        }
                    }
                }
                f[state] = min(f[state], f[i] + 1);
            }
        }
        
        
        if (f[mask] == MAX) return -1;
        else return f[mask];
    }
};