class Solution {
public:
    /**
     * @param num: a array
     * @param target: a num
     * @return: return all combinations
     */
    vector<int> combinationSet(vector<int> &num, int target) {
        this->target = target;
        const int n = num.size();
        sort(num.begin(), num.end());
        this->num = num;
        
        for (int i : num) {
            if (i == 0) ans.push_back(0);
            else dfs(i);
        }
        return ans;
    }
private:
    vector<int> ans, num;
    int target;
    void dfs(int state) {
        if (state >= target) return;
        else ans.push_back(state);
        
        for (int i : num) {
            dfs(state * 10 + i);
        }
    }
};
