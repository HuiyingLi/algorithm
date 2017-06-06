#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
#include<set>
using namespace std;
class Solution {
public:
    int k;
    int solve(string s){
        int ans=0;
        unordered_set<char>bad;
        int vf[26]={0};
        for(int i=0;i<s.length();i++){
            char c=s[i];
            vf[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(vf[i]<k&&vf[i]>0)
                bad.insert('a'+i);
        }
        if(bad.size()==0)
            return s.length();
		if(s=="z")
			cout<<"";
        int b=0,e=0;
        while(b<s.length()&&e<s.length()){
            while(bad.find(s[b])!=bad.end())b++;
            e=b;
            while(bad.find(s[e])==bad.end())e++;
            int a=solve(s.substr(b,e));
            if(a>ans)
                ans=a;
            b=e;
        }
        return ans;
    }
    int longestSubstring(string s, int k) {
        if(k==0)
            return s.length();
        if(s.length()==0) return 0;
        this->k=k;
        return solve(s);
    }
};

int main(){
	Solution s;
	cout<<s.longestSubstring("tipirhqrfbfhlcqchiidzvhinfgtiwzddaasolgwjaqonupccgnaizehculhoqpxlhrxoqmqiaguzotitdwz",2);
	return 0;
}
