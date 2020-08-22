class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        for (auto& rect : rects) {
            total += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            pref.push_back(total);
        }
        
        d = uniform_int_distribution<int>(0, total - 1);
    }
    
    vector<int> pick() {
        const int idx = d(rd);
        auto it = upper_bound(pref.begin(), pref.end(), idx);
        const int offset = it - pref.begin();
        
        const vector<int>& rect = rects[offset];
        const int w = rect[2] - rect[0] + 1;
        const int h = rect[3] - rect[1] + 1;
        
        const int base = *it - w * h;
        vector<int> answer(2, 0);
        answer[0] = rect[0] + (idx - base) % w;
        answer[1] = rect[1] + (idx - base) / w;
        return answer;
    }
private:
    vector<int> pref;
    vector<vector<int>> rects;
    mt19937 rd{random_device{}()};
    uniform_int_distribution<int> d;
    int total = 0;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
