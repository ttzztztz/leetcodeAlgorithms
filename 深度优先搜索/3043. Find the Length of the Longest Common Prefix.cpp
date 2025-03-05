class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s;
        int ans = 0;

        for (int i : arr1) {
            while (i > 0) {
                s.insert(i);
                i /= 10;
            }
        }

        for (int i : arr2) {
            while (i > 0) {
                if (s.count(i)) ans = max(ans, get_length(i));
                i /= 10;
            }
        }

        return ans;
    }
private:
    int get_length(int i) {
        int ans = 0;
        while (i > 0) {
            ans++;
            i /= 10;
        }
        return ans;
    }
};