class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        
        int cur = 0;
        for (char ch : s) {
            if (ch == '(') cur++;
            else if (ch == ')') cur--;
            
            ans = max(ans, cur);
        }
        return ans;
    }
};
