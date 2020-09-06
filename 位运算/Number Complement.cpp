class Solution {
public:
    int findComplement(int num) {
        bool isLead = true;
        for (int i = 30; i >= 0; i--) {
            if (num & (1 << i)) {
                num ^= 1 << i;
                isLead = false;
            } else {
                if (!isLead) {
                    num ^= 1 << i;
                }
            }
        }
        return num;
    }
};
