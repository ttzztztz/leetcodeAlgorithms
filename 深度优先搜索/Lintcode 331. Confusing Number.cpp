unordered_map<int, int> f;

class Solution {
public:
    /**
     * @param k: the number of auction participants
     * @return: the number of confusing numbers
     */
    int theConfusingNumbers(int k) {
        if (f.count(k)) return f[k];
        possible = {0, 1, 6, 8, 9};
        this->k = k;
        
        for (int k = 1; k < possible.size(); k++) {
            dfs(possible[k]);
        }
        return f[k] = ans;
    }
private:
    vector<int> possible;
    typedef long long ll;
    int ans = 0;
    ll k;
    
    bool ok(ll num) {
        string rev = to_string(num);
        reverse(rev.begin(), rev.end());
        for (int d = 0; d < rev.size(); d++) {
            if (rev[d] == '6') rev[d] = '9';
            else if (rev[d] == '9') rev[d] = '6';
        }
        for (int k = 0; k < rev.size(); k++) {
            if (rev[k] == '0') return false;
            else break;
        }
        const ll q = stoll(rev);
        if (q > k) return false;
        return q != num;
    }
    void dfs(ll num) {
        if (num > k) return;
        if (ok(num)) ans++;
        
        for (int k = 0; k < possible.size(); k++) {
            dfs(num * 10 + possible[k]);
        }
    }
};
