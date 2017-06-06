#include<iostream>
using namespace std;
class Solution{
public:
	bool isUgly(int num){
		if(num<=0)
			return false;
		if(num==1)
			return true;
		while(true){
			bool done=false;
			if(num%2==0){
				num/=2;
				done=true;
			}
			if(num%3==0){
				num/=3;
				done=true;
			}
			if(num%5==0){
				num/=5;
				done=true;
			}
			if(!done){
				if(num==1)
				return true;
				else
				return false;
			}
		}
	}
};

int main(){
	Solution s;
	if(s.isUgly(256))
		cout<<"true\n";
	else
		cout<<"false\n";
	return 0;
}
