/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        map<int, int> diff;
        for (auto& a : schedule) {
            for (auto& interval : a) {
                diff[interval.start]++;
                diff[interval.end]--;
            }
        }
        
        vector<Interval> ans;
        for (auto it1 = diff.begin(), it2 = ++diff.begin(); it2 != diff.end(); it1++, it2++) {
            it2->second += it1->second;
        }
        
        int last = -1;
        for (auto it = diff.begin(); it != diff.end(); it++) {
            auto [time, cnt] = *it;
            if (cnt == 0 && last == -1) {
                last = time;
            } else if (last != -1 && cnt != 0) {
                ans.emplace_back(last, time);
                last = -1;
            }
            
        }
        return ans;
    }
};
