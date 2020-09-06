class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        multiset<int> appear_positive, appear_negative;
        int zero_count = 0;
        
        for (int a : A) {
            if (a > 0) {
                appear_positive.insert(a);
            } else if (a < 0) {
                appear_negative.insert(-a);
            } else if (a == 0) {
                zero_count++;
            }
        }
        
        if (zero_count % 2 == 1) return false;
        
        while (!appear_positive.empty()) {
            auto it1 = appear_positive.begin();
            const int number = *it1;
            auto it2 = appear_positive.find(2 * number);
            
            if (it2 != appear_positive.end()) {
                appear_positive.erase(it1);
                appear_positive.erase(it2);
            } else {
                return false;
            }
        }
        
        while (!appear_negative.empty()) {
            auto it1 = appear_negative.begin();
            const int number = *it1;
            auto it2 = appear_negative.find(2 * number);
            
            if (it2 != appear_negative.end()) {
                appear_negative.erase(it1);
                appear_negative.erase(it2);
            } else {
                return false;
            }
        }
        return true;
    }
};
