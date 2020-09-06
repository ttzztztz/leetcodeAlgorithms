#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        int N;
        cin >> N;
        vector<vector<int>> matrix(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> matrix[i][j];
            }
        }

        printf("Case #%d: ", _);
        int sum = 0;
        for (int i = 0; i < N; i++) sum += matrix[i][i];
        printf("%d ", sum);

        int row = 0;
        for (int i = 0; i < N; i++) {
            unordered_set<int> allNumber;
            for (int j = 0; j < N; j++) {
                allNumber.insert(matrix[i][j]);
            }
            if (allNumber.size() != N) {
                row++;
            }
        }

        printf("%d ", row);

        int col = 0;
        for (int i = 0; i < N; i++) {
            unordered_set<int> allNumber;
            for (int j = 0; j < N; j++) {
                allNumber.insert(matrix[j][i]);
            }
            if (allNumber.size() != N) {
                col++;
            }
        }

        printf("%d ", col);
        printf("\n");
    }

    return 0;
}
