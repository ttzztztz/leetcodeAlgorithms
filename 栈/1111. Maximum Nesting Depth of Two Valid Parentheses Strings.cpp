class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> stk = {-1};
        const int n = seq.size();
        
        vector<int> layers(n, 0), match(n, 0);
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                stk.push_back(i);
                if (stk.back() != -1) layers[i] = layers[stk.back()] + 1;
                else layers[i] = 1;
            } else { // seq[i] == ')'
                const int t = stk.back();
                stk.pop_back();
                match[i] = t;
                if (stk.back() != -1) {
                    layers[stk.back()] = max(layers[stk.back()], layers[t] + 1);
                }
            }
        }
        
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                ans[i] = layers[i] % 2;
            } else { // s[i] == ')'
                ans[i] = ans[match[i]];
            }
        }
        return ans;
    }
};
