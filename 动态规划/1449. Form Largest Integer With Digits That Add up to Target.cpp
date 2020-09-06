class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> f[5005];
        f[0] = vector<int>(9, 0);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j <= target; j++) {
                if (j < cost[i]) continue;
                vector<int> last = f[j - cost[i]];
                if (last.empty()) continue;
                
                last[i]++;
                f[j] = maxN(f[j], last);
            }
        }
        
        const vector<int>& tmp = f[target];
        if (tmp.empty()) return "0";
        string answer;
        for (int i = 8; i >= 0; i--) {
            if (tmp[i] > 0) answer += string(tmp[i], '1' + i);
        }
        if (answer.empty()) answer = "0";
        return answer;
    }
private:
    vector<int> maxN(const vector<int>& $1, const vector<int>& $2) {
        int sz1 = 0, sz2 = 0;
        for (int i : $1) sz1 += i;
        for (int i : $2) sz2 += i;
        
        if (sz1 != sz2) return sz1 > sz2 ? $1 : $2;
        for (int i = 8; i >= 0; i--) {
            if ($1[i] > $2[i]) return $1;
            else if ($1[i] < $2[i]) return $2;
        }
        return $1;
    }
};
