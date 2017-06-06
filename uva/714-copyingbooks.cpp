#include<iostream>
#include<sstream>
#include<string.h>
using namespace std;

int m;
int k;
long books[500];
long seps[500];
int T;
long long total;
long mmax;
bool fits(int x){
	int sl=m-1;
	for(int i=0;i<k;i++){
		long long s=0;
		while(s+books[sl]<=x){
			if(sl==0)
				return true;
			s+=books[sl];
			sl--;
		}
	}
	return false;
}

long long bisearch_x(){
	long long cur=mmax+(total-mmax)/2;
	long long l=mmax, r=total;
	while(l<r){
		if(!fits(cur)){
			l=cur+1;
		}else{
			r=cur;
		}
		cur=l+(r-l)/2;
	}
	return cur;
}
void solve(){
	long long minx=bisearch_x();
	int sl=m-1;
	int tg=0;//total /
	while(tg<k-1){
		if(sl<=k-1-tg){//each number get a /
			sl--;
			while(sl>=0){
				seps[tg]=sl;
				sl--;
				tg++;
			}
		}else{
			long long s=0;
			while(s+books[sl]<=minx){
				if(sl+1<=k-1-tg||sl<=0)
					break;
				s+=books[sl];
				sl--;
			}
			seps[tg]=sl;
			tg++;
		}
	}	

	int cnt=k-2;
	cout<<books[0];
	if(cnt>=0&&0==seps[cnt]){
		cout<<" /";
		cnt--;
	}
	for(int i=1;i<m;i++){
		cout<<" "<<books[i];
		if(cnt>=0&&i==seps[cnt]){
			cout<<" /";
			cnt--;
		}
	}
	cout<<endl;
}
int main(){
	string line;
	getline(cin,line);
	stringstream ss0(line);
	ss0>>T;
	while(T--){
		getline(cin,line);
		stringstream ss1(line);
		ss1>>m>>k;
		getline(cin,line);
		stringstream ss(line);
		for(int i=0;i<m;i++){
			ss>>books[i];
			total+=books[i];
			if(books[i]>mmax)
				mmax=books[i];
		}
		solve();
		total=0;
		mmax=0;
		memset(seps,0,sizeof(seps));
	}	
	return 0;
}
