class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        for (auto& group : groups) {
            nxt.push_back(build(group));
        }
        
        const int m = groups.size();
        for (int i = 0, ptr = 0; i < m; i++) {
            const int t = find(i, ptr, groups[i], nums);
            if (t == -1) {
                return false;
            } else {
                ptr = t;
            }
        }
        return true;
    }
private:
    vector<vector<int>> nxt;

    vector<int> build(const vector<int>& group) {
        const int n = group.size();
        vector<int> ans(n + 1, -1);
        ans[1] = 0;
        int i = 1, j = 0;
        while (i < n) {
            if (j == -1 || group[i] == group[j]) {
                ans[++i] = ++j;
            } else {
                j = ans[j];
            }
        }
        return ans;
    }
    
    int find(int t, int ptr, const vector<int>& tt, const vector<int>& nums) {
        const vector<int>& next = nxt[t];
        int i = ptr, j = 0;
        while (i < nums.size()) {
            if (j == -1 || nums[i] == tt[j]) {
                i++, j++;
            } else {
                j = next[j];
            }
            
            if (j == tt.size()) {
                j = next[j];
                return i;
            }
        }
        return -1;
    }
};
