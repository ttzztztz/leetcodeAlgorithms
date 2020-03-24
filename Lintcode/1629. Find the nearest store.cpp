class Solution {
public:
    /**
     * @param stores: The location of each store.
     * @param houses: The location of each house.
     * @return: The location of the nearest store to each house.
     */
    vector<int> findNearestStore(vector<int> &stores, vector<int> &houses) {
        const int N = stores.size(), M = houses.size();
        vector<int> answer(M);
        sort(stores.begin(), stores.end());
        for (int i = 0; i < M; i++) {
            auto it = lower_bound(stores.begin(), stores.end(), houses[i]);
            if (it == stores.begin()) {
                answer[i] = *it;
                continue;
            }
            if (it == stores.end()) {
                answer[i] = *(it - 1);
                continue;
            }
            
            it--;
            if (houses[i] - *it <= *(it + 1) - houses[i]) {
                answer[i] = *it;
            } else {
                answer[i] = *(it + 1);
            }
        }
        return answer;
    }
};
