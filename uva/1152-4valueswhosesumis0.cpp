#include<iostream>
#include<sstream>
#include<unordered_map>
#include<stdio.h>
using namespace std;
int T;
//unordered_map<long, long> A;
//unordered_map<long, long> B;
//unordered_map<long, long> C;
//unordered_map<long, long> D;
long A[4000];
long B[4000];
long C[4000];
long D[4000];
void solve(int n){
	long res=0;
	unordered_map<long,long> sum1;
//	for(unordered_set<long>::iterator ita=A.begin();ita!=A.end();ita++){
//		for(unordered_set<long>::iterator itb=B.begin();itb!=B.end();itb++){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		//	long s=*ita+*itb;
			long s=A[i]+B[j];
			if(sum1.find(s)!=sum1.end()){
				sum1[s]=sum1[s]+1;
			}else{
				sum1[s]=1;
			}
		}
	}
//	for(unordered_set<long>::iterator itc=C.begin();itc!=C.end();itc++){
//		for(unordered_set<long>::iterator itd=D.begin();itd!=D.end();itd++){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			long s=-C[i]-D[j];
			if(sum1.find(s)!=sum1.end()){
				res+=sum1[s];
			}
		}
	}
	cout<<res<<endl;	
}

int main(){
	string line;
	getline(cin,line);
	stringstream ss0(line);
	ss0>>T;
	getline(cin,line);
	while(T--){
		getline(cin,line);
		stringstream ss1(line);
		int n;
		ss1>>n;
		long a,b,c,d;
		for(int i=0;i<n;i++){
			scanf("%ld%ld%ld%ld",&a,&b,&c,&d);
		//	A.insert(a);
		//	B.insert(b);
		//	C.insert(c);
		//	D.insert(d);
			A[i]=a; B[i]=b;C[i]=c;D[i]=d;
		}
		solve(n);
		if(T)
			cout<<endl;
//		A.clear();
//		B.clear();
//		C.clear();
//		D.clear();
		getline(cin,line);
		getline(cin,line);
	}
	return 0;
}
