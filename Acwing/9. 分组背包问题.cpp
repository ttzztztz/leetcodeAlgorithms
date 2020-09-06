#include<iostream>
using namespace std;

int dp[105];
int v[105], w[105];

int main() {
    int N, V;
    cin >> N >> V;
    
    for (int i = 0; i < N; i++) {
        int group = 0;
        cin >> group;
        
        for (int j = 1; j <= group; j++) cin >> v[j] >> w[j];
        
        for (int j = V; j >= 0; j--) {
            for (int k = 0; k <= group; k++) {
                if (j >= v[k]) {
                    dp[j] = max(dp[j], dp[j - v[k]] + w[k]);
                }
            }
        }
    }
    
    cout << dp[V] << endl;
    return 0;
}
