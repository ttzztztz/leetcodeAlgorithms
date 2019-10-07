#include <iostream>
#include <cstring>
#include <vector>

//#define DEBUG 1

using namespace std;

int A[20], B[20], visited[20], N;
vector<vector<int>> A_sum, B_sum;

void init() {
    std::memset(A, 0, sizeof(A));
    std::memset(B, 0, sizeof(B));

    A_sum.clear();
    B_sum.clear();
}

void prepare2(const int *target, vector<vector<int>> &targetSum) {
    for (int ptr1 = 0; ptr1 < 3 * N; ptr1++) {
        for (int ptr2 = ptr1 + 1; ptr2 < 3 * N; ptr2++) {
            for (int ptr3 = ptr2 + 1; ptr3 < 3 * N; ptr3++) {
                if (visited[ptr1] || visited[ptr2] || visited[ptr3]) {
                    continue;
                }

                visited[ptr1] = visited[ptr2] = visited[ptr3] = 2;

                vector<int> temp = {0, 0, 0};
                for (int i = 0; i < 3 * N; i++) {
                    temp[visited[i]] += target[i];
                }
                targetSum.push_back(temp);

                visited[ptr1] = visited[ptr2] = visited[ptr3] = 0;
            }
        }
    }
}

void prepare1(const int *target, vector<vector<int>> &targetSum) {
    memset(visited, 0, sizeof(visited));
    for (int ptr1 = 0; ptr1 < 3 * N; ptr1++) {
        for (int ptr2 = ptr1 + 1; ptr2 < 3 * N; ptr2++) {
            for (int ptr3 = ptr2 + 1; ptr3 < 3 * N; ptr3++) {
                visited[ptr1] = visited[ptr2] = visited[ptr3] = 1;

                prepare2(target, targetSum);

                visited[ptr1] = visited[ptr2] = visited[ptr3] = 0;
            }
        }
    }
}

int main() {
    int testCases = 0;
    cin >> testCases;
    for (int _ = 1; _ <= testCases; _++) {
        init();
        double answer = 0.0;
        cin >> N;
        for (int i = 0; i < 3 * N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < 3 * N; i++) {
            cin >> B[i];
        }
        prepare1(A, A_sum);
        prepare1(B, B_sum);

        for (int i = 0; i < A_sum.size(); i++) {
            int finalCount = 0;

            for (int j = 0; j < B_sum.size(); j++) {
                int winCount = 0;
                for (int k = 0; k < 3; k++) {
                    if (A_sum[i][k] > B_sum[j][k]) {
                        winCount++;
                    }
                }

                if (winCount >= 2) {
                    finalCount++;
                }
            }

            answer = std::max(answer, 1.0 * finalCount / A_sum.size());
        }

        printf("Case #%d: %.6lf \n", _, answer);
    }

    return 0;
}
