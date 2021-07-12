class Solution {
public:
    bool sumGame(string num) {
        int sum = 0, cnt = 0;
        const int n = num.size();
        for (int i = 0; i < n; i++) {
            if (i < (n / 2)) {
                if (num[i] == '?') cnt++;
                else sum += num[i] - '0';
            } else { // i >= (n / 2)
                if (num[i] == '?') cnt--;
                else sum -= num[i] - '0';
            }
        }
        
        return (cnt & 1) || (sum + cnt * 9 / 2 != 0);
    }
};