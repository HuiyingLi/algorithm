#include<iostream>
#include<sstream>
#include<string.h>

using namespace std;
int T,n;
int perm[10010];
int rec1[1000000];
int rec2[1000000];
bool swap(int l, int r){
	if(r-l<=0)
		return false;
	int wid=(r+1-l)/2;
	int tmp[wid];
	memcpy(tmp,perm+l-1,sizeof(tmp));
	memcpy(perm+l-1,perm+l-1+wid,sizeof(tmp));
	memcpy(perm+l-1+wid,tmp,sizeof(tmp));
	return true;
}

void solve(){
	long C=0;
	for(int i=0;i<n;i++){
		int pos;
		for(int j=i;j<n;j++){
			if(perm[j]==i+1)
				pos=j;
		}
		if((n-i-1)%2==0){//odd
			if(pos>(n-i)/2+i){
				if(swap(i+2,n)){
					rec1[C]=i+2;
					rec2[C++]=n;
				}
				
				if(swap(i+1,2*pos-n+1)){
					rec1[C]=i+1;
					rec2[C++]=2*pos-n+1;
				}
			}else{
				if(swap(i+1,2*pos-i)){
					rec1[C]=i+1;
					rec2[C++]=2*pos-i;
				}
			}
		}else{//even
			if(pos>=(n-i)/2+i){
				if(swap(i+1,n)){
					rec1[C]=i+1;
					rec2[C++]=n;
				}
				if(swap(i+1,2*pos-n)){
					rec1[C]=i+1;
					rec2[C++]=2*pos-n;
				}
			}else{
				if(swap(i+1,2*pos-i)){
					rec1[C]=i+1;
					rec2[C++]=2*pos-i;
				}
			}
		}			
	}
	
	cout<<C<<endl;
//	for(int i=0;i<n;i++)
//		if(perm[i]!=i+1)
//			cout<<"ERROR!"<<endl;
	for(long i=0;i<C;i++){
		cout<<rec1[i]<<" "<<rec2[i]<<endl;
	}
}
/**
void solve(){
	long C=0;
	while(true){
		bool swapped=false;
		for(int i=0;i<n;i++){
			bool done=false;
			for(int wid=1; wid<=(n-i)/2;wid++){
				int lmin=99999;
				int rmax=-1;
				for(int j=i;j<i+wid;j++){
					if(perm[j]<lmin)
						lmin=perm[j];
				}	
				for(int j=i+wid;j<i+2*wid;j++){
					if(perm[j]>rmax)
						rmax=perm[j];
				}
				if(rmax<lmin){
					swap(i+1,i+1+2*wid-1);
					rec1[C]=i+1;
					rec2[C]=i+1+2*wid-1;
					done=true;
					C++;
					break;
				}
			}
			if(done){
				swapped=true;
				break;
			}
		}
		if(!swapped)
			break;
	}
	cout<<C<<endl;
	for(long i=0;i<C;i++)
		cout<<rec1[i]<<" "<<rec2[i]<<endl;
}
**/
int main(){
	string line;
	getline(cin,line);
	stringstream ss(line);
	ss>>T;
	while(T--){
		getline(cin,line);
		stringstream ss1(line);
		ss1>>n;
		getline(cin,line);
		stringstream ss(line);
		for(int i=0;i<n;i++){
			ss>>perm[i];
		}
		solve();
	}	
	return 0;
}
