#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;

int p[maxn], q[maxn];

int Run(int n)
{
    for(int st = 0; st < n; st++){
        int oil = 0;
        int i;
        for(i = 0; i < n; i++){
            int cur = (i+st)%n;
            oil += p[cur];

            if(oil<q[cur]){ st += i; break; }
            oil -= q[cur];
        }
        if(i == n) return st;
    }
    return -1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int T; scanf("%d",&T);
    for(int k = 1; k <= T; k++){
        int n;scanf("%d",&n);
        for(int i = 0; i < n; i++) scanf("%d",p+i);
        for(int i = 0; i < n; i++) scanf("%d",q+i);
        printf("Case %d: ",k);
        int ans = Run(n);
        if(~ans) printf("Possible from station %d\n",ans+1);
        else puts("Not possible");
    }
    return 0;
}
