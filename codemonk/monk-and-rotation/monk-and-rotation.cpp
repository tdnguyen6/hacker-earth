#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

void solve()
{
    int n, k;
    cin >> n >> k;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        int index = i + k >= n ? i + k - n : i + k;
        cin >> ar[index];
    }
    for (int i = 0; i < n; i++)
    {
        cout << ar[i];
        if (i < n - 1)
            cout << ' ';
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        solve();
    }
}