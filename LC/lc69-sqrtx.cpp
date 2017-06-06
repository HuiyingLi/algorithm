#include<iostream>

using namespace std;
class Solution {
public:
    int mySqrt(int x) {
		long long int l=0;
		long long int r=x;
		long long int mid=0;
		if(x==1) return 1;
		while(l<r){
			mid=l+(r-l)/2;
			if(mid*mid<x){
			    if((mid+1)*(mid+1)<=x)
				    l=mid+1;
				else
				    return mid;
			}
			if(mid*mid>x)
				r=mid;
			if(mid*mid==x)
				return mid;
		}
		return mid;
    }

};
int main(){
	Solution s;
	cout<<s.mySqrt(2147395599);
	return 0;
}
