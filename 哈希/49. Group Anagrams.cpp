class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        const int N = strs.size();
        
        map<vector<int>, int> f;
        for (int i = 0; i < N; i++) {
            vector<int> tmp(26, 0);
            const string& str = strs[i];
            for (const char ch: str) tmp[ch - 'a']++;
            
            if (f.count(tmp)) {
                answer[f[tmp]].push_back(str);
            } else {
                f[tmp] = answer.size();
                answer.push_back(vector<string>{str});
            }
        }
        
        return answer;
    }
};
