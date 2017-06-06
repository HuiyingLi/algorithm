#include<iostream>
#include<sstream>

using namespace std;

long long maxpd(int N, int* a){
	int s=0,e=0;
	long long p=1;
	long long maxp=-1;
	for(s=0;s<=N-1;s++){
		p=1;
		for(e=s;e<=N-1;e++){
			p*=a[e];
			if(p>0&&p>maxp)
				maxp=p;
		}
	}
	return maxp;
}
int main(){
	string line;
	int N=-1;
	int a[20];
	int C=1;
	while(getline(cin, line)){
		if(N==-1&&line.length()!=0){
			stringstream ss(line);
			ss>>N;
		}else if(line.length()==0){
			N=-1;
		}else{
			stringstream ss(line);
			for(int i=0;i<N;i++)ss>>a[i];
			long long maxp=maxpd(N,a);			
			if(maxp<0)maxp=0;
			cout<<"Case #"<<C<<": The maximum product is "<<maxp<<".\n\n";
			C++;
		}
	}
}
