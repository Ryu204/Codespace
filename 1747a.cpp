#include <iostream>
using namespace std;
typedef long long ll;

constexpr ll N = 2e6;
ll t, n, a;

void sol()
{
    ll s1 = 0, s2 = 0;
    cin >> n;
    while (n--)
    {
        cin >> a;
        s1 += a;
    }
    cout << abs(s1) << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--)
        sol();
}

