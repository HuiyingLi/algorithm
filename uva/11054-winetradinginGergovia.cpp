#include<iostream>
#include<sstream>
#include<math.h>
using namespace std;

long n;
long vil[100000];

void solve(){
	long long res=0;
	for(long i=1;i<n;i++){
		res+=fabs(vil[i-1]);
		vil[i]+=vil[i-1];
		
	}
	cout<<res<<endl;
}
int main(){
	string line;
	while(true){
		getline(cin, line);
		stringstream ss0(line);
		ss0>>n;
		if(n==0)
			break;
		getline(cin, line);
		stringstream ss(line);
		for(long i=0;i<n;i++){
			ss>>vil[i];
		}
		solve();
	}
	return 0;
}
