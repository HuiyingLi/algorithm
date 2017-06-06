#include<iostream>
#include<sstream>
#include<string.h>
using namespace std;

long N[100000];
long solve(long s, long n){
	/*
	if(n<=s){
		long cnt[s];
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++){
			cnt[N[i]-1]++;
			if(cnt[N[i]-1]>1){
				return 0;
			}
		}
		return s;
	}
	*/
	long win[s];
	long ltonce=0;
	long legit[s];
	memset(win,0,sizeof(win));
	memset(legit,0,sizeof(legit));
	long i=0;
	while(i<n+s){
		//remove leftmost element
		if(i-s>=0){
			win[N[i-s]-1]--;
			if(win[N[i-s]-1]==1)
				ltonce--;
		}
		//add current element
		if(i<n){
			win[N[i]-1]++;
			if(win[N[i]-1]==2)
				ltonce++;
		}
		if(ltonce){
			legit[i%s]=-1;
		}
		i++;
	}
	long res=0;
	for(long i=0;i<s;i++){
		if(!legit[i])
			res++;
	}
	return res;
}

int main(){
	int T;
	string line;
	getline(cin,line);
	stringstream ss0(line);
	ss0>>T;
	long s, n;
	while(T--){
		getline(cin, line);
		stringstream ss1(line);
		ss1>>s>>n;
		getline(cin,line);
		stringstream ss(line);
		for(long i=0;i<n;i++){
			ss>>N[i];
		}
		long ans=solve(s, n);
		cout<<ans<<endl;
	}
	return 0;
}
