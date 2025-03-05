class Solution {
public:
    string minRemoveToMakeValid(string s) {
        const int n = s.size();
        int left = 0, right = 0;
        for (int i = 0; i < n; i++) if (s[i] == ')') right++;

        string ans;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (right > 0) {
                    left++, right--;
                    ans += s[i];
                }
            } else if (s[i] == ')') {
                if (left > 0) {
                    left--;
                    ans += s[i];
                } else {
                    right--;
                }
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};