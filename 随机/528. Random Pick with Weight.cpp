class Solution {
public:
    Solution(vector<int>& w) {
        prefix.push_back(0);
        for (int i : w) prefix.push_back(prefix.back() + i);

        gen = mt19937(rd());
        d = uniform_int_distribution<int>(0, prefix.back() - 1);
    }
    
    int pickIndex() {
        const int random_number = d(gen);
        auto it = upper_bound(prefix.begin(), prefix.end(), random_number);
        return it - prefix.begin() - 1;
    }
private:
    random_device rd;
    mt19937 gen;
    uniform_int_distribution<int> d;
    vector<int> prefix;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */