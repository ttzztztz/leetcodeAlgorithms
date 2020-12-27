class Solution {
public:
    string maximumBinaryString(string binary) {
        if (binary.empty()) return "";
        const int n = binary.size();
        
        string ans;
        int left = 0;
        for (int i = 0; i < n; i++) {
            if (binary[i] == '1') {
                left++;
            } else {
                break;
            }
        }
        
        ans = string(left, '1');
        int cnt1 = 0, cnt0 = 0;
        for (int i = left; i < n; i++) {
            if (binary[i] == '1') cnt1++;
            else cnt0++;
        }
        for (int j = 0; j < cnt0 - 1; j++) ans += '1';
        if (cnt0 >= 1) ans += '0';
        for (int j = 0; j < cnt1; j++) ans += '1';
        
        return max(ans, binary);
    }
};
