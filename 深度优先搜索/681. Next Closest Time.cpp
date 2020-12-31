class Solution {
public:
    string nextClosestTime(string time) {
        unordered_set<char> bit = {time[0], time[1], time[3], time[4]};
        all = vector<char>(bit.begin(), bit.end());
        
        int hour = (time[0] - '0') * 10 + (time[1] - '0');
        int minute = (time[3] - '0') * 10 + (time[4] - '0');
        cur_ts = hour * 60 + minute;
        
        dfs(0, 0, 0);
        return ans;
    }
private:
    vector<char> all;
    int ans_delta = -1, cur_ts = 0;
    string ans;
    
    void dfs(int idx, int hour, int minute) {
        if (hour < 0 || hour >= 24 || minute < 0 || minute >= 60) return;

        if (idx == 4) {
            int ts = hour * 60 + minute;
            int delta = ts - cur_ts;
            if (delta <= 0) delta = ts + 24 * 60 - cur_ts;
            
            if (ans_delta == -1 || ans_delta > delta) {
                ans_delta = delta;
                string h = to_string(hour), m = to_string(minute);
                if (h.size() == 1) h = "0" + h;
                if (m.size() == 1) m = "0" + m;
                ans = h + ":" + m;
            }
            return;
        }
        
        for (char k : all) {
            const int d = k - '0';
            
            if (idx == 0) {
                dfs(idx + 1, 10 * d, minute);
            } else if (idx == 1) {
                dfs(idx + 1, hour + d, minute);
            } else if (idx == 2) {
                dfs(idx + 1, hour, 10 * d);
            } else if (idx == 3) {
                dfs(idx + 1, hour, minute + d);
            }
        }
    }
};
