class SummaryRanges {
public:
    SummaryRanges() {
        s.insert(vector<int>{ -INF, -INF });
        s.insert(vector<int>{ INF, INF });
    }

    void addNum(int val) {
        auto l = s.lower_bound(vector<int>{val, val});
        auto r = l--;
        
        if ((*l)[0] <= val && val <= (*l)[1]) return;
        if ((*r)[0] <= val && val <= (*r)[1]) return;
        
        if ((*l)[1] + 1 == val && val + 1 == (*r)[0]) {
            s.emplace(vector<int>{ (*l)[0], (*r)[1] });
            s.erase(l);
            s.erase(r);
        } else if ((*l)[1] + 1 == val) {
            s.emplace(vector<int>{ (*l)[0], val });
            s.erase(l);
        } else if (val + 1 == (*r)[0]) {
            s.emplace(vector<int>{ val, (*r)[1] });
            s.erase(r);
        } else {
            s.emplace(vector<int>{ val, val });
        }
    }

    vector<vector<int>> getIntervals() {
        return vector<vector<int>>(++s.begin(), --s.end());
    }
private:
    typedef vector<int> Interval;
    set<Interval> s;
    const int INF = 1e9+7;
};