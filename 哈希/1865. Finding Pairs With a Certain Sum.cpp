class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a = nums1, b = nums2;
        for (int i : b) h[i]++;
    }
    
    void add(int index, int val) {
        const int prev = b[index];
        h[prev]--;
        h[prev + val]++;
        b[index] += val;
    }
    
    int count(int tot) {
        int ans = 0;
        for (int i : a) {
            if (h.count(tot - i)) ans += h[tot - i];
        }
        return ans;
    }
private:
    vector<int> a, b;
    unordered_map<int, int> h;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */