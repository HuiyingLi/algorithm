#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> res;
	string digits;
	string getchars(char d){
		if(d=='1'||d=='0')
			return "";
		int s=d-'2';
		string ans="";
		ans+='a'+s*3;
		ans+='a'+s*3+1;
		ans+='a'+s*3+2;
		if(d=='7')
			ans="pqrs";
		if(d=='8')
			ans="tuv";
		if(d=='9')
			ans="wxyz";
		return ans;
	}
	void dfs(string comb,int d){
		if(d>=digits.length()){
			res.push_back(comb);
			return;
		}
		string cand=getchars(digits[d]);
		for(int i=0;i<cand.length();i++){
			comb+=cand[i];
			dfs(comb, d+1);
			comb=comb.substr(0,comb.length()-1);
		}
	}
    vector<string> letterCombinations(string digits) {
		res.clear();
		if(digits.length()==0)
			return res;
		this->digits=digits;
		dfs("",0);
		return res;
    }
};

int main(){
	Solution s;
	s.letterCombinations("365");
	return 0;}
