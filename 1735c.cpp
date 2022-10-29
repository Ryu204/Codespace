#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;

string s, t;
ll n;

vector<int> p('z' + 1), r('z' + 1);

void init()
{
    for (int i = 'a'; i <= 'z'; i++)
    {
        p[i] = i;
        r[i] = 0;
    }
}

int get(int x)
{
    if (x == p[x])
        return x;
    p[x] = get(p[x]);
    return p[x];
}

void combine(int x, int y)
{
    int a = get(x);
    int b = get(y);
    if (a != b)
    {
        if (r[a] < r[b])
            swap(a, b);
        p[b] = a;
        if (r[a] == r[b])
            r[a]++;
    }
}

void sol()
{
    init();
    cin >> n >> t;
    vector<bool> ap('z' + 1);
    vector<char> func('z' + 1);
    queue<char> ord;
    for (int i = 0; i < t.length(); i++)
    {
        if (!ap[t[i]])
        {
            ap[t[i]] = true;
            ord.push(t[i]);
        }
    }
    for (char c = 'a'; c <= 'z'; c++)
        if (!ap[c])
            ord.push(c);

    ap.clear(); ap.resize('z' + 1);
    while (!ord.empty())
    {
        char c = ord.front();
        ord.pop();
        for (char h = 'a'; h <= 'z'; h++)
        {
            if (ap[h] == false && (ord.empty() || get(h) != get(c)))
            {
                ap[h] = true;
                func[c] = h;
                combine(c, h);
                break;
            }
        }
    }
    for (int i = 0; i < t.length(); i++)
        cout << func[t[i]];
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int l;
    cin >> l;
    while (l --)
        sol();
}

