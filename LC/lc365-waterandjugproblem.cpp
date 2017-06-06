#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    unordered_map<int,unordered_set<int> > vis;
    int target;
    int x;
    int y;
    void put(int a, int b, unordered_map<int,unordered_set<int> >&tq){
        if(vis.find(a)==vis.end()){
            vis[a].insert(b);
	    	tq[a].insert(b);
        }else{
			if(vis[a].find(b)==vis[a].end()){
				vis[a].insert(b);
					tq[a].insert(b);
			}
		}
    }
    void getNext(int k, int l,unordered_map<int,unordered_set<int> >& tq){
        int a=k, b=l;
        put(0,b,tq);        
        put(a,0,tq);
        put(x,b,tq);
        put(a,y,tq);
        //pour x into y
        if(a+b<y)
            a=0,b+=a;
        else
            a-=y-b,b=y;
        put(a,b, tq);
        //pour y into x
        a=k, b=l;
        if(a+b<x)
            a+=b,b=0;
        else
            a=x,b-=x-a;
        put(a,b,tq);
        
    }
    bool canMeasureWater(int x, int y, int z) {
        this->x=x;
        this->y=y;
        int a=0,b=0;
		target=z;
        unordered_map<int,unordered_set<int> >q;
        q[a].insert(b);
        vis[a].insert(b);
        while(!q.empty()){
            unordered_map<int,unordered_set<int> >tq;
            for(auto iter=q.begin();iter!=q.end();iter++){
                int k=iter->first;
				if(k==target) return true;
				for(auto iter2=q[k].begin();iter2!=q[k].end();iter2++){
					int l=*iter2;
					if(l==target) return true;
					getNext(k,l,tq);
				}
           	}
            q=tq;
        }
        
        return false;
    }
};

int main(){
	Solution s;
	s.canMeasureWater(3,5,4);
	return 0;}
