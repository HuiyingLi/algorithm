#include<iostream>
#include<sstream>
#include<math.h>
#include<vector>
using namespace std;
int main(){

	int n;
	string terminal;
	int  vars[10];
	int m;
	int vva[513];
	
	string line;
	int C=1;
	while(true){
		getline(cin,line);
		stringstream ss(line);
		ss>>n;
		if(n==0)
			return 0;
		getline(cin, line);
		int c=0;
		for(int i=0; i<line.length();i++){
			if(line[i]=='x'){
				vars[c]=line[i+1]-'1';
				c++;
			}
		}
		getline(cin,line);
		for(int i=0; i< pow(2.0, n);i++){
			vva[i]=line[i]-'0';
		}
		getline(cin,line);
		stringstream sss(line);
		sss>>m;
		vector<int> res;
		int ass[n];
		for(int i=0;i<m;i++){
			getline(cin,line);
			int ind;
			for(int j=0;j<n;j++){
				int d=line[j]-'0';
				for(int k=0;k<n;k++){
					if(vars[k]==j)
						ind=k;
				}
				ass[ind]=d;
			}
			int nn=1;
			for(int j=0; j<n;j++){
				if(ass[j]==0)
					nn*=2;
				else if(ass[j]==1)
					nn=2*nn+1;
			}
			nn-=pow(2,n);
			res.push_back(vva[nn]);	
		}
		cout<<"S-Tree #"<<C<<":\n";
		for(int i=0;i<res.size();i++)cout<<res[i];
		cout<<endl<<endl;
		C++;
		for(int i=0;i<10;i++)vars[i]=0;
		for(int i=0;i<513;i++)vva[i]=0;
	}
}
