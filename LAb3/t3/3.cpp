#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
struct edge
{
    int to;
    long long cap;
    long long state;
};
long long zeng;

vector<edge> G[50];
long long dotcap[50];
long long ans = 0;
bool is_vis[50];
long long dotnow[50] = {0};
int from[50];

bool find_path()
{
    int dotadd[50];
    for (int i = 0; i <= n+1; i++)
    {
        is_vis[i] = 0;
        dotadd[i] = 0;
    }
    queue<int> route;
    route.push(0);
    is_vis[0] = 1;
    dotadd[0] = dotcap[0] - dotnow[0];
    if(dotadd[0]<=0)
    {
        return 0;
    }
    while (route.size() > 0)
    {
        int tmp = route.front();
        route.pop();
        for (int i = 0; i < G[tmp].size(); i++)
        {
            int nex = G[tmp][i].to;
            //cout<<nex<<":";
            if ((is_vis[nex] == 0 )&& (dotcap[nex] - dotnow[nex] > 0) && (G[tmp][i].state < G[tmp][i].cap))
            {
                int x = min(dotcap[nex] - dotnow[nex], G[tmp][i].cap - G[tmp][i].state);
                x = min(x, dotadd[tmp]);
                dotadd[nex] = x;
                is_vis[nex] = 1;
                from[nex] = tmp;
                if (nex == n + 1)
                {
                    zeng = x;
                    int t = n + 1;
                    while (t != 0)
                    {
                        int l = t;
                        dotnow[t] += x;
                        t = from[t];
                        int k;
                        for (int i = 0; i < G[t].size(); i++)
                        {
                            if (G[t][i].to == l)
                            {
                                G[t][i].state += x;
                                break;
                            }
                        }
                    }
                    dotnow[0]+=x;
                    return 1;
                }
                else
                {
                    route.push(nex);
                }
                
            }
        }
    }
    return 0;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        cin >> dotcap[i];
    }
    dotcap[n+1]=10000000005;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        long long va;
        cin >> x >> y >> va;
        if (va == -1)
        {
            va = 200000000000;
        }
        if(va==0)
        {
            continue;
        }
        bool flag = 0;
        for (int j = 0; j < G[x].size(); j++)
        {
            if (G[x][j].to == y)
            {
                G[x][j].cap += va;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            struct edge e = {y, va, 0};
            G[x].push_back(e);
        }
    }
    while (find_path() == 1)
    {
        ans += zeng;
    }
    cout << ans;
    return 0;
}