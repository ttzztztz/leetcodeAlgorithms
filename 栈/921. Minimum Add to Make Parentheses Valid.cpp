class Solution {
public:
    int minAddToMakeValid(string s) {
        if (s.empty()) return 0;
        const int n = s.size();

        int ans = 0, balance = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                balance++;
            } else if (s[i] == ')') {
                balance--;
                if (balance < 0) ans++, balance = 0;
            }
        }
        return ans + balance;
    }
};