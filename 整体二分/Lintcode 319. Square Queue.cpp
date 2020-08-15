class Solution {
public:
    /**
     * @param height: n people's height
     * @return: return the maxium number of people in square matrix
     */
    int MaxPeopleNumber(vector<int> &height) {
        // write your code here
        const int n = height.size();
        int l = 1, r = sqrt(n);
        sort(height.begin(), height.end());
        this->height = height;
        
        while (l <= r) {
            const int m = (l + r) >> 1;
            
            const bool ok = solve(height, m);
            if (ok) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        return r * r;
    }
private:
    bool solve(const vector<int>& height, int m) {
        memset(f, 0xff, sizeof f);
        this->m = m;
        return dfs(0) >= m;
    }
    int f[100005];
    int m;
    vector<int> height;
    
    int dfs(int idx) {
        if (idx >= height.size()) return 0;
        int& val = f[idx];
        if (val != -1) return val;
        
        int answer = 0;
        if (idx + m - 1 < height.size() && height[idx + m - 1] - height[idx] <= 2) {
            answer = max(answer, 1 + dfs(idx + m));
        }
        answer = max(answer, dfs(idx + 1));
        return val = answer;
    }
};
