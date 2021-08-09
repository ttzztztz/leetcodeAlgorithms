class Solution {
public:
    int minSwaps(string s) {
        const int n = s.size();
        int ans = 0, b = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '[') {
                b++;
            } else { // s[i] == ']'
                if (b == 0) {
                    b++;
                    ans++;
                } else {
                    b--;
                }
            }
        }
        
        return ans;
    }
};