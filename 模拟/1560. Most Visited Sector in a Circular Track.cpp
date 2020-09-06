class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        const int m = rounds.size();
        vector<int> times(n, 0);
        times[rounds[0] - 1]++;
        
        for (int i = 1, cur = rounds[0] - 1; i < m; i++) {
            const int t = rounds[i] - 1;
            while (cur != t) {
                cur = (cur + 1) % n;
                times[cur]++;
            }
        }
        
        vector<int> answer;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (times[i] > mx) {
                answer = {i + 1};
                mx = times[i];
            } else if (times[i] == mx) {
                answer.push_back(i + 1);
            }
        }

        return answer;
    }
};
