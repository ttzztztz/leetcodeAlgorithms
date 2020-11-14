class Solution {
public:
    /**
     * @param arr: the array
     * @return: determine the number of moves to make all elements equals
     */
    long long arrayGame(vector<int> &arr) {
        typedef long long ll;
        ll ttl = 0;
        const int n = arr.size();
        for (int i : arr) ttl += (ll) i;
        const int mi = *min_element(arr.begin(), arr.end());
        return ttl - 1ll * mi * n;
    }
};
