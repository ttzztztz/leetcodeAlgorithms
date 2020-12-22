class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1.size() != str2.size()) return false;
        if (str1 == str2) return true;
        
        unordered_map<char, char> convert_map;
        unordered_set<char> str2_char_set;
        for (int i = 0; i < str1.size(); i++) {
            if (convert_map.count(str1[i]) && convert_map[str1[i]] != str2[i]) return false;
            convert_map[str1[i]] = str2[i];
            str2_char_set.insert(str2[i]);
        }
        
        return str2_char_set.size() < 26;
    }
};
