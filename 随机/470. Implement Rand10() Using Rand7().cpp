// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        const int v[7][7] = {
            {0,1,2,3,4,5,6},
            {7,8,9,0,1,2,3},
            {4,5,6,7,8,9,0},
            {1,2,3,4,5,6,7},
            {8,9,0,1,2,3,4},
            {5,6,7,8,9,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1}
        };
        
        int ans = -1;
        while (ans == -1) {
            ans = v[rand7() - 1][rand7() - 1];
        }
        return ans + 1;
    }
};
