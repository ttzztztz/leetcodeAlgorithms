class Solution {
public:
    int longestPalindrome(string s) {
        bool haveOdd = false;
        int answer = 0;
        unordered_map<char, int> a;
        for (const char ch : s) {
            a[ch]++;
            
            if (a[ch] % 2 == 1) {
                haveOdd = true;
            } else {
                answer += 2;
            }
        }
        return answer + haveOdd;
    }
};