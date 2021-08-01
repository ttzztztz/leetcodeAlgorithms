class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        typedef long long ll;
        
        ll sum = accumulate(milestones.begin(), milestones.end(), 0ll);
        ll mx = *max_element(milestones.begin(), milestones.end());
        
        if (sum - mx >= mx) {
            return sum;
        } else {
            return 1 + 2 * (sum - mx);
        }
    }
};