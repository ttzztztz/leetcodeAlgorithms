class Solution {
public:
    int maxProduct(vector<string>& words) {
        int answer = 0;
        const int n = words.size();
        vector<int> prepare(n, 0);
        for (int i = 0; i < n; i++) {
            const string& str = words[i];
            int& cur = prepare[i];
            
            for (const char ch : str) {
                cur |= (1 << (ch - 'a'));
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prepare[i] & prepare[j]) continue;
                
                answer = max(answer, (int) (words[i].size() * words[j].size()));
            }
        }
        
        return answer;
    }
};
