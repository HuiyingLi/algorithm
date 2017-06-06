#include<iostream>
using namespace std;
class Solution {
public:
    int cache[1000000];
    int ans;
    void dfs(long n, int d){
        if(d>ans)
            return;
        if(n==1){
            ans=d;
            return;
        }
        if(n%2==0)
            dfs(n/2, d+1);
        else{
            dfs(n-1, d+1);
            dfs(n+1, d+1);
        }
    }
    int integerReplacement(int n) {
        ans=10000;
        dfs(n,0);
        return ans;
    }
};
int main(){
	Solution s;
	cout<<s.integerReplacement(2147483647);
	
}
