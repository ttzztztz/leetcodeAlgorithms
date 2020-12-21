class Solution {
public:
    int nextGreaterElement(int n) {
        if (n == 0) return -1;

        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());
        
        typedef unsigned long long u64;
        if (next_permutation(digits.begin(), digits.end())) {
            u64 ans = 0;
            for (int i =  0; i < digits.size(); i++) {
                ans = (ans * 10 + digits[i]);
            }
            
            if (ans > numeric_limits<int>::max()) return -1;
            return ans;
        } else {
            return -1;
        }
    }
};
