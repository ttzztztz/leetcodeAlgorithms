class RangeModule {
public:
    RangeModule() {
        s.emplace(-INF, -INF);
        s.emplace(INF, INF);
    }
    
    void addRange(int left, int right) {
        auto it = --s.upper_bound({left, left});
        bool first = true;
        while (it != s.end()) {
            if (max(left, it->first) <= min(right, it->second)) {
                left = min(left, it->first);
                right = max(right, it->second);
                
                it = s.erase(it);
            } else if (first) {
                it++;
            } else {
                break;
            }
            first = false;
        }
        
        s.emplace(left, right);
    }
    
    bool queryRange(int left, int right) {
        auto it = --s.upper_bound({left, INF});
        if (it->first <= left && right <= it->second) return true;
        
        it++;
        if (it->first <= left && right <= it->second) return true;
        return false;
    }
    
    void removeRange(int left, int right) {
        auto it = --s.upper_bound({left, INF});
        vector<Interval> nxt;
        
        bool first = true;
        while (it != s.end()) {
            if (max(left, it->first) <= min(right, it->second)) {
                if (it->first < left) nxt.emplace_back(it->first, left);
                if (right < it->second) nxt.emplace_back(right, it->second);
                
                it = s.erase(it);
            } else if (first) {
                it++;
            } else {
                break;
            }
            first = false;
        }
        
        for (auto& v : nxt) {
            if (v.first < v.second) s.emplace(v);
        }
    }
private:
    typedef pair<int, int> Interval;
    set<Interval> s;
    const int INF = 1e9+7;
};
