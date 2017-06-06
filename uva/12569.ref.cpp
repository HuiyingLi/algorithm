# include<iostream>
# include<cstdio>
# include<string>
# include<queue>
# include<vector>
# include<cstring>
# include<algorithm>
using namespace std;

struct Edge
{
    int to,nxt;
};

struct node
{
    int t,u,sta;
    string path;
    node(int _t,int _u,int _s,string _p):t(_t),u(_u),sta(_s),path(_p){}
    bool operator < (const node &a) const {
        return t>a.t;
    }
};
Edge e[32];
int n,cnt,head[16],vis[15][1<<15];

void add(int u,int v)
{
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt++;
}
void bfs(int s,int st,int ed)
{
    priority_queue<node>q;
    memset(vis,0,sizeof(vis));
    vis[s][st]=1;
    q.push(node(0,s,st,""));
    while(!q.empty())
    {
        node u=q.top();
        q.pop();
        if(u.u==ed){
            printf("%d\n",u.t);
            for(int i=0;i<u.path.size();i+=2)
                printf("%d %d\n",u.path[i]-'A'+1,u.path[i+1]-'A'+1);
            return ;
        }
        for(int i=0;i<n;++i){
            if(u.sta&(1<<i)){
                for(int j=head[i];j!=-1;j=e[j].nxt){
                    int v=e[j].to;
                    if(u.sta&(1<<v))
                        continue;
                    if(v==u.u)
                        continue;
                    int ns=u.sta^(1<<i);
                    ns|=(1<<v);
                    if(!vis[u.u][ns]){
                        vis[u.u][ns]=1;
                        string p=u.path;
                        p+=(char)(i+'A'),p+=(char)(v+'A');
                        q.push(node(u.t+1,u.u,ns,p));
                    }
                }
            }
        }
        for(int i=head[u.u];i!=-1;i=e[i].nxt)
        {
            int v=e[i].to;
            if(u.sta&(1<<v))
                continue;
            if(!vis[v][u.sta]){
                vis[v][u.sta]=1;
                string p=u.path;
                p+=(char)(u.u+'A'),p+=(char)(v+'A');
                q.push(node(u.t+1,v,u.sta,p));
            }
        }
    }
    printf("-1\n");
}
int main()
{
    int T,a,b,s,t,st,m,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        st=cnt=0;
        memset(head,-1,sizeof(head));
        scanf("%d%d%d%d",&n,&m,&s,&t);
        --s,--t;

        while(m--)
        {
            scanf("%d",&a);
            st|=(1<<(a-1));
        }
        for(int i=1;i<n;++i){
            scanf("%d%d",&a,&b);
            add(a-1,b-1);
            add(b-1,a-1);
        }
        printf("Case %d: ",++cas);
        bfs(s,st,t);
        if(T)
            printf("\n");
    }
    return 0;
}
