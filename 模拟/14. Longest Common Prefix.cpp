class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string ans;
        const int n = strs.size();
        int min_length = strs[0].size();
        for (int j = 0; j < n; j++) {
            min_length = min<int>(min_length, strs[j].size());
        }

        for (int i = 0; i < min_length; i++) {
            for (int j = 1; j < n; j++) {
                if (strs[0][i] != strs[j][i]) return ans;
            }
            ans += strs[0][i];
        }
        return ans;
    }
};