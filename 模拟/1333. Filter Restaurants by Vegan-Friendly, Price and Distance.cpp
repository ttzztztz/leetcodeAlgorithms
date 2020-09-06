class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> answer;
        const int N = restaurants.size();
        for (int i = 0; i < N; i++) {
            const vector<int>& r = restaurants[i];
            bool b1 = true;
            if (veganFriendly == 1) {
                b1 = r[2] == 1;
            }
            bool b2 = r[3] <= maxPrice;
            bool b3 = r[4] <= maxDistance;
            
            if (b1 && b2 && b3) {
                answer.push_back(i);
            }
        }
        
        sort(answer.begin(), answer.end(), [&](const int $1, const int $2)->bool {
            if (restaurants[$1][1] == restaurants[$2][1]) {
                return restaurants[$1][0] > restaurants[$2][0];
            }
            return restaurants[$1][1] > restaurants[$2][1];
        });
        
        for (int& r : answer) {
            r = restaurants[r][0];
        }
        return answer;
    }
};
