#include<iostream>
#include<vector>
#include<string.h>
#define INT_MAX 2147483647
using namespace std;

class Solution {
public:
    int cdist[110][26];
    int adist[110][26];
    int state;
    int steps;
    string key;
    string ring;
    int ms;
    void dfs(int d){
        if(d==key.length()){
            if(steps<ms)
                ms=steps;
            return;
        }
		if(ring[state]==key[d]){
			dfs(d+1);
			return;
		}
        //right side
        int dist=cdist[state][key[d]-'a'];
        if(dist!=-1&&steps+dist<ms){
            int ts=state;
            state+=dist;
            if(state>=ring.length())
                state-=ring.length();
            steps+=dist;
            dfs(d+1);
            steps-=dist;
            state=ts;
        }
        dist=adist[state][key[d]-'a'];
        if(dist!=-1&&steps+dist<ms){
            int ts=state;
            state-=dist;
            if(state<0)
                state+=ring.length();
            steps+=dist;
            dfs(d+1);
            steps-=dist;
            state=ts;
        }
        
    }
    int findRotateSteps(string ring, string key) {
		memset(adist,0,sizeof(adist));
		memset(cdist,0,sizeof(cdist));
        for(int i=0;i<ring.length();i++){
            char z=ring[i];
            for(int j=0;j<ring.length()-1;j++){
                int p=j+1+i;
                if(p>=ring.length())
                    p-=ring.length();
                char c=ring[p];
                if(cdist[i][c-'a']==0||cdist[i][c-'a']>j+1)
                    cdist[i][c-'a']=j+1;
                if(adist[i][c-'a']==0||adist[i][c-'a']>ring.length()-j-1)
                    adist[i][c-'a']=ring.length()-j-1;
            }
        }
        for(int i=0;i<ring.length();i++){
            for(int j=0;j<26;j++)
                if(adist[i][j]==ring.length()-cdist[i][j]){
                    if(adist[i][j]>=cdist[i][j])
                        adist[i][j]=-1;
                    else
                        cdist[i][j]=-1;
                }
        }
        for(int i=0;i<ring.length();i++){
            for(int j=0;j<26;j++)
                cout<<cdist[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<ring.length();i++){
            for(int j=0;j<26;j++)
                cout<<adist[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        this->key=key;
        this->ring=ring;
        steps=0;
        state=0;
        ms=INT_MAX;
        dfs(0);
        return ms+key.length();
    }
};

int main(){
	string ring="godding";
	string key="dg";
	Solution s;
	cout<<s.findRotateSteps(ring,key);
	return 0;
}
