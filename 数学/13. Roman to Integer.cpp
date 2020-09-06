class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> dict = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        unordered_map<string, int> dict2 = {
            {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90},
            {"CD", 400}, {"CM", 900}
        };
        
        int answer = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && dict2.count(string{s[i], s[i + 1]})) {
                answer += dict2[string{s[i], s[i + 1]}];
                i++;
            } else {
                answer += dict[s[i]];
            }
        }
        return answer;
    }
};
