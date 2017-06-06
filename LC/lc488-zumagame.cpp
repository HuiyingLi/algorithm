#include<list>
#include<vector>
#include<iostream>
#include<string.h>
#define INT_MAX 2147483647
using namespace std;
class Solution {
public:
    int minstep;
    int step;
    string state;
    string hand;
    int vis[10];
    bool dfs(int d,int ind){
		if(state.length()==0){
			if(step<minstep){
				minstep=step;
				return true;
			}
		}
		if(d==hand.length())
		    return false;
        if(vis[ind]||step>=minstep-1)
            return false;
		char clr=hand[ind];
        vis[ind]=1;
        int i=0;
        while(i<state.length()){
            char c=state[i];
            if(c==clr){
                i++;
                while(i<state.length()&&state[i]==clr) i++;
				int ti=i;
                string tstate=state;
                //insert
                state.insert(i,&c, 1);
                //update, remove
                int j=i, p=i-1;
                int cnt=0;
                while(state.length()>2&&i>0){
                    char tc=state[j];
                    while(j<state.length()&&state[j]==tc)j++;
                    p=j-1;
                    i=j;
                    cnt=1;
                    while(p>0&&state[p-1]==state[p]) p--,cnt++;
                    if(cnt>=3){
                        state.erase(p,j-p);
                        j-=cnt;
                        i-=cnt;
                    }
                    else
                        break;
                }
                step++;
                for(int n=0;n<hand.length();n++){
                    dfs(d+1,n);
                }
				i=ti;
                state=tstate;
                step--;
            }
			else
				i++;
		}
        vis[ind]=0;
        return false;
    }
    int findMinStep(string board, string hand) {
        minstep=INT_MAX;
		this->hand=hand;
		this->state=board;
		memset(vis,0,sizeof(vis));
		step=0;
		if(board.length()==0) return 0;
		for(int i=0;i<hand.length();i++){
            dfs(0,i);
		}
        if(minstep!=INT_MAX)
            return minstep;
        return -1;
    }
};
int main(){
	string hand="RB";
	string board="WRRBBW";
//	string hand = "WGB";
//	string board="GBB";
	Solution s;
	cout<<s.findMinStep(board,hand)<<endl;
	
	return 0;
}
