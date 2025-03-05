class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) continue;
            data.emplace_back(i, nums[i]);
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        const vector<pair<int, int>>& lhs = this->data;
        const vector<pair<int, int>>& rhs = vec.data;

        const int len1 = lhs.size(); // lhs.size() == rhs.size()
        const int len2 = rhs.size();

        int ans = 0, ptr1 = 0, ptr2 = 0;
        while (ptr1 < len1 && ptr2 < len2) {
            auto [idx1, val1] = lhs[ptr1];
            auto [idx2, val2] = rhs[ptr2];

            if (idx1 < idx2) {
                ptr1++;
            } else if (idx1 == idx2) {
                ans += val1 * val2;
                ptr1++, ptr2++;
            } else { // idx1 > idx2
                ptr2++;
            }
        }
        return ans;
    }

    vector<pair<int, int>> data; // { idx, val }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);