#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
class job{
	public:
	int q,d;
	job(){}
	bool operator < (const job& j) const{
		return this->d<j.d;
	}
};

int T;
int n;
job jobs[8000010];

void solve(){
	priority_queue<int>p;
	int start=0;
	int k=0;
	sort(jobs, jobs+n);
	for(int i=0;i<n;i++){
		job j=jobs[i];
		start+=j.q;
		p.push(j.q);
		if(start>j.d){
			start-=p.top();
			p.pop();
			k++;
		}
	}
	cout<<n-k<<endl;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d", &jobs[i].q,&jobs[i].d);
		}
		solve();
		if(T)
			cout<<endl;
	}
	return 0;
}
