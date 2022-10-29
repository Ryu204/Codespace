#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

constexpr ll N = 2e6;
ll t, n, q, a[N], p[N], s[N];

void sol()
{
    cin >> n >> q;
    set<ll> se;
    vector<map<ll, vector<ll>>> v(2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i] = p[i - 1] ^ a[i];
        s[i] = s[i - 1] + a[i];
        v[i % 2][p[i]].push_back(i);
    }

//    for (int i = 1; i <= n; i++)
//        cout << p[i] << ' ';
//    cout << '\n';
//    for (int i = 1; i <= n; i++)
//        cout << s[i] << ' ';
//    cout << '\n';
//    for (auto& i : v)
//    {
//        for (auto& pr : i)
//        {
//            cout << pr.first << " : ";
//            for (auto& ii : pr.second)
//                cout << ii << ' ';
//            cout << '\n';
//        }
//        cout << '\n';
//    }

    for (int i = 1; i <= q; i++)
    {
        ll le, ri;
        cin >> le >> ri;
        if (p[ri] ^ p[le - 1])
            cout << "-1\n";
        else if (s[ri] - s[le - 1] == 0)
            cout << "0\n";
        else if ((ri - le + 1) % 2 == 1)
            cout << "1\n";
        else if (a[le] == 0 || a[ri] == 0)
            cout << "1\n";
        else
        {
            auto& vec = v[le % 2][p[le - 1]];
            if (vec.empty())
            {
                cout << "-1\n";
                continue;
            }
            const auto& itr = lower_bound(vec.begin(), vec.end(), le);
            if (itr != vec.end() && *itr <= ri)
                cout << "2\n";
            else
                cout << "-1\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    t = 1;
    while (t--)
        sol();
}


