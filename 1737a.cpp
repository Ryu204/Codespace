#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

ll n, t, k;
char a[500];

void sol()
{
    cin >> n >> k;
    vector<ll> c('z' + 1);
    vector<char> mex(k + 1);
    vector<ll> siz(k + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[a[i]] ++;
    }
    for (auto& i : mex)
        i = 'a';
    for (char x = 'a'; x <= 'y'; x++)
    {
        for (int i = 1; i <= k; i++)
        {
            if (siz[i] < n / k && c[x] > 0)
            {
                siz[i]++;
                if (mex[i] == x)
                    mex[i] = x + 1;
                c[x] --;
            }
        }
    }
    for (int i = 1; i <= k; i++)
        cout << mex[i];
    cout << '\n';
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--)
        sol();
}
