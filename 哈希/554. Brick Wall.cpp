class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        const int N = wall.size();
        int answer = N, right = 0;
        
        unordered_map<int, int> appear;
        for (int i = 0; i < N; i++) {
            int offset = 0;
            for (int j = 0; j < wall[i].size(); j++) {
                offset += wall[i][j];
                appear[offset]++;
            }
            right = max(right, offset);
        }
        
        for (auto& p : appear) {
            if (p.first == 0 || p.first == right) continue;
            answer = min(answer, N - p.second);
        }
        return answer;
    }
};
