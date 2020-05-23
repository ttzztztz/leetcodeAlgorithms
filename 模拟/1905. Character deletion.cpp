class Solution {
public:
    /**
     * @param str: The first string given
     * @param sub: The given second string
     * @return: Returns the deleted string
     */
    string CharacterDeletion(string &str, string &sub) {
        unordered_set<char> all;
        for (const char ch : sub) all.insert(ch);
        
        string answer;
        for (const char ch : str) {
            if (!all.count(ch)) answer.push_back(ch);
        }
        return answer;
    }
};
