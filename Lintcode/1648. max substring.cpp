class Solution {
public:
    /**
     * @param s: the matrix
     * @return: the last substring of s in lexicographical order
     */
    string maxSubstring(string &s) {
        vector<int> ans;
        char ch = '\0';
        const int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] > ch) {
                ans = {i};
                ch = s[i];
            } else if (s[i] == ch) {
                ans.push_back(i);
            }
        }
        
        int ptr = 0;
        for (int i = 1; i < ans.size(); i++) {
            for (int k = 0; ans[i] + k < n; k++) {
                if (s[ans[i] + k] < s[ans[ptr] + k]) {
                    break;
                }
                
                if (s[ans[i] + k] > s[ans[ptr] + k]) {
                    ptr = i;
                    break;
                }
            }
        }
        return s.substr(ans[ptr]);
    }
};
