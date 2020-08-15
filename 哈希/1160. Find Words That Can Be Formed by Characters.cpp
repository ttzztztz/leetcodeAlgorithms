class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int answer = 0;
        unordered_map<char, int> stand;
        for (const char ch : chars) stand[ch]++;
        
        for (const string& str : words) {
            unordered_map<char, int> appear;
            for (const char ch : str) appear[ch]++;
            
            bool ok = true;
            for (const auto& p : appear) {
                char ch;
                int cnt;
                tie(ch, cnt) = p;
                
                if (cnt > stand[ch]) {
                    ok = false;
                    break;
                }
            }
            
            if (ok) answer += str.size();
        }
        
        return answer;
    }
};