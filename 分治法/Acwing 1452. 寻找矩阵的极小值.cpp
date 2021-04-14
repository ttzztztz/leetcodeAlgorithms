// Forward declaration of queryAPI.
// int query(int x, int y);
// return int means matrix[x][y].
bool is_cache[301][301];
int cache[301][301];
class Solution {
 public:
  vector<int> getMinimumValue(int n) {
    this->n = n;
    memset(is_cache, 0, sizeof is_cache);
    memset(cache, 0, sizeof cache);

    int xl = 0, xr = n - 1, yl = 0, yr = n - 1;
    while (xl <= xr && yl <= yr) {
      const int midx = (xl + xr) / 2, midy = (yl + yr) / 2;

      const int dx[] = {0, 0, -1, 1};
      const int dy[] = {-1, 1, 0, 0};
      int min_val = get(midx, midy), min_x = midx, min_y = midy;
      for (int i = 0; i < n; i++) {
        if (i != midx) {
          const int t1 = get(i, midy);
          if (t1 < min_val) {
            min_val = t1;
            min_x = i, min_y = midy;
          }
        }

        if (i != midy) {
          const int t2 = get(midx, i);
          if (t2 < min_val) {
            min_val = t2;
            min_x = midx, min_y = i;
          }
        }
      }

      const int t = valid(min_x, min_y, min_val);
      if (t == -1)
        return vector<int>{min_x, min_y};
      else if (t == 0)
        yr = midy - 1;
      else if (t == 1)
        yl = midy + 1;
      else if (t == 2)
        xr = midx - 1;
      else if (t == 3)
        xl = midx + 1;

      if (min_x < midx)
        xr = midx - 1;
      else if (min_x > midx)
        xl = midx + 1;

      if (min_y < midy)
        yr = midy - 1;
      else if (min_y > midy)
        yl = midy + 1;
    }
    return {};
  }

 private:
  int n;
  bool point_valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < n; }

  int get(int i, int j) {
    if (!point_valid(i, j)) {
      return numeric_limits<int>::max();
    } else {
      if (is_cache[i][j]) {
        return cache[i][j];
      } else {
        is_cache[i][j] = true;
        return cache[i][j] = query(i, j);
      }
    }
  }

  int valid(int x, int y, int val) {
    const int dx[] = {0, 0, -1, 1};
    const int dy[] = {-1, 1, 0, 0};

    int min_k = -1;
    for (int k = 0; k < 4; k++) {
      const int t = get(x + dx[k], y + dy[k]);
      if (t < val) {
        val = t;
        min_k = t;
      }
    }
    return min_k;
  }
};