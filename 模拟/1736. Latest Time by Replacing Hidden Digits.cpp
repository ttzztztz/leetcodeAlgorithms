class Solution {
public:
    string maximumTime(string time) {
        for (int i = 23; i >= 0; i--) {
            for (int j = 59; j >= 0; j--) {
                string a = to_string(i);
                string b = to_string(j);
                
                if (a.size() == 1) a = "0" + a;
                if (b.size() == 1) b = "0" + b;
                
                string cur = a + ":" + b;
                if (ok(cur, time)) return cur;
            }
        }
        return "";
    }
private:
    bool ok(const string& cur, const string& time) {
        for (int i = 0; i < 5; i++) {
            if (cur[i] == ':') continue;
            if (time[i] == '?') continue;
            if (time[i] != cur[i]) return false;
        }
        return true;
    }
};
