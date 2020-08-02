class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        const int N = grid.size();
        int answer = 0;
        
        vector<int> state;
        for (int i = 0; i < N; i++) state.push_back(i);
        
        auto valid = [&](int i, int grid_c) -> bool {
            const vector<int>& vec = grid[state[grid_c]];
            for (int j = i + 1; j < N; j++) {
                if (vec[j] == 1) return false;
            }
            return true;
        };
        
        for (int i = 0; i < N; i++) {
            if (valid(i, i)) continue;
            
            bool find = false;
            for (int j = i + 1; j < N; j++) {
                if (valid(i, j)) {
                    answer += j - i;
                    
                    for (int k = j; k >= i + 1; k--) {
                        state[k] = state[k - 1];
                    }
                    state[i] = j;

                    find = true;
                    break;
                }
            }
            
            if (!find) return -1;
        }
        return answer;
    }
};