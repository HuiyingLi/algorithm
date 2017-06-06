#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
using namespace std;

class Solution {
public:
	
    bool searchMatrix(vector<vector<int> >& mt, int t) {
		int m=mt.size();
		if(m==0)return false;
		int n=mt[0].size();
		if(n==0)
			return false;
		int l=0,r=m;
		int mid=0;
		while(l<r){
			mid=l+(r-l)/2;
			if(mt[mid][0]<t){
				if(mid==m-1)
					break;
				if(mt[mid+1][0]<=t)
					l=mid+1;
				else
					break;
			}
			if(mt[mid][0]>t)
				r=mid;
			if(mt[mid][0]==t)
				return true;
		}
		vector<int> v=mt[mid];
		cout<<mid<<endl;
		l=0; r=n;
		mid=0;
		while(l<r){
			mid=l+(r-l)/2;
			if(v[mid]<t)
				l=mid+1;
			else if(v[mid]>t)
				r=mid;
			else if(v[mid]==t)
				return true;
		}
		return false;
    }

};

int main(){
	
	return 0;

}
