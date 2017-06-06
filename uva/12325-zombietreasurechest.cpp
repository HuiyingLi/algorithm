#include<iostream>
#include<sstream>
using namespace std;
long N, S1, V1, S2, V2;
long thres=10000;

long long search(){
	long long total=0;
	if(N*1.0/S1<thres){
		if(S1<S2){
			long tmps, tmpv;
			tmps=S2;
			S2=S1;
			S1=tmps;
			tmpv=V2;
			V2=V1;
			V1=tmpv;
		}
		for(long i=0; i<=N/S1; i++){
			long long tt=i*V1;
			tt+=(N-i*S1)/S2*V2;
			if(tt>total)
				total=tt;
		}
	}else{
		if(S2*V1>S1*V2){
			for(long i=0;i<S1;i++){
				long long tt=i*V2;
				tt+=((N-i*S2)/S1)*V1;
				if(tt>total)
					total=tt;
			}
		}else{
			for(long i=0;i<S2;i++){
				long long tt=i*V1;
				tt+=((N-i*S1)/S2)*V2;
				if(tt>total)
					total=tt;
			}
		}
	}
	return total;
}

int main(){
	int T=0;
	string line;
	getline(cin,line);
	stringstream ss(line);
	ss>>T;
	for(int C=1; C<=T; C++){
		getline(cin, line);
		stringstream ss0(line);
		ss0>>N>>S1>>V1>>S2>>V2;
		cout<<"Case #"<<C<<": "<<search()<<endl;
	}
	return 0;	
}
