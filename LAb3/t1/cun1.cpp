#include<iostream>
using namespace std;
int n;
int ques;
long long map[3005][3005];
long long x[3005];
long long y[3005];
long long dis[3005];
bool vis[3005];
long long ans=0;
void prim()
{
    for( int i=1;i<=n;i++)
    {
        dis[i]=23372036854775806;
    }
    dis[1]=0;
    dis[0]=23372036854775806;
    while(1)
    {
        int u=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0&&dis[i]<dis[u])
            {
                u=i;
            }
        }
        if(u==0)
        {
            break;
        }
        vis[u]=1;
        ans+=dis[u];
        for(int i=1;i<=n;i++)
        {
            dis[i]=min(dis[i],map[u][i]);
        }
    }
}


int main()
{
    cin>>n>>ques;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            map[i][j] = abs(x[i]-x[j]) * abs(x[i]-x[j]) * abs(x[i]-x[j]) + abs(y[i]-y[j]) * abs(y[i]-y[j]) * abs(y[i]-y[j]);
        }
    }
    prim();
    cout<<ans<<endl;
    return 0;
}