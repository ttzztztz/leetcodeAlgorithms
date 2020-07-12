class Solution {
public:
    string reformatDate(string date) {
        vector<string> all = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        unordered_map<string, string> f;
        for (int i = 0; i < all.size(); i++) {
            f[all[i]] = to_string(i + 1);
        }
        
        stringstream ss(date);
        string y, m, d;
        ss >> d;
        d.pop_back();
        d.pop_back();
        if (d.size() == 1) d = "0" + d;
        
        ss >> m;
        m = f[m];
        if (m.size() == 1) m = "0" + m;
        
        ss >> y;
        
        return y + "-" + m + "-" + d;
    }
};