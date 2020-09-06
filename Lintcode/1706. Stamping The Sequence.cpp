class Solution {
public:
    /**
     * @param stamp: 
     * @param target: 
     * @return: List[int]
     */
    vector<int> movesToStamp(string &stamp, string &target) {
        vector<int> answer;
        const int N = target.size();
        string finalState(N, '?');
        
        while (target != finalState) {
            int tmp = solve(stamp, target);
            if (tmp == -1) return answer;
            answer.push_back(tmp);
        }
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
private:
    int solve(string& stamp, string& target) {
        const int N = target.size(), M = stamp.size();
        for (int i = 0; i < N; i++) {
            int j = 0, k = i;
            bool valid = false;
            while (j < M && k < N && (stamp[j] == target[k] || target[k] == '?')) {
                if (target[k] != '?') valid = true;
                j++, k++;
            }
            if (valid && j == M) {
                fill(target.begin() + i, target.begin() + k, '?');
                return i;
            }
        }
        
        return -1;
    }
};
