class Solution {
public:
    int bitwiseComplement(int num) {
        if (num == 0) return 1;
        
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
