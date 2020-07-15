class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        const int N = bits.size();
        int i = 0;
        while (i < N - 1) {
            i += bits[i] + 1;
        }
        return i == N - 1;
    }
};