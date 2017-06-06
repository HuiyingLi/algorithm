#include<iostream>
#include<sstream>
#include<queue>
using namespace std;
int n;

void solve(priority_queue<long, vector<long>, greater<long> > q){
	long cost=0;
	while(q.size()>=2){
		long a=q.top();
		q.pop();
		long b=q.top();
		q.pop();
		long s=a+b;
		q.push(s);
		cost+=s;
	}
	cout<<cost<<endl;	
}
int main(){
	string line;
	while(true){
		getline(cin,line);
		stringstream ss0(line);
		ss0>>n;
		if(n==0)
			break;
		getline(cin,line);
		stringstream ss(line);
		priority_queue<long, vector<long>, greater<long> > q;
		long k;
		for(int i=0;i<n;i++){
			ss>>k;
			q.push(k);
		}
		solve(q);
	}
	return 0;
}
