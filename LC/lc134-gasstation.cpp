#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int N=gas.size();
		int left=0;
		int start=0;
		int sum=0;
		for(int i=0;i<N;i++){
			sum+=gas[i]-cost[i];
			left+=gas[i]-cost[i];
			if(left<0){
				start=i+1;
				left=0;
			}
		}
		return sum>=0?start:-1;
    }
};
int main(){
	return 0;
}
