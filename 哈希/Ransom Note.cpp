class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> appearM, appearR;
        for (const char ch : magazine) appearM[ch]++;
        for (const char ch : ransomNote) appearR[ch]++;
        
        for (auto& p : appearR) {
            if (appearM[p.first] < p.second) return false;
        }
        return true;
    }
};
