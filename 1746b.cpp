#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

ll n, t, a[100010];

void sol()
{
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    stack<int> c;
    for (int i = 1; i <= n; i++)
        if (a[i] == 0)
            c.push(i);
    for (int i = 1; i <= n; i++)
    {
        if (c.empty() || c.top() < i)
            break;
        if (a[i] == 1)
        {
            a[c.top()] = 1;
            c.pop();
            ans++;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--)
        sol();
}

