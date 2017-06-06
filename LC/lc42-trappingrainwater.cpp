#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0) return 0;
        stack<int> stkh;
        stack<int> stkp;
        int f=0;
        int total=0;
        stkh.push(height[0]);
        stkp.push(0);
        for(int i=1;i<height.size();i++){
            while(!stkh.empty()&&height[i]>stkh.top()){
                int w=i-stkp.top()-1;
                if(w>0){ 
                    int h=min(height[i],stkh.top());
               		int area=w*(h-f);
                	total+=area;
                    f=h;
				}
                stkh.pop();
                stkp.pop();
            }
            if(!stkh.empty()){
                int w=i-stkp.top()-1;
                if(w>0){ 
                  int h=min(height[i],stkh.top());
                 	int area=w*(h-f);
                    total+=area;
                    f=h;
			    }
            }
            stkh.push(height[i]);
            stkp.push(i);
            f=height[i];
        }
        return total;
    }
};

int main(){
	Solution s;
	int arr[12]={0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> in(arr, arr+12);
	cout<<s.trap(in)<<endl;
}
