class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        const int n = word1.size(), m = word2.size();
        string ans;
        while (i < n || j < m) {
            if (i < n) ans += word1[i++];
            if (j < m) ans += word2[j++];
        }
        return ans;
    }
};
