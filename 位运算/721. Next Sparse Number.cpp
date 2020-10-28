class Solution {
public:
    /**
     * @param x: a number
     * @return: return the next sparse number behind x
     */
    int nextSparseNum(int x) {
        // write your code here
        
        int original = x;
        for (int i = 0; i < 31; i++) {
            if ((x & (1 << i)) && (x & (1 << (i + 1)))) {
                x += 1 << i;
            }
        }
        
        for (int i = 31; i >= 0; i--) {
            if ((x & (1 << i)) && (x ^ (1 << i)) >= original) {
                x ^= 1 << i;
            }
        }
        
        return x;
    }
};
