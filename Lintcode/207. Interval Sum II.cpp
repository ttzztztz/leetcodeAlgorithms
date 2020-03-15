class Solution {
public:
    /* you may need to use some attributes here */

    /*
    * @param A: An integer array
    */
    Solution(vector<int> A) {
        const int N = A.size();
        data = vector<long long>(N + 5, 0);
        for (int i = 1; i <= N; i++) inc(i, A[i - 1]);
    }

    /*
     * @param start: An integer
     * @param end: An integer
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        start++, end++;
        return query(end) - query(start - 1);
    }

    /*
     * @param index: An integer
     * @param value: An integer
     * @return: nothing
     */
    void modify(int index, int value) {
        index++;
        const int cur = query(index) - query(index - 1);
        const int delta = value - cur;
        inc(index, delta);
    }
private:
    vector<long long> data;
    int lowbit(int x) {
        return x&(-x);
    }
    long long query(int x) {
        int answer = 0;
        while (x) {
            answer += data[x];
            x -= lowbit(x);
        }
        return answer;
    }
    void inc(int x, int y) {
        const int N = data.size();
        while (x && x < N) {
            data[x] += y;
            x += lowbit(x);
        }
    }
};
