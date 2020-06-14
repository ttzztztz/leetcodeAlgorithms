class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> appear;
        for (int i : arr) appear[i]++;
        map<int, int> r;
        for (auto& p : appear) r[p.second]++;
        int answer = appear.size();
        for (auto& p : r) {
            cout << k << endl;
            if (k <= 0) break;
            
            const int appearTimes = p.first; // appear 3 times
            const int appearCount = p.second; // have 3 numbers
            // cout << "ac = " << appearCount << ", at = " << appearTimes << endl;

            if (k >= appearTimes * appearCount) {
                answer -= appearCount;
                k -= appearTimes * appearCount;
            } else {
                answer -= k / appearTimes;
                break;
            }
        }
        return answer;
    }
};
