class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> seconds_list;
        for (const string& str : timePoints) {
            int h, m;
            sscanf(str.c_str(), "%d:%d", &h, &m);
            seconds_list.push_back(h * 60 + m);
            seconds_list.push_back(h * 60 + m + 24 * 60);
        }
        
        sort(seconds_list.begin(), seconds_list.end());
        int ans = numeric_limits<int>::max();
        for (int i = 1; i < seconds_list.size(); i++) {
            ans = min(ans, seconds_list[i] - seconds_list[i - 1]);
        }
        return ans;
    }
};
