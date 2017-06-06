#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& p) {
		if(p.size()<=1) return 0;
		int prof=0;
		int buy=-1;
		for(int i=0;i<p.size();i++){
			if(i==0){
				if(p[i]<p[i+1]){
					buy=p[i];
				}
				continue;
			}
			if(i==p.size()-1){
				if(buy!=-1){
					prof+=p[i]-buy;	
				}
				continue;
			}
			if(p[i]==p[i+1]) continue;
			int l=i-1;
			while(l>0&&p[l]!=p[i])l--;
			if(p[l]>p[i]&&p[i]<p[i+1]){
				buy=p[i];
				continue;
			}
			l=i-1;
			while(l>0&&p[l]!=p[i])l--;
			if(p[l]<p[i]&&p[i]>p[i+1]){
				prof+=p[i]-buy;
				buy=-1;
			}
		}
		return prof;
    }
};
int main(){
	return 0;
}
