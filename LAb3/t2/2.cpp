#include <iostream>
#include <vector>
using namespace std;

int mycolornum=1;
const int N = 20; 
vector<int> G[N];   
int color[N];      
int n;             
int m;       


void dfs(int u)
{
    //cout<<u<<endl;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (color[v] == 0) // 如果节点v未着色
        {
            bool flag = 1;
            for (int j = 1; j <= n; j++)
            {
                bool ok = 1;
                for (int k = 0; k < G[v].size(); k++)
                {
                    if (color[G[v][k]] == j)
                    {
                        ok = 0;
                        break;
                    }
                }
                if (ok)
                {
                    color[v] = j;
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                mycolornum++;
                color[v] = mycolornum;
            }
            dfs(v);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    color[1]=1;
    dfs(1);
   // cout << mycolornum << endl;
   int ans=color[1];
    for(int i=1;i<=n;i++)
    {
        if(color[i]>ans)
        {
            ans=color[i];
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<color[i]<<" ";
    }

}