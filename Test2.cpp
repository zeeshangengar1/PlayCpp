#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define fl(n) for (int i = 0; i < n; i++)
#define flj(n) for (int j = 0; j < n; j++)
#define flo(n) for (int i = 1; i <= n; i++)
#define mii map<int, int>
#define mci map<char, int>
#define V vector<int>
#define vp vector<pair<int, int>>
#define pb push_back
#define pp pair<int, int>
#define ff first
#define ss second
#define S set<int>
#define all(v) v.begin(), v.end()
#define gr greater<int>()
#define show2(a, b) cout << a << ' ' << b << endl;
#define show3(a, b, c) cout << a << ' ' << b << ' ' << c << endl;
#define print(arr)     \
    for (auto i : arr) \
        cout << i << ' ';
const long long mod = 1000000007;
const int N = 1e5 + 5;
const long double PI = 3.14159265358;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> val;
void dfs(int j)
{
    vis[j] = true;
    for (auto u : adj[j])
    {
        if (!vis[u])
        {
            dfs(u);
            cout << j << ' ';
        }
    }
}

const int inf = 1e7;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    int arr[200001] = {0};
    for (int i = 1; i <= 200000; i++)
    {
        int z = i;
        while (z % 2 == 0)
        {
            z /= 2;
            arr[i]++;
        }
    }
    for (int l = 1; l <= T; l++)
    {
        int n, cnt = 0;
        cin >> n;
        int a[n];
        fl(n)
        {
            cin >> a[i];
            int z = a[i];
            while (z % 2 == 0)
            {
                cnt++;
                z /= 2;
            }
        }
        if (cnt >= n)
            cout << 0 << endl;
        else
        {
            int z = n - cnt;
            vector<int> v;
            for (int i = 1; i <= n; i++)
            {
                if (arr[i] > 0)
                    v.push_back(arr[i]);
            }
            sort(all(v), greater<int>());
            int ans = 0;
            for (auto i : v)
            {
                if (z >= i)
                {
                    z -= i;
                    ans++;
                }
            }
            if (z == 0)
                cout << ans << endl;
            else
                cout << -1 << endl;
        }
    }
    return 0;
}