#include<iostream>
#include<sstream>

using namespace std;

int D, N;
string num;
class node{
	public:
	char v;
	node* nxt;
	node* prev;
	node(int n){
		v=n;
		nxt=NULL;
		prev=NULL;
	}
};

void solve(){
	char res[100010];
	int L=N-D;
	int l=0;
	int i;
	for(i=0;i<N&&D>0;i++){
//		if(i!=N&&num[i]>num[i-1]){
//			D--;
//			continue;
//		}
		while(l>0&&res[l-1]<num[i]){
			l--;
			D--;
			if(D==0)
				break;
		}
		res[l]=num[i];
		l++;
	}
	int j;
	for(j=0;j<l&&j<L;j++)
		cout<<res[j];
	cout<<num.substr(i,L-j)<<endl;
}
/**
void solve(){
	string res="";
	int start=0;
	int maxi;
	int L=N-D;
	while(D>0&&res.length()<L){
		char maxd='0'-1;
		for(int i=start; i<N&&i<=start+D;i++){
			if(num[i]>maxd){
				maxd=num[i];
				maxi=i;
				if(maxd=='9')
					break;
			}
		}
		D-=maxi-start;
		res+=maxd;
		start=maxi+1;
	}
	if(res.length()<L){
		for(int i=maxi+1;i<N;i++)
			res+=num[i];
	}
	cout<<res<<endl;
}
*/

int main(){
	string line;
	while(true){
		getline(cin,line);
		stringstream ss(line);
		ss>>N>>D;
		if(N==0&&D==0)
			break;
		getline(cin, num);
		solve();
	}
	return 0;
}
