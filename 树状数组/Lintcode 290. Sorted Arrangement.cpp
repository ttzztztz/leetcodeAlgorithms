class Solution {
public:
    /**
     * @param nums: the array of elements to be inserted.
     * @return: return the least operation number.
     */
    long long sortedArrangement(vector<int> &nums) {
        long long answer = 0;
        memset(data, 0, sizeof data);
        
        int sze = 0;
        for (int i : nums) {
            inc(i, 1);
            sze++;

            const int d = query(i) - 1;
            const int g = sze - d - 1;
            answer += min(2 * d + 1, 2 * g + 1);
        }
        
        return answer;
    }
private:
    int data[100005];
    int lowbit(int x) {
        return x&(-x);
    }
    int query(int x) {
        int answer = 0;
        while (x) {
            answer += data[x];
            x -= lowbit(x);
        }
        return answer;
    }
    void inc(int x, int y) {
        while (x && x <= 100000) {
            data[x] += y;
            x += lowbit(x);
        }
    }
};
