#include<iostream>
#include<string.h>
using namespace std;

class Solution {
public:
	int fac[10];
	int vis[100];
    string getPermutation(int n, int k) {
		for(int i=1; i<n;i++){
			if(i==1){
				fac[i]=1;
			}else{
				fac[i]=i*fac[i-1];
			}
		}
		string ans="";
		if(n==1)
			return "1";
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			int a;
			if(k==0){
				for(int t=n;t>0;t--)
					if(!vis[t])
						ans+='0'+t;
				break;
			}
			else{
				a=(k-1)/fac[n-i];
			}
			k%=fac[n-i];
			int c=0;
			int j;
			for(j=0;j<n&&c<=a;j++){
				if(vis[j+1])
					continue;
				c++;
			}
			ans+='0'+j;
			vis[j]=1;
		}
		return ans;
    }
};
int main(){
	Solution s;
	cout<<s.getPermutation(2,1);
	return 0;}
