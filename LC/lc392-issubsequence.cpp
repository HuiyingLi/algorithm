#include<iostream>

using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
		int i=0,j=0;
		while(i<s.length()&&j<t.length()){
			while(j<t.length()&&t[j]!=s[i]){
				j++;
			}
			if(j==t.length())
				return false;
			i++;
			j++;
		}
		if(i==s.length())
			return true;
		return false;
    }

};

int main(){
	string s="abc";
	string t="aabfgcc";
	Solution sol;
	sol.isSubsequence(s,t);
	return 0;
}
