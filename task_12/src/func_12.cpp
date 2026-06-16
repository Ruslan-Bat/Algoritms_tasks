#include <vector>
using namespace std;

int func(int S, int N, vector<int>& coins ) {

    const int INF = S + 1;
    vector<int> dp(S + 1, INF);
    
    dp[0] = 0;

    for (int i = 1; i <= S; ++i) {
        for (int coin : coins) {
            if (i >= coin && dp[i - coin] != INF) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    if (dp[S] == INF) {
        return -1;
    } else {
        return dp[S];
    }
}