class Solution {
public:
    int longestPalindrome(string s) {
        int answer = 0, oddCnt = 0;
        unordered_map<char, int> a;
        for (const char ch : s) {
            a[ch]++;
            
            if (a[ch] % 2 == 1) {
                oddCnt++;
            } else {
                answer += 2;
                oddCnt--;
            }
        }
        return answer + (oddCnt > 0 ? 1 : 0);
    }
};
