class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());
        
        int carry = 0, i = 0, j = 0;
        while (i < arr1.size() || j < arr2.size() || carry) {
            if (i < arr1.size()) carry += arr1[i++];
            if (j < arr2.size()) carry += arr2[j++];
            
            ans.push_back(carry & 1);
            carry = -(carry >> 1);
        }
        
        while (!ans.empty() && ans.back() == 0) {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        if (ans.empty()) {
            ans.push_back(0);
        }
        return ans;
    }
};
