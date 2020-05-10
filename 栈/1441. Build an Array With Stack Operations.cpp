class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> answer;
        int ptr = 0;
        for (int i = 1; i <= n; i++) {
            if (i == target[ptr]) {
                ptr++;
                answer.push_back("Push");
            } else {
                answer.push_back("Push");
                answer.push_back("Pop");
            }
            
            if (ptr == target.size()) break;
        }
        
        return answer;
    }
};
