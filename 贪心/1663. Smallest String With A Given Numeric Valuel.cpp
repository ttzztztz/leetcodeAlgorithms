class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        k -= n;
        
        int ptr = n - 1;
        while (k > 0) {
            if (k >= 25) {
                ans[ptr] = 'z';
                k -= 25;
            } else {
                ans[ptr] += k;
                k = 0;
            }
            
            ptr--;
        }
        
        return ans;
    }
};
