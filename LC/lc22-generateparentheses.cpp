#include<iostream>
#include<vector>
using namespace std;


class Solution{
public:
	int n,lc, rc;
	int stack;
	string ans;
	vector<string> ansset;
	void append(int lr, int d){
		if(d==n*2 && !stack){
			ansset.push_back(ans);
			cout<<ans<<endl;
			return;
		}
		if((lr==0&&lc==0) ||(lr==1&&(rc==0||stack==0)))
			return;

		if(lr==0){
			ans+="(";
			stack++;
			lc--;
			append(0, d+1);
			if(d<n*2-1)
			append(1, d+1);	
			stack--;
			lc++;
			ans=ans.substr(0,ans.length()-1);
		}
		if(lr==1){
			ans+=")";
			stack--;
			rc--;
			append(0,d+1);
			if(d<n*2-1)
			append(1,d+1);
			stack++;
			rc++;
			ans=ans.substr(0,ans.length()-1);
		}
	}

	vector<string> generateParenthesis(int n){
		lc=n;
		rc=n;
		this->n=n;
		ans="";
		ansset.clear();
		stack=0;
		append(0, 0);
		return ansset;
	}
};
int main(){
	Solution s;
	s.generateParenthesis(3);
	cout<<endl;
	s.generateParenthesis(4);
	return 0;
}
