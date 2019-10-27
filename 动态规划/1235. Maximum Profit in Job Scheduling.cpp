class Shedule{
public:
    int start, end, profit;
    Shedule() : start(0), end(0), profit(0) {};
    Shedule(int s, int e, int p) : start(s), end(e), profit(p) {};
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        const int N = startTime.size();
        vector<Shedule> shedules(N, Shedule());
        for (int i = 0; i < N; i++) {
            shedules[i] = {startTime[i], endTime[i], profit[i]};
        }
        std::sort(shedules.begin(), shedules.end(), [](const Shedule& $1, const Shedule& $2)->bool {
            return $1.end < $2.end;
        });
        map<int, int> dp;

        dp.insert({0, 0});
        for (const Shedule& shedule : shedules) {
            auto it = std::prev(dp.upper_bound(shedule.start));

            if (it->second + shedule.profit > dp.rbegin()->second) {
                dp[shedule.end] = it->second + shedule.profit;
            }
        }

        return dp.rbegin()->second;
    }
};