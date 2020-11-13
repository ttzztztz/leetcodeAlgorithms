class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        memset(f, 0xff, sizeof f);
        this->nums = nums, this->n = nums.size();
        
        const int all = accumulate(nums.begin(), nums.end(), 0);
        const int mx =  dfs(0, n - 1, 0);
        return mx >= all - mx;
    }
private:
    int f[25][25][2];
    int n;
    vector<int> nums;
    
    int dfs(int i, int j, int turn) {
        if (i > j) return 0;
        int& val = f[i][j][turn];
        if (val != -1) return val;
        
        // int answer = (turn == 0) ? -1 : numeric_limits<int>::max();
        int answer = 0;
        if (turn == 0) { // player 1
            answer = max(
                nums[i] + dfs(i + 1, j, turn ^ 1),
                nums[j] + dfs(i, j - 1, turn ^ 1)
            );
        } else { // player 2
            answer = min(
                dfs(i + 1, j, turn ^ 1),
                dfs(i, j - 1, turn ^ 1)
            );
        }
        
        return val = answer;
    }
};
