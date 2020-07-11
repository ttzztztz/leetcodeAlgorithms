class Solution {
public:
    bool rotateString(string A, string B) {
        if (A == B) return true;
        if (A.empty()) return false;
        string tmp = shft(A);
        while (tmp != A) {
            if (tmp == B) return true;
            tmp = shft(tmp);
        }
        return false;
    }
private:
    string shft(string a) {
        const char lst = *a.rbegin();
        a.pop_back();
        // cout << (lst + a) << endl;
        return lst + a;
    }
};