#include<iostream>
#include<sstream>

using namespace std;

int T;
long N;
long in[100000];
long out[100000];
long solve(){
	for(long k=0;k<N;k++){
		long long store=0;
		long i;
		for(i=0;i<N;i++){
			long ind=(i+k)%N;
			store+=in[ind];
			if(store<out[ind]){
				k+=i;
				break;
			}
			store-=out[ind];
		}
		if(i==N){
			return k;
		}
	}
	return -1;
}
int main(){
	string line;
	getline(cin,line);
	stringstream ss0(line);
	ss0>>T;
	int t=1;
	while(T--){
		getline(cin,line);
		stringstream ss1(line);
		ss1>>N;
		if(N==0){cout<<"Case "<<t++<<": Not possible\n"; continue;}
		getline(cin,line);
		stringstream ss(line);
		for(long i=0;i<N;i++)
			ss>>in[i];
		getline(cin,line);
		stringstream ss3(line);
		for(long i=0;i<N;i++)
			ss3>>out[i];
		cout<<"Case "<<t++<<": ";
		long ans = solve();
		if(ans!=-1){
			cout<<"Possible from station "<<ans+1<<endl;
		}else
			cout<<"Not possible\n";
	}
	return 0;
}

