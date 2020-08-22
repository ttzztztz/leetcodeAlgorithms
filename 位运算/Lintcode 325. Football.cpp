class Solution {
public:
    /**
     * @param probability: the winning probability of 16 teams in pairs
     * @return: return the index of the winner with the highest probability of winning
     */
    int findWinner(vector<vector<double>> &probability) {
        memset(f, 0, sizeof f);
        this->probability = probability;
        
        dfs(mask, 1.0);
        
        double ans[16];
        memset(ans, 0, sizeof ans);
        for (int i = 0; i < 16; i++) {
            ans[i] = f[1 << i];
        }
        return max_element(ans, ans + 16) - ans;
    }
private:
    const int mask = (1 << 16) - 1;
    double f[(1 << 16) + 5];

    vector<vector<double>> probability;
    void dfs(int state, double cur) {
        f[state] += cur;
        vector<int> v = validBit(state);
        
        if (v.size() == 1) return;
        vector<pair<int, double>> nx = nxtState(v);
        for (const auto& i : nx) {
            int nxt;
            double nxtProb;
            tie(nxt, nxtProb) = i;
            
            dfs(nxt, cur * nxtProb);
        }
    }
    
    vector<pair<int, double>> nxtState(const vector<int>& v) {
        vector<pair<int, double>> cur{{0, 1.0}};
        
        for (int i = 0; i + 1 < v.size(); i += 2) {
            vector<pair<int, double>> nxt;
            
            for (const auto& c : cur) {
                int state;
                double prob;
                
                tie(state, prob) = c;
                nxt.emplace_back(state | (1 << v[i]), prob * probability[v[i]][v[i + 1]]);
                
                nxt.emplace_back(state | (1 << v[i + 1]), prob * probability[v[i + 1]][v[i]]);
            }
            
            cur = nxt;
        }
        
        return cur;
    }
    
    vector<int> validBit(int state) {
        vector<int> answer;
        for (int i = 0; i < 16; i++) {
            if (state & (1 << i)) {
                answer.push_back(i);
            }
        }
        return answer;
    }
    
    int bitCnt(int state) {
        int answer = 0;
        for (int i = 0; i < 16; i++) {
            if (state & (1 << i)) {
                answer++;
            }
        }
        return answer;
    }
};
