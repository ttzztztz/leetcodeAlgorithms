class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        const int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '#') {
                string t = { s[i - 2], s[i - 1] };
                int idx = stoi(t);
                ans += 'a' - 1 + idx;
                i -= 2;
            } else {
                ans += 'a' - 1 + (s[i] - '0');
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};