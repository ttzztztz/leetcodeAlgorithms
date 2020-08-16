class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        const int mi = *min_element(position.begin(), position.end()), mx = *max_element(position.begin(), position.end());;
        int l = 1, r = mx - mi;
        
        while (l <= r) {
            const int mid = (l + r) >> 1;
            
            const int s = solve(position, mid);
            if (s < m) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
private:
    int solve(const vector<int>& p, int m) {
        int answer = 1, lst = p[0];
        for (int i : p) {
            if (abs(i - lst) >= m) {
                answer++;
                lst = i;
            }
        }
        return answer;
    }
};
