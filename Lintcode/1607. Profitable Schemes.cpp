class Solution {
public:
    /**
     * @param G: The people in a gang.
     * @param P: A profitable scheme any subset of these crimes that generates at least P profit.
     * @param group: The i-th crime requires group[i] gang members to participate.
     * @param profit: The i-th crime generates a profit[i].
     * @return: Return how many schemes can be chosen.
     */
    
    int profitableSchemes(int G, int P, vector<int> &group, vector<int> &profit) {
        this->N = group.size();
        this->P = P;
        this->G = G;
        
        f = vector<vector<vector<long long>>>(N + 5, vector<vector<long long>>(G + 5, vector<long long>(P + 5, -1)));
        
        return dfs(group, profit, 0, 0, 0);
    }
private:
    int P, G, N;
    vector<vector<vector<long long>>> f;
    long long dfs(vector<int> &group, vector<int> &profit, int i, int g, int p) {
        const int MOD = 1e9+7;
        
        if (g > this->G) return 0;
        p = min(p, this->P + 1);
        
        if (i == N) return (p >= this->P && g <= this->G) ? 1 : 0;
        if (f[i][g][p] != -1) return f[i][g][p];
        
        long long answer = 0;
        answer += dfs(group, profit, i + 1, g + group[i], p + profit[i]);
        answer %= MOD;
        
        answer += dfs(group, profit, i + 1, g, p);
        answer %= MOD;
        
        return f[i][g][p] = answer;
    }
};
