#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, t, a[4][2];

void sol()
{
    cin >> n;
    for (int i = 1; i <= 3; i++)
        cin >> a[i][0] >> a[i][1];
    cin >> a[0][0] >> a[0][1];

    for (int i = 1; i <= 3; i++)
        if (a[i][0] == a[0][0] && a[i][1] == a[0][1])
        {
            cout << "YES\n";
            return;
        }

    vector<int> c(4);
    for (int i = 1; i <= 3; i++)
        for (int j = i + 1; j <= 3; j++)
        {
            if (a[i][0] == a[j][0] || a[i][1] == a[j][1])
            {
                c[i]++;
                c[j]++;
            }
        }
    ll ans = 1;
    for (int i = 1; i <= 3; i++)
        if (c[i] > c[ans])
            ans = i;
    if (a[ans][0] == a[0][0] || a[ans][1] == a[0][1])
    {
        cout << "YES\n";
        return;
    }
    if ((1 - a[ans][0]) * (n - a[ans][0]) == 0 && (1 - a[ans][1]) * (n - a[ans][1]) == 0)
    {
        cout << "NO\n";
        return;
    }

    if ((a[ans][0] - a[0][0]) % 2 != 0 && (a[ans][1] - a[0][1]) % 2 != 0)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--)
        sol();
}

