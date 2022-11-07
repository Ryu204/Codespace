#include <iostream>
using namespace std;
typedef long long ll;

constexpr ll N = 2e6;
ll t, n, a[N], b[N];

void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char tmp;
        cin >> tmp;
        a[i] = tmp - '0';
    }
    for (int i = 1; i <= n; i++)
    {
        char tmp;
        cin >> tmp;
        b[i] = tmp - '0';
    }
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += abs(a[i] - b[i]);
    if (cnt != 0 && cnt != n)
    {
        cout << "NO\n";
        return;
    }
    cnt = 0;
    cout << "YES\n";
    for (int i = 2; i <= n; i++)
        if (a[i])
            cnt++;
    if (abs(cnt - b[1]) % 2)
    {
        cout << cnt + 3 + a[1] << '\n';
        for (int i = 1; i <= n; i++)
            if (a[i])
                cout << i << ' ' << i << '\n';
        cout << "1 " <<  n << "\n1 1\n2 " << n << '\n';
    }
    else
    {
        cout << cnt + a[1] << '\n';
        for (int i = 1; i <= n; i++)
            if (a[i])
                cout << i << ' ' << i << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--)
        sol();
}

