class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        int l = 0, r = 0;
        
        vector<double> delta;
        double ans = 0;
        for (auto& price : prices) {
            const double p = stod(price);
            l += floor(p);
            r += ceil(p);
            
            delta.push_back(p - floor(p));
        }
        
        if (target < l || r < target) return "-1";
        const int need = target - l;
        const int n = delta.size();
        nth_element(delta.begin(), delta.begin() + n - need, delta.end());
        for (int i = 0; i < delta.size(); i++) {
            if (i < delta.size() - need) {
                ans += delta[i];
            } else {
                ans += 1.0 - delta[i];
            }
        }
        
        string ans_str = to_string(ans);
        auto it = ans_str.find(".");
        if (it == string::npos) {
            ans_str += ".000";
        } else {
            int tail = ans_str.size() - it - 1;
            while (tail > 3) ans_str.pop_back(), tail--;
            while (tail < 3) ans_str += "0", tail++;
        }
        return ans_str;
    }
};
