#include <iostream>
#include <vector>
#include <set>
using namespace std;

long long n, k;
char a[100010], b[100010];
bool visit['z' + 1];

// generate kCv.size() sets
void gen(long long i, long long kk, long long& ans, const vector<char>& v)
{
    if (kk > k)
        return;
    if (i > v.size())
        return;
    if (i == v.size())
    {
        long long c = 0, tmp = 0;
        for (long long j = 1; j <= n; j++)
        {
            bool s = visit[a[j]] || (a[j] == b[j]);
            if (s)
                c++;
            else
            {
                tmp += c * (c - 1) / 2 + c;
                c = 0;
            }
        }
        ans = max(ans, tmp + c * (c - 1) / 2 + c);
        return;
    }
    visit[v[i]] = true;
    gen(i + 1, kk + 1, ans, v);
    visit[v[i]] = false;
    gen(i + 1, kk, ans, v);
}

void sol()
{
    for (char i = 'a'; i <= 'z'; i++)
        visit[i] = false;
    vector<bool> d('z' + 1);
    vector<char> v;
    cin >> n >> k;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (!d[a[i]])
        {
            d[a[i]] = true;
            v.push_back(a[i]);
        }
    }
    for (long long i = 1; i <= n; i++)
        cin >> b[i];
    long long ans = 0;
    gen(0, 0, ans, v);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin >> t;
    while (t--)
        sol();
}

