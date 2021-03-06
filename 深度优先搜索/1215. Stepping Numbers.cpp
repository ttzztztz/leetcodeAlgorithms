class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        max_number = high;
        init();
        auto it1 = all.lower_bound(low);
        auto it2 = all.upper_bound(high);
        
        vector<int> ans;
        while (it1 != it2) {
            ans.push_back(*it1);
            it1++;
        }
        return ans;
    }
private:
    set<int> all;
    typedef long long ll;
    ll max_number;
    
    void init() {
        all.insert(0);
        for (int i = 1; i <= 9; i++) {
            dfs(i);
        }
    }

    void dfs(ll u) {
        if (u > max_number) return;
        all.insert(u);

        const int last = u % 10;
        if (last - 1 >= 0) dfs(u * 10 + (last - 1));
        if (last + 1 <= 9) dfs(u * 10 + (last + 1));
    }
};
