class Solution {
public:
    /**
     * @param p: The time you choose to do part of the problem.
     * @param part: The points you choose to do part of the problem.
     * @param f: The time you choose to do the whole problem.
     * @param full: The points you choose to do the whole problem.
     * @return: Return the maximum number of points you can get.
     */
    int exam(vector<int> &p, vector<int> &part, vector<int> &f, vector<int> &full) {
        // write your code here
        memset(g, 0xff, sizeof g);
        this->f = f;
        this->p = p;
        this->part = part;
        this->full = full;
        return dfs(120, 0);
    }
private:
    int g[125][205];
    vector<int> p, part, f, full;
    
    int dfs(int minutes, int idx) {
        const int N = f.size();
        if (idx == N) return 0;
        if (minutes == 0) return 0;
        if (minutes < 0) return -999999;
        
        int& val = g[minutes][idx];
        if (val != -1) return val;
        
        int answer = 0;
        answer = max(answer, dfs(minutes, idx + 1));
        if (minutes >= p[idx]) answer = max(answer, dfs(minutes - p[idx], idx + 1) + part[idx]);
        if (minutes >= f[idx]) answer = max(answer, dfs(minutes - f[idx], idx + 1) + full[idx]);
        return val = answer;
    }
};
