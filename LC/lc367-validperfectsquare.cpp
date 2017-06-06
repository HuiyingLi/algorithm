#include<iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int x) {
		long long int l=0;
		long long int r=x;
		long long int mid=0;
		if(x<=1) return true;
		while(l<r){
			mid=l+(r-l)/2;
			if(mid*mid<x){
				if((mid+1)*(mid+1)<=x)
					l=mid+1;
				else if((mid+1)*(mid+1)>x)
					return false;
			}
			if(mid*mid>x)
				r=mid;
			if(mid*mid==x)
				return true;
		}
		return false;
    }

};
int main(){
	return 0;

}
