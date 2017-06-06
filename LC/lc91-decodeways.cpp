#include<iostream>

using namespace std;

class Solution {
public:
	int ans;
	string s;
	int dp[10000];
	void dfs(int d){
		if(d>=s.length()){
			ans++;
			return;
		}
		if(s[d]=='0')
			return;
		dfs(d+1);
		if(s.length()-1>d){
			int p=(s.at(d)-'0')*10;
			p+=s.at(d+1)-'0';
			if(p>0&&p<=26)
				dfs(d+2);
		}
	}
	int v2(){
		for(int i=0;i<s.length();i++){
			if(i==0){
				dp[i]=1;
			}else if(i==1){
				int p=s.at(i-1)-'0';
				p=p*10+s.at(i)-'0';
				if(p>0&&p<=26){
					if(s.at(1)!='0')
						dp[i]=2;
					else
						dp[i]=1;
				}else if(s.at(i)!='0'){
					dp[i]=1;
				}
			}else{
				int p=s.at(i-1)-'0';
				p=p*10+s.at(i)-'0';
				if(s.at(i-1)!='0'&&p>0&&p<=26){
					dp[i]+=dp[i-2];
				}
				if(s.at(i)!='0')
					dp[i]+=dp[i-1];
				
			}
		}
		return dp[s.length()-1];
	}
    int numDecodings(string s) {
		ans=0;
		if(s.length()==0)
			return 0;
		this->s=s;
		if(s[0]=='0')
			return ans;
		ans=v2();
		return ans;
    }
};
int main(){
	Solution s;
	cout<<s.numDecodings("20134")<<endl;
	return 0;}
