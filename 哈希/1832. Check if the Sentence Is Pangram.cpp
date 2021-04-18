class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> a;
        for (const char ch : sentence) a[ch]++;
        
        for (char i = 'a'; i <= 'z'; i++) {
            if (a[i] <= 0) return false;
        }
        return true;
    }
};