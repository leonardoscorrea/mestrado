#include <bits/stdc++.h>
#define inf 2147483600
using namespace std;

int n, lim, q[1005], dp[1005][1005];

int func(int a, int k)
{
    if (k == lim && a >= n)
        return 0;
    if (k == lim || a >= n)
        return inf;
    if (dp[a][k] != -1)
        return dp[a][k];
    int ret = inf;
    for (int i = 0; a + i < n; i++)
    {
        ret = min(ret, func(a + i + 1, k + 1) + (q[a + i] - q[a]));
    }
    return dp[a][k] = ret;
}

int main(void)
{
    q[0] = 0;
    while (scanf("%d%d", &n, &lim) != EOF)
    {
        for (int i = 1; i < n; i++)
            scanf("%d", &q[i]);
        memset(dp, -1, sizeof dp);
        printf("%d\n", func(0, 0));
    }
    return 0;
}