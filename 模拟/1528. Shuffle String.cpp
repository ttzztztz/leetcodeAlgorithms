class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        const int N = indices.size();
        
        string answer(N, 'a');
        for (int i = 0; i < N; i++) {
            answer[indices[i]] = s[i];
        }
        
        return answer;
    }
};
