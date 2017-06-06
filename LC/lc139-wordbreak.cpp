#include<iostream>
#include<map>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution{
public:
	string ans;
	vector<string> res;
	unordered_set<string> test;
	map<int, unordered_set<string> > dict;
//	map<int, set<string> >dict;
	string s;
	void dfs(int p){
		if(p>s.length()) return;
		if(p==s.length()){
			res.push_back(ans.substr(0,ans.size()-1));
			return;
		}
		int i=p;
		for(map<int, unordered_set<string> >::iterator it=dict.begin();it!=dict.end();it++){
			int l=it->first;
			unordered_set<string> d=it->second;
			if(i+l>s.length())
				break;
			string wd=s.substr(i,l);
			if(d.find(wd)!=d.end()){
				string ta=ans;
				ans+=wd+" ";
				dfs(p+l);
				ans=ta;
			}
		}
	}
	bool wordBreak(string s, vector<string>& wordDict){
		dict.clear();
		this->s=s;
		for(int i=0;i<wordDict.size();i++){
			string t=wordDict[i];
			int l=t.length();
			if(dict.find(l)==dict.end()){
				unordered_set<string> set;
				dict[l]=set;
			}
			dict[l].insert(t);
		}
		dfs(0);
		if(res.size()>0)
			return true;
		return false;
	}
};
int main(){
	string in="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	string d[10]={"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
	vector<string> v(d,d+4);
	Solution s;
	cout<<s.wordBreak(in,v);
	return 0;}
