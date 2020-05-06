class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int answer = 0;
        
        unordered_map<int, int> cnt;
        for (int i = 0; i < time.size(); i++) {
            const int cur = time[i] % 60;
            if (cur == 0) {
                answer += cnt[0];
            } else {
                answer += cnt[60 - cur];
            }
            cnt[cur]++;
        }
        return answer;
    }
};
