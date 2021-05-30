class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        for (char& ch : firstWord) ch = ch - 'a' + '0';
        for (char& ch : secondWord) ch = ch - 'a' + '0';
        for (char& ch : targetWord) ch = ch - 'a' + '0';
        
        return stoi(firstWord) + stoi(secondWord) == stoi(targetWord);
    }
};