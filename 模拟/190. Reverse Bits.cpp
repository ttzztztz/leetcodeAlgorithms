class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> bits;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) bits.push_back(1);
            else bits.push_back(0);
        }
        reverse(bits.begin(), bits.end());
        uint32_t answer = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i]) {
                answer |= 1 << i;
            }
        }
        return answer;
    }
};
