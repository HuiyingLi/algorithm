#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> ans;
    int N;
    int L;
    int num;
    bool dfs(int k){
        if(ans.size()>N)
            return false;
        if(k<=N)
            ans.push_back(k);
        for(int i=0;i<=9;i++){
            int tmp=k;
            k=k*10+i;
            if(!dfs(k))
                return false;
            k=tmp;
        }
        return true;
    }
    vector<int> lexicalOrder(int n) {
        string in=to_string(n);
        N=n;
        num=1;
        L=in.length();
        dfs(1);
        return ans;
    }
};
int main(){
	Solution s;
	s.lexicalOrder(130);
	
}
