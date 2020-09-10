class Solution {
public:
    /**
     * @param nums: a list of integer
     * @param k: an integer
     * @return: return a boolean, denote whether the array can be divided into k non-empty subsets whose sums are all equal
     */
    bool partitiontoEqualSumSubsets(vector<int> &nums, int k) {
        this->nums = nums;
        this->n = nums.size();
        int sum = 0;
        for (int i : nums) sum += i;
        if (sum % k != 0) return false;
        each = sum / k;
        this->mask = (1 << n) - 1;
        
        memset(f, 0xff, sizeof f);
        return dfs(0, k);
    }
private:
    vector<int> nums;
    int n, each, mask;
    int f[66000][18];
    
    int dfs(int state, int k) {
        if (k == 0) return state == mask ? 1 : 0;
        if (state == mask) return 0;
        
        int& val = f[state][k];
        if (val != -1) return -1;
        
        int answer = 0;
        vector<int> nxtState = calcNextState(state);
        for (int nxt : nxtState) {
            if (dfs(nxt, k - 1)) answer |= 1;
        }
        return val = answer;
    }
    
    vector<int> tmp;
    void dfsState(int curState, int i, int curSum) {
        if (curSum > each) return;
        if (curSum == each) {
            tmp.push_back(curState);
            return;
        }
            
        for (int j = i; j < n; j++) {
            if (curState & (1 << j)) continue;
            dfsState(curState | (1 << j), j + 1, curSum + nums[j]);
        }
    }
    vector<int> calcNextState(int state) {
        tmp = {};
        dfsState(state, 0, 0);
        return tmp;
    }
};