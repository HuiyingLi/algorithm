#include<iostream>
#include<string.h>
#include<fstream>
#include<sstream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
		if(m==1&&n==1) return 1;
		long long ans=1;
		long long t=m+n-2;
		int k=m<n?m:n;
		for(int i = 0; i <k-1; i++){
			ans*=t;
			t--;
		}
		long long deno=1;
		for(int i=k-1;i>0;i--){
			deno*=i;
		}
		return ans/deno;
    }

};

int main(){
	Solution s;
	ifstream in;
	in.open("testgen_lc62.in");
	string line;
	while(!in.eof()){
		getline(in, line);
		stringstream ss(line);
		int m,n;
		ss>>m;
		getline(in,line);
		stringstream ss1(line);
		ss1>>n;
		cout<<s.uniquePaths(m,n)<<endl;
	}
	return 0;
}
