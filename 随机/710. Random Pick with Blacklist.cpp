class Solution {
public:
    Solution(int N, vector<int>& blacklist) {
        unordered_set<int> b(blacklist.begin(), blacklist.end());
        n_ = N, m_ = N - blacklist.size();
        
        int idx = m_;
        for (int i = 0; i < blacklist.size(); i++) {
            if (blacklist[i] >= m_) continue;

            while (b.count(idx)) idx++;
            block_to_unused_[blacklist[i]] = idx;
            idx++;
        }
    }
    
    int pick() {
        uniform_int_distribution<int> dis(0, m_ - 1);
        const int t = dis(rd);

        if (block_to_unused_.count(t)) return block_to_unused_[t];
        else return t;
    }
private:
    int n_, m_;
    unordered_map<int, int> block_to_unused_;
    mt19937 rd{ random_device{}() };
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
