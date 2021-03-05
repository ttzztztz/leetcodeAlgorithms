class SparseVector {
public:
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                data.emplace_back(i, nums[i]);
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        const vector<PII>& lhs = this->data;
        const int n = lhs.size();
        const vector<PII>& rhs = vec.data;
        const int m = rhs.size();
        
        int i = 0, j = 0, ans = 0;
        while (i < n && j < m) {
            if (lhs[i].first == rhs[j].first) {
                ans += lhs[i].second * rhs[j].second;
                i++, j++;
            } else if (lhs[i].first < rhs[j].first) {
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
    
    typedef pair<int, int> PII;
    vector<PII> data;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
