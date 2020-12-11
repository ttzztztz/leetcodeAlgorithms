class Solution {
public:
    int maximumSwap(int num) {
        int ans = num;
        string s = to_string(num);
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                swap(s[i], s[j]);
                ans = max(ans, stoi(s));
                swap(s[i], s[j]);
            }
        }
        
        return ans;
    }
};
