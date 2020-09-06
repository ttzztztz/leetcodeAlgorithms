class Solution {
public:
    /**
     * @param A: an array
     * @return: total of reverse pairs
     */
    long long reversePairs(vector<int> &A) {
        const int N = A.size();
        init(N);
        
        vector<int> all(A.begin(), A.end());
        sort(all.begin(), all.end());
        auto endIt = unique(all.begin(), all.end());
        for (int& i : A) i = lower_bound(all.begin(), endIt, i) - all.begin() + 1;
        
        long long answer = 0;
        for (int i = N - 1; i >= 0; i--) {
            const int number = A[i];
            
            answer += query(number - 1);
            inc(number, 1);
        }
        return answer;
    }
private:
    vector<long long> bit;
    void init(int N) {
        bit = vector<long long>(N + 5, 0);
    }
    int lowbit(int x) {
        return x&(-x);
    }
    long long query(int x) {
        long long answer = 0;
        while (x) {
            answer += bit[x];
            x -= lowbit(x);
        }
        return answer;
    }
    void inc(int x, int y) {
        while (x && x < bit.size()) {
            bit[x] += y;
            x += lowbit(x);
        }
    }
};
