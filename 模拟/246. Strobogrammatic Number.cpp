class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> mapping = {
            { '0', '0' },
            { '1', '1' },
            { '6', '9' },
            { '8', '8' },
            { '9', '6' }
        };

        const int n = num.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            if (mapping[num[l]] == num[r]) {
                l++, r--;
            } else {
                return false;
            }
        }
        return true;
    }
};