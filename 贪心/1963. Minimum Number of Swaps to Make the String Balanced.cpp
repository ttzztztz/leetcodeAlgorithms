class Solution {
public:
    int minSwaps(string s) {
        const int n = s.size();
        int ans = 0, b = 0;
        vector<int> r;
        for (int i = 0; i < n; i++) {
            if (s[i] == '[') r.push_back(i);
        }
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '[') {
                b++;
            } else { // s[i] == ']'
                if (b == 0) {
                    s[r.back()] = ']';
                    r.pop_back();
                    s[i] = '[';
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