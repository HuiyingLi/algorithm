#include<string.h>
#include<iostream>
using namespace std;
class Solution {
public:
    int dp[1000][1000];
    int dfs(int s, int e){
        //cout<<s<<" "<<e<<":\n";
		if(e-s<1) return 0;
        //cout<<"dpv val:"<<dpv[e-s]<<endl;
        if(dp[s][e]!=-1){
            return dp[s][e];
        }
        int mmin=2147483647;
        for(int i=s;i<=e;i++){//i the pivot
            int v=i;
            int lv=0,rv=0;
            lv=dfs(s,i-1);
            rv=dfs(i+1,e);
            //if(s==2&&e==4){
            //    cout<<v<<" "<<lv<<" "<<rv<<endl;
            //}
            v+=lv>rv?lv:rv;
           
            if(v<mmin)
                dp[s][e]=v,mmin=v;
        }
        //cout<<s<<" "<<e<<":"<<mmin<<endl;
        return mmin;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        //dp[0]=0,dp[1]=0;
        return dfs(1,n);
    }
};
int main(){
	Solution s;
	cout<<s.getMoneyAmount(8);
	
}
