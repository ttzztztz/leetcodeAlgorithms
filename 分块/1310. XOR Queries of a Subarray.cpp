class Query {
public:
    int L, R, index;
    Query() : L(0), R(0), index(0) {};
    Query(int l, int r, int i) : L(l), R(r), index(i) {};
};
const int MAX = 30005;
class Solution {
public:
    int N, M, K, blockNumber, blockSize;
    long long answer[MAX];
    Query queryList[MAX];
    void init() {
        blockSize = sqrt(N);
        blockNumber = N / blockSize;
        if (N % blockSize) {
            blockNumber++;
        }
    }
    int belong(int index) {
        return (index - 1) / blockSize + 1;
    }
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        N = arr.size(), M = queries.size();
        vector<int> answer(M, 0);
        
        int i = 0;
        for (const auto& query : queries) {
            queryList[i] = {query[0], query[1], i};
            i++;
        }
        
        init();
        sort(queryList, queryList + M, [&](const Query &$1, const Query &$2) -> bool {
            if (belong($1.L) == belong($2.L)) {
                return $1.R < $2.R;
            } else {
                return $1.L < $2.L;
            }
        });

        int temp = 0, l = 1, r = 0;
        for (int i = 0; i < M; i++) {
            const auto& q = queryList[i];
            int _i = q.index, L = q.L, R = q.R;
            
            while (l < L) {
                temp ^= arr[l];
                l++;
            }
            while (l > L) {
                l--;
                temp ^= arr[l];
            }
            while (r < R) {
                r++;
                temp ^= arr[r];
            }
            while (r > R) {
                temp ^= arr[r];
                r--;
            }
            answer[_i] = temp;
        }

        return answer;
    }
};
