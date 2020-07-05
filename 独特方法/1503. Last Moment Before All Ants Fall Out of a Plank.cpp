class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int answer = 0;
        for (int i : left) {
            answer = max(answer, i);
        }
        for (int i : right) {
            answer = max(answer, n - i);
        }
        
        return answer;
    }
};
