#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
		int maxk=1;
		for(int k=2;k<=n;k++){
			int base=n/k;
			int ones=n%k;
			int ans=pow(base,k-ones);
			ans*=pow(base+1,ones);
			if(ans>maxk)
				maxk=ans;
		}
		return maxk;
    }
};
int main(){
	Solution s;
	cout<<s.integerBreak(11);
	return 0;}
