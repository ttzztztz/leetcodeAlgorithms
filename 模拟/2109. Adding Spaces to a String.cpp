class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int ptr = 0;
        for (int i = 0; i < s.size(); i++) {
            if (ptr < spaces.size() && i == spaces[ptr]) {
                ans += ' ';
                ptr++;
            }
            ans += s[i];
        }
        return ans;
    }
};
