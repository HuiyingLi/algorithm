#include<iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        for(long i=m+1;i<=n;i++){
            m&=i;
            if((m^0)==0)
                break;
        }
        return m;
    }
};

int main(){
	Solution s;
	cout<<s.rangeBitwiseAnd(2147483645,2147483647);
	
return 0;}
