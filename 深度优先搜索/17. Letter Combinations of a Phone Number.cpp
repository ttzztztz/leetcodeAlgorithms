class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return vector<string>{};
        vector<string> answer{""};
        vector<vector<char>> v = {{'a', 'b','c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'}};
        
        const int N = digits.size();
        for (int i = 0; i < N; i++) {
            vector<string> next;
            const int d = digits[i] - '2';
            for (int i = 0; i < answer.size(); i++) {
                for (char ch : v[d]) {
                    next.push_back(answer[i] + ch);
                }
            }
            answer = next;
        }
        return answer;
    }
};
