class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        const int N = words.size();
        vector<string> answer;
        
        for (int i = 0; i < N; i++) {
            bool ok = false;
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                
                if (words[j].find(words[i]) != std::string::npos) {
                    ok = true;
                    break;
                }
            }
            
            if (ok) answer.push_back(words[i]);
        }
        
        return answer;
    }
};
