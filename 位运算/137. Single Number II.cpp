class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = 0;

        short bit[32];
        memset(bit, 0, sizeof(bit));

        for (int num : nums) {
            for (int i = 0; i < 32; i++) {
                if (num & (1 << i)) {
                    bit[i] = (bit[i] + 1) % 3;
                }
            }
        }

        for (int i = 0; i < 32; i++) {
            if (bit[i] == 1) {
                answer |= (1 << i);
            }
        }
        return answer;
    }
};