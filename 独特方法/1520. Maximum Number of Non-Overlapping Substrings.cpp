class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        l = vector<int>(26, 999999), r = vector<int>(26, -1);
        const int N = s.size();
        for (int i = 0; i < N; i++) {
            const int c = s[i] - 'a';
            l[c] = min(l[c], i);
            r[c] = max(r[c], i);
        }
        
        vector<string> answer;
        int last = -1;
        
        for (int i = 0; i < N; i++) {
            const int c = s[i] - 'a';
            if (l[c] != i) continue;
            
            const int _last = solve(s, i);
            if (_last == -1) continue;
            if (last < i) answer.push_back("");
            
            last = _last;
            answer.back() = s.substr(i, last - i + 1);
        }
        
        return answer;
    }
private:
    vector<int> l, r;
    int solve(const string& s, int i) {
        const int N = s.size();
        int right = r[s[i] - 'a'];
        for (int k = i; k <= right; k++) {
            const int c = s[k] - 'a';
            if (l[c] < i) return -1;
            
            right = max(right, r[c]);
        }
        return right;
    }
};
