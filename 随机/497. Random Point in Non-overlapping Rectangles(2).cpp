class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        
        pref = {0};
        for (auto& v : rects) {
            const int w = v[2] - v[0] + 1;
            const int h = v[3] - v[1] + 1;
            
            total += w * h;
            pref.push_back(total);
        }
        d = uniform_int_distribution<int>(0, total - 1);
    }
    
    vector<int> pick() {
        const int t = d(rd);
        auto it = --upper_bound(pref.begin(), pref.end(), t);
        const int i = it - pref.begin();
        
        const vector<int>& v = rects[i];
        const int diff = t - *it;
        
        vector<int> answer{0, 0};
        const int w = v[2] - v[0] + 1;;
        const int h = v[3] - v[1] + 1;
        
        answer[0] = v[0] + diff % w;
        answer[1] = v[1] + diff / w;
        
        return answer;
    }
private:
    vector<vector<int>> rects;
    vector<int> pref;
    int total = 0;
    mt19937 rd{random_device{}()};
    uniform_int_distribution<int> d;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
