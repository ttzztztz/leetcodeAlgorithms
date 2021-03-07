class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        typedef long long ll;
        ll sum = 0;
        for (int i : nums) sum += i;
        if (sum > goal) {
            const ll d = sum - goal;
            return 1ll * (d / limit) + (d % limit > 0);
        } else if (sum < goal) {
            const ll d = goal - sum;
            return 1ll * (d / limit) + (d % limit > 0);
        } else return 0;
    }
};
