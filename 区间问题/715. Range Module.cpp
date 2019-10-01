class Interval {
public:
    int start, end;
    Interval() : start(0), end(0) {};
    Interval(int s, int e) : start(s), end(e) {};

    bool operator<(const Interval& $2) const {
        return this->start < $2.start;
    }
};

class RangeModule {
public:
    multiset<Interval> intervalSet;
    RangeModule() {}

    void addRange(int left, int right) {
        Interval newInterval(left, right);

        auto it = std::lower_bound(intervalSet.begin(), intervalSet.end(), newInterval, [](const Interval& $1, const Interval& $2)->bool{
            return $1.start < $2.start;
        });
        if (it != intervalSet.begin()) {
            it--;
        }

        while (it != intervalSet.end()) {
            if (it->end < left) {
                it++;
                continue;
            }

            if (right < it->start) {
                break;
            }

            left = std::min(left, it->start);
            right = std::max(right, it->end);
            it = intervalSet.erase(it);
        }

        intervalSet.insert(Interval(left, right));
    }

    bool queryRange(int left, int right) {
        Interval newInterval(left, right);

        auto it = std::lower_bound(intervalSet.begin(), intervalSet.end(), newInterval, [](const Interval& $1, const Interval& $2)->bool{
            return $1.start < $2.start;
        });
        if (it != intervalSet.begin()) {
            it--;
        }
        while (it != intervalSet.end()) {
            if (right < it->start) {
                break;
            }

            if (it->start <= left && right <= it->end) {
                return true;
            }

            it++;
        }
        return false;
    }

    void removeRange(int left, int right) {
        Interval newInterval(left, right);
        vector<Interval> willAdd;

        auto it = std::lower_bound(intervalSet.begin(), intervalSet.end(), newInterval, [](const Interval& $1, const Interval& $2)->bool{
            return $1.start < $2.start;
        });
        if (it != intervalSet.begin()) {
            it--;
        }
        while (it != intervalSet.end()) {
            if (it->end < left) {
                it++;
                continue;
            }

            if (right < it->start) {
                break;
            }

            if (it->start < left) {
                willAdd.push_back(Interval(it->start, left));
            }
            if (right < it->end) {
                willAdd.push_back(Interval(right, it->end));
            }

            it = intervalSet.erase(it);
        }

        for (const Interval& interval : willAdd) {
            intervalSet.insert(interval);
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */