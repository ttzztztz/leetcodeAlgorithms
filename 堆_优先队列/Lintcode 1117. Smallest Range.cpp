class Solution {
public:
    /**
     * @param nums: k lists of sorted integers
     * @return: the smallest range that includes at least one number from each of the k lists
     */
    vector<int> smallestRange(vector<vector<int>> &nums) {
        const int INF = 999999;
        vector<int> ans = {-INF, INF};
        const int n = nums.size();
        
        typedef tuple<int, int, int> PII;
        priority_queue<PII, vector<PII>, greater<>> heap;
        multiset<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(nums[i][0]);
            heap.emplace(nums[i][0], i, 0);
        }
        
        ans = cmp(ans, s);
        while (!heap.empty()) {
            int val, i, j;
            tie(val, i, j) = heap.top();
            heap.pop();
            
            if (j + 1 < nums[i].size()) {
                heap.emplace(nums[i][j + 1], i, j + 1);
                s.erase(s.lower_bound(nums[i][j]));
                s.insert(nums[i][j + 1]);
            }
            ans = cmp(ans, s);
        }
        return ans;
    }
private:
    vector<int> cmp(const vector<int>& $1, const multiset<int>& s) {
        vector<int> $2 = { *s.begin(), *s.rbegin() };
        const int d1 = $1[1] - $1[0], d2 = $2[1] - $2[0];
        if (d1 == d2) return $1[0] < $2[0] ? $1 : $2;
        else return d1 < d2 ? $1 : $2;
    }
};
