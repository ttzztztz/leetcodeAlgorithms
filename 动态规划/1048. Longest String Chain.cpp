class Solution {
public:
    int longestStrChain(vector<string>& words) {
        const int n = words.size();
        int ans = 0;
        sort(words.begin(), words.end(), [&](const auto& lhs, const auto& rhs) -> bool {
            return lhs.size() < rhs.size();
        });
        
        vector<int> f(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (ok(words[j], words[i])) f[i] = max(f[i], f[j] + 1);
            }
            ans = max(ans, f[i]);
        }
        return ans;
    }
private:
    bool ok(const string& from, const string& to) {
        if (from.size() + 1 == to.size()) {
            for (int i = 0, j = 0, changed = 0; i < to.size();) {
                if (from[j] == to[i]) {
                    i++, j++;
                    continue;
                } else { // from[i] != to[j]
                    if (changed) return false;
                    else changed = true;
                    i++;
                }
            }
            return true;
        } else {
            return false;
        }
    }
};