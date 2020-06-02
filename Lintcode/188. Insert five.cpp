class Solution {
public:
    /**
     * @param a: A number
     * @return: Returns the maximum number after insertion
     */
    int InsertFive(int a) {
        string s = to_string(a);
        
        bool inserted = false;
        const int N = s.size();
        if (s[0] == '-') {
            s.erase(s.begin());
            for (int i = 0; i < N; i++) {
                if (s[i] >= '5') {
                    inserted = true;
                    s.insert(s.begin() + i, '5');
                    break;
                }
            }
            s = '-' + s;
        } else {
            for (int i = 0; i < N; i++) {
                if (s[i] <= '5') {
                    inserted = true;
                    s.insert(s.begin() + i, '5');
                    break;
                }
            }
            if (!inserted) s += '5';
        }
        
        return stoi(s);
    }
};
