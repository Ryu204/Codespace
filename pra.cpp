#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

int m, n;
vector<vector<int>> children;
vector<int> p;
vector<vector<int>> adj;
vector<set<int>> parents;
vector<bool> visited;
map<pair<int, int>, int> value;


int main()
{
    cin >> n >> m;
    children.resize(n + 1);
    parents.resize(n + 1);
    adj.resize(n + 1);
    visited.resize(n + 1);
    p.resize(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    visited[1] = true; p[1] = 1;
    while(!q.empty())
    {
        int c = q.front();
        q.pop();
        for (auto& i : adj[c])
        {
            if (!visited[i])
            {
                p[i] = c;
                children[c].push_back(i);
                parents[i].insert(c);
                for (auto& cp : parents[c])
                    parents[i].insert(cp);
                visited[i] = true;
                q.push(i);
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u == v)
            continue;
        else if (parents[u].count(v))
            for (int up = u; up != v; up = p[up])
                value[pair(up, p[up])] = value[pair(up, p[up])] + 1;
        else if (parents[v].count(u))
            for (int vp = v; vp != u; vp = p[vp])
                value[pair(vp, p[vp])] = value[pair(vp, p[vp])] + 1;
        else
            for (int up = u; true; up = p[up])
            {
                if (parents[v].count(up))
                {
                    for (int vp = v; vp != up; vp = p[vp])
                        value[pair(vp, p[vp])] = value[pair(vp, p[vp])] + 1;
                    // cout << "up = " << up << '\n';
                    break;
                }
                value[pair(up, p[up])] = value[pair(up, p[up])] + 1;
            }
    }
    int mx = 0;
    for (auto& i : value)
        mx = max(mx, i.second);
    cout << mx;
}
