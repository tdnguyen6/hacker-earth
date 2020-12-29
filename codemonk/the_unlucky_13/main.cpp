#include <bits/stdc++.h>

using namespace std;
// using std::cout
// namespace chrono = std::chrono;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define watch(x) cout << (#x) << " is " << (x) << endl
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert(B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi = acos(-1.0);
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<ll> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

#define C 1000000009

void multiply(ll a[3][3], ll b[3][3]) 
{ 
    ll mul[3][3] = {0}; 
    for (ll i = 0; i < 3; i++) 
        for (ll j = 0; j < 3; j++) 
            for (ll k = 0; k < 3; k++) 
                {
                    mul[i][j] += (a[i][k] * b[k][j]) % C; 
                    if(mul[i][k] >= C) mul[i][k] -= C;
                    if(mul[i][k] < 0) mul[i][k] += C;
                }
  
    for (ll i=0; i<3; i++) 
        for (ll j=0; j<3; j++)
            a[i][j] = mul[i][j];
} 

ll M[3][3] = {
    {0, 99, -10},
    {1, 0, 0},
    {0, 1, 0}};
void matpowp(ll a[3][3], ll n) 
{

    if(n <= 1)
    	return;
    matpowp(a,n/2); 
    multiply(a,a); 
    if (n&1)
        multiply(a,M);
}
    

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto a = freopen("a.in", "r", stdin);
    // auto b = freopen("a.out", "w", stdout);
    // if (!a || !b)
    //     cout << "uh oh" << endl;
    string T = "13";
    ll t = T.length();
    // ll k = 10;
    ll matC[3][3] = {{99}, {10}, {1}};
    ll n_test;
    cin >> n_test;
    while (n_test--)
    {
        ll n;
        cin >> n;
        if (n >= C) n %= C;
        if (n < 2 * t - 1)
            cout << matC[t - n][0] << '\n';
        else
        {
            ll matB[3][3] = {
                {0, 99, -10},
                {1, 0, 0},
                {0, 1, 0}};
            matpowp(matB, n - 2);
            multiply(matB, matC);

            cout << matB[0][0] << '\n';
        }
    }
}