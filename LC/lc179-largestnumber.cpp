#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

class Solution{
public:
	vector<string> n;
	string ans;
	string mans;
	int L;
	int vis[10000];
	void dfs(int d){
		
		int l=ans.length();
		int ml=mans.length();
		if(l==ml){
			if(ans<mans)
				return;
			mans=ans;
		}else if(l<ml){
			string s=mans.substr(0,l);
			if(ans<s)
				return;
			if(ans>s)
				mans=ans;
		}else{
			string s=ans.substr(0,ml);
			if(s<mans)
				return;
			mans=ans;
		}
		if(d==L)
			return;
		for(int i=0;i<n.size();i++){
			if(!vis[i]){	
				vis[i]=1;
				string ta=ans;
				ans+=n[i];
				dfs(d+n[i].length());
				ans=ta;
				vis[i]=0;
			}
		}
	}
	static bool mycomp(string a, string b){
		if(a+b>b+a)
			return true;
		return false;
		int la=a.length(), lb=b.length();
		if(la==lb)
			return a>b;
		else if(la<lb){
			if(b.substr(0,la)>a)
				return false;
			return true;
		}else{
			if(a.substr(0,lb)>b)
				return true;
			return false;
		}
	}
	string largestNumber(vector<int>& nums){
		this->mans="";
		this->ans="";
		for(int i=0;i<nums.size();i++){
			string s=to_string(nums[i]);
			n.push_back(s);
			L+=s.length();
		}
		std::sort(n.begin(),n.end(), mycomp);
	//	memset(vis,0,sizeof(vis));
	//	dfs(0);
		for(int i=0;i<n.size();i++)
			mans+=n[i];
		return mans;
	}
};
int main(){
	//int arr[10]={7,89,34,88,93,90,9,8,9999,61};
	int arr[2]={47,474};
	vector<int> v(arr, arr+2);
	Solution s;
	cout<<s.largestNumber(v);
	return 0;}
