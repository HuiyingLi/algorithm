#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    stack<char> stk;
    string ans;
    string s;
    int ml;
    unordered_set<string> vis;
    void fullpush(char c){
        if(!stk.empty()&&stk.top()=='('&&c==')'){
            stk.pop();
            return;
        }
		if(c!='('&&c!=')')
	    	return;
        stk.push(c);
    }
    void dfs(int d){
        if(d>=s.length()){
			if(stk.empty()){
			    if(ans.length()<ml) return;
			    if(ans.length()>ml){
			        vis.clear();
			        vis.insert(ans);
			        ml=ans.length();
			    }else if(ans.length()==ml){
			        vis.insert(ans);
			    }
			}
            return;
        }
		if(!(stk.empty()&&s[d]==')')){
			stack<char> tstk=stk;
			string ts=ans;
			ans+=s[d];
			fullpush(s[d]);
			dfs(d+1);
			stk=tstk;
			ans=ts;
		}
		dfs(d+1);
    }
    vector<string> removeInvalidParentheses(string s) {
        stk=stack<char>();
        ans="";
        this->s=s;
        ml=0;
        dfs(0);
        vector<string> res;
        for(auto iter=vis.begin();iter!=vis.end();iter++)
            res.push_back(*iter);
        return res;
    }
};


int main(){
	string in="()())()";
	Solution s;
	s.removeInvalidParentheses(in);

	return 0;}

