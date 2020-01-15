class SummaryRanges {
public:
    set<vector<int>> intervals;
    int INF = 1e9;
    /** Initialize your data structure here. */
    SummaryRanges() {
        intervals.insert({-INF, -INF});
        intervals.insert({INF, INF});
    }
    
    void addNum(int val) {
        auto it = intervals.lower_bound({val, val});
        auto it2 = it;
        it2--;
        
        if ((*it2)[0] <= val && val <= (*it2)[1] || (*it)[0] <= val && val <= (*it)[1]) {
            return;
        }
        
        bool b1 = (*it)[0] == val + 1, b2 = (*it2)[1] == val - 1;
        if (b1 && b2) {
            intervals.insert({(*it2)[0], (*it)[1]});
            intervals.erase(it), intervals.erase(it2);
        } else if (b1) {
            intervals.insert({val, (*it)[1]});
            intervals.erase(it);
        } else if (b2) {
            intervals.insert({(*it2)[0], val});
            intervals.erase(it2);
        } else {
            intervals.insert({val, val});
        }
    }
    
    vector<vector<int>> getIntervals() {
        auto it1 = intervals.begin(), it2 = intervals.end();
        it1++, it2--;
        vector<vector<int>> answer(it1, it2);
        return answer;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
