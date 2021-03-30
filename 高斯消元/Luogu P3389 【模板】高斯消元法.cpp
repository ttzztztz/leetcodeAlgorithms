#include <bits/stdc++.h>

using namespace std;

int main() {
  // freopen("./in.txt", "r", stdin);

  int n;
  cin >> n;
  vector<vector<double>> mat(n + 1, vector<double>(n + 2, 0.0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n + 1; j++) {
      cin >> mat[i][j];
    }
  }

  for (int j = 1; j <= n; j++) {
    int mx = j;
    for (int i = j + 1; i <= n; i++) {
      if (fabs(mat[i][j]) > fabs(mat[mx][j])) mx = i;
    }
    if (fabs(mat[mx][mx]) <= 1e-9) {
      printf("No Solution");
      return 0;
    }
    swap(mat[mx], mat[j]);

    for (int i = 1; i <= n; i++) {
      if (i == j) continue;

      const double t = mat[i][j] / mat[j][j];
      for (int k = 1; k <= n + 1; k++) {
        mat[i][k] -= mat[j][k] * t;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    printf("%.2f\n", mat[i][n + 1] / mat[i][i]);
  }
  return 0;
}