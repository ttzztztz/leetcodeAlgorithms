class Solution {
public:
    string validIPAddress(string IP) {
        int type = 0;
        string cur;
        vector<string> f;
        char last = 0;
        bool haveMin = false;
        
        for (int i = 0; i < IP.size(); i++) {
            const char ch = IP[i];
            if (ch == '.') {
                if (type == 6) {
                    return "Neither";
                }
                
                type = 4;
                f.push_back(cur);
                cur.clear();
            } else if (ch == ':') {
                if (type == 4) {
                    return "Neither";
                }
                
                if (last == ':') {
                    haveMin = true;
                }
                type = 6;
                if (!cur.empty()) f.push_back(cur);
                cur.clear();
            } else {
                if (ch >= 'A' && ch <= 'Z') {
                    cur += ch - 'A' + 'a';
                } else {
                    cur += ch;
                }
            }
            
            last = ch;
        }
        
        f.push_back(cur);
        if (type == 4) return v4(f);
        else if (type == 6) return v6(f, haveMin);
        else return "Neither";
    }
private:
    string v4(const vector<string>& f) {
        if (f.size() != 4) return "Neither";
        for (const string& s : f) {
            if (s.empty() || s.size() > 3) return "Neither";
            for (const char ch : s) {
                if (ch < '0' || ch > '9') return "Neither";
            }
            
            if (s != "0") {
                for (const char ch : s) {
                    if (ch == '0') return "Neither";
                    else break;
                }
            }
            
            int v = stoi(s, nullptr, 10);
            if (v < 0 || v > 255) return "Neither";
        }
        return "IPv4";
    }
    string v6(const vector<string>& f, bool haveMin) {
        if (haveMin && f.size() >= 6) return "Neither";
        if (f.size() < 2 || f.size() > 8) return "Neither";
        if (f.size() == 7 || f.size() == 6) return "Neither";
        for (const string& s : f) {
            if (s.empty() || s.size() > 4) return "Neither";
            
            for (const char ch : s) {
                if (!((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f'))) return "Neither";
            }

            int v = stoi(s, nullptr, 16);
            if (v < 0 || v > 0xffff) return "Neither";
        }
        return "IPv6";
    }
};
