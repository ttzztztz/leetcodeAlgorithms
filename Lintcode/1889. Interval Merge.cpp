class Solution {
public:
    /**
     * @param interval_A: a string represent a interval.
     * @param interval_B: a string represent a interval.
     * @return: if two intervals can merge return true, otherwise false.
     */
    typedef tuple<string, string, char, char> Data;
    
    bool MergeJudge(string &interval_A, string &interval_B) {
        const int commaA = interval_A.find(",");
        string a = interval_A.substr(1, commaA - 1), b = interval_A.substr(commaA + 1, interval_A.size() - (commaA + 1) - 1);
        const int commaB = interval_B.find(",");
        string c = interval_B.substr(1, commaB - 1), d = interval_B.substr(commaB + 1, interval_B.size() - (commaB + 1) - 1);
        
        
        Data left{a, b, (char) *interval_A.begin(), (char) *interval_A.rbegin()};
        Data right{c, d, (char) *interval_B.begin(), (char) *interval_B.rbegin()};
        
        return judge(left, right) || judge(right, left);
    }
private:
    bool judge(Data& a, Data& b) {
        if (get<0>(a) > get<1>(b)) return false;
        if (get<0>(a) == get<1>(b)) {
            return get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b) && (get<2>(a) == '[' || get<3>(b) == ']');
        }
        
        // cout << get<0>(a) << " " << get<0>(b) << endl;
        // cout << get<1>(a) << " " << get<1>(b) << endl;
        
        string l = get<0>(b), r = get<1>(a);
        // cout << l << ", " << r << endl << endl; 
        
        if (get<3>(a) == ')' && get<2>(b) == '(') {
            if (l.size() == r.size()) return l < r;
            else {
                if (l.size() < r.size()) return r.substr(0, l.size()) >= l;
                else return l.substr(0, r.size()) <= r;
            }
        } else {
            if (l.size() == r.size()) return l <= r;
            else {
                if (l.size() < r.size()) return r.substr(0, l.size()) >= l;
                else return l.substr(0, r.size()) <= r;
            }
        }
    }
};
