#include <vector>
#include <iostream>
#include <map>
using namespace std;

typedef vector<int> Seq;

Seq add(const Seq& a, const Seq& b)
{
    Seq c(a);
    for (const auto& i : b)
        c.push_back(i);
    return c;
}

int n, c[2010];
Seq s[2010], children[2010];
bool bakana;

void make(int vertex)
{
    if (!s[vertex].empty())
        return;
    for (auto& i : children[vertex])
    {
        make(i);
        s[vertex] = add(s[vertex], s[i]);
    }
    if (c[vertex] > s[vertex].size())
    {
        bakana = true;
        return;
    }
    s[vertex].insert(s[vertex].begin() + c[vertex], vertex);
}

int main()
{
    cin >> n;
    int root;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p >> c[i];
        if (!p)
            root = i;
        children[p].push_back(i);
    }
    make(root);
    if (bakana)
        cout << "NO";
    else
    {
        cout << "YES\n";
        Seq tmp(n + 1);
        int val = 0;
        for (auto& i : s[root])
            tmp[i] = ++val;
        for (int i = 1; i <= n; i++)
            cout << tmp[i] << ' ';
    }
}
