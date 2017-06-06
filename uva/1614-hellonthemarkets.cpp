#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

class num{
	public:
	long v;
	long ind;
};

bool comp(const num &n1, const num &n2){
	return n1.v<n2.v;
}
long n;
int bs[100010];
num as[100010];

int main(){
	while(scanf("%ld",&n)!=EOF){
		long ssum=0;
		for(long i=0;i<n;i++){
			scanf("%ld",&as[i].v);
			as[i].ind=i;
			ssum+=as[i].v;
		}
		if(ssum%2==1)
			cout<<"No\n";
		else{
			cout<<"Yes\n";
			memset(bs, 0, sizeof(bs));
			sort(as, as+n, comp);
			ssum/=2;
			long j=n-1;
			while(ssum&&j>=0){
				if(ssum>=as[j].v){
					ssum-=as[j].v;
					bs[as[j].ind]=1;
				}
				j--;
			}
			for(j=0;j<n-1;j++){
				if(bs[j]){
					cout<<"1 ";
				}
				else{
					cout<<"-1 ";
				}
			}
			if(bs[j]){
				cout<<"1\n";
			}
			else{
				cout<<"-1\n";
			}
			if(ssum!=0)
				cout<<"ERROR"<<endl;
		}
	}
	return 0;
}
