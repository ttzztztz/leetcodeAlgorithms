class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        
        int ptr = 1;
        
        digits[0]++;
        bool should = digits[0] >= 10;
        if (should) digits[0] -= 10;
        
        while (ptr < digits.size() && should) {
            digits[ptr] ++;
            if (digits[ptr] >= 10) {
                digits[ptr] -= 10;
                ptr++;
                should = true;
            } else should = false;
        }
        if (ptr == digits.size() && should) digits.push_back(1);
        
        reverse(digits.begin(), digits.end());
        return digits;
    }
};