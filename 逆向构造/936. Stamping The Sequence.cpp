class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        const string kInitialString(target.size(), '?');
        
        vector<int> ans;
        while (target != kInitialString) {
            const int idx = solve(stamp, target);
            
            if (idx == -1) return {};
            else ans.push_back(idx);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    int solve(const string& stamp, string& target) {
        for (int i = 0; i + stamp.size() <= target.size(); i++) {
            bool valid = false;
            int j = 0;
            
            for (; j < stamp.size() && i + j < target.size(); j++) {
                if (target[i + j] == stamp[j] || target[i + j] == '?') {
                    if (target[i + j] != '?') valid = true;
                } else {
                    break;
                }
            }
            
            if (j == stamp.size() && valid) {
                fill(target.begin() + i, target.begin() + i + stamp.size(), '?');
                return i;
            }
        }
        
        return -1;
    }
};
