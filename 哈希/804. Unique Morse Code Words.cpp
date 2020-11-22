class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> table = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> all;
        for (const string& str : words) {
            string cur;
            for (const char ch : str) cur += table[ch - 'a'];
            all.insert(cur);
        }
        return all.size();
    }
};
