class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        N = nums1.size(), M = nums2.size();
        memset(f, 0xff, sizeof f);
        
        return dfs(nums1, nums2, 0, 0, 0, 0, 0);
    }
private:
    int N, M;
    long long f[505][505][2][2][2];
    long long dfs(vector<int>& nums1, vector<int>& nums2, int i, int j, int select1, int select2, int selected) {
        if (i == N || j == M) {
            if (selected) return 0;
            else return -99999999;
        }
        if (f[i][j][select1][select2][selected] != -1) return f[i][j][select1][select2][selected];
        long long answer = -99999999;
        
        if (select1) {
            answer = max(answer, nums1[i] * nums2[j] + dfs(nums1, nums2, i + 1, j + 1, 0, 0, 1));
            answer = max(answer, dfs(nums1, nums2, i, j + 1, 1, 0, selected));
        } else if (select2) {
            answer = max(answer, nums1[i] * nums2[j] + dfs(nums1, nums2, i + 1, j + 1, 0, 0, 1));
            answer = max(answer, dfs(nums1, nums2, i + 1, j, 0, 1, selected));
        } else {
            answer = max(answer, nums1[i] * nums2[j] + dfs(nums1, nums2, i + 1, j + 1, 0, 0, 1));
            answer = max(answer, dfs(nums1, nums2, i, j + 1, 1, 0, selected));
            answer = max(answer, dfs(nums1, nums2, i + 1, j, 0, 1, selected));
            answer = max(answer, dfs(nums1, nums2, i + 1, j + 1, 0, 0, selected));
        }
        
        return f[i][j][select1][select2][selected] = answer;
    }
};
