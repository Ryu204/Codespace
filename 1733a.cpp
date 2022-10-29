#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

constexpr ll N = 1e5 + 10;
ll a[N], n, t, k;

void sol()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    std::vector<std::vector<int>> l(k);
    for (int i = 1; i <= n; i++)
        l[i%k].push_back(a[i]);
    ll sum = 0;
    for(auto& v : l)
    {
        sum += *max_element(v.begin(), v.end());
    }
    cout << sum << '\n';
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t --)
        sol();
}
