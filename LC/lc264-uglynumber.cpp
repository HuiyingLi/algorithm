#include<iostream>
#include<set>

using namespace std;

class Solution{
public:
	long nthUglyNumber(int n){
		set<long> ms;
		ms.insert(1);
		long t=1;
		for(int i=0;i<n;i++){
			t=*ms.begin();
			ms.erase(ms.begin());
			ms.insert(t*2);
			ms.insert(t*3);
			ms.insert(t*5);
		}
		return t;
}
};


int main(){
	
	return 0;}
