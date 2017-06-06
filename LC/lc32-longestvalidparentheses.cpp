#include<iostream>
#include<string.h>
using namespace std;
class Solution {
public:
    int dp[1000][1000];
    int longestValidParentheses(string s) {
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int l=2;l<=s.length();l+=2){
            for(int i=0;i+l<=s.length();i++){
                if(l==2&&s.substr(i,l)=="()"){
                    dp[i][i+l]=1;
                    continue;
                }
                if(dp[i+1][i+l-1]&&s[i]=='('&&s[i+l-1]==')'){
                    ans=l;
                    continue;
                }
                for(int k=i+1;k<=i+l;k++){
                    if(dp[i][k]&&dp[k][i+l])
                        ans=l;
                }
            }
        }
        return ans;
    }
};

int main(){
	Solution s;
	string in="((())))";
	cout<<s.longestValidParentheses(in)<<endl;
	
}
