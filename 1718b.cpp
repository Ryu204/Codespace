#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll t, c[101], k, f[100], MAXN, mark;
vector<bool> d;

void prep()
{
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; f[i - 1] <= 1e9; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        MAXN = i;
    }
//    for (int i = 1; i <= 10; i++)
//        cout << f[i] <<  ' ';
//    cout << endl;
}

bool check(ll m)
{
    d.clear(); d.resize(100);
    for (int i = 1; i <= k; i++)
    {
        ll tmp = c[i];
        while (tmp)
        {
            ll left = 1, right = MAXN;
            while (left < right - 1)
            {
                ll mid = left + right >> 1;
                if (f[mid] <= tmp)
                    left = mid;
                else
                    right = mid;
            }
           // cout << "c[" << i << "] = " << tmp << endl << "left = " << left << endl;
            tmp -= f[left];
            if (d[left] || (i == m && left == 1) || left > mark)
                return false;
            d[left] = true;
        }
    }
    return true;
}

bool sol()
{
    cin >> k;
    ll s = 0;
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
        s += c[i];
    }
    s--;
    for (int i = 1; i <= MAXN; i++)
    {
        if (s == 0)
            break;
        if (s < 0)
            return false;
        s -= f[i];
        mark = i;
    }
    for (int i = 1; i <= k; i++)
    {
        if (c[i] > 0)
        {
            c[i]--;
            if (check(i))
                return true;
            c[i]++;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    prep();
    cin >> t;
    while (t--)
        if(sol())
            cout << "YES\n";
        else
            cout << "NO\n";
}
