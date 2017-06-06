#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int r) {
        if(s==""||r==1) return s;
        int l=0;
        string ans=s.substr(0,1);
        for(int i=1;i<=r;i++){
            int p=0, c=1;
            while(true){
                if(c%2==1){
		    if(i==1||i==r) {
			c++;continue;
		    }
                    p=1+(c-1)*(r-1)+i-1;
                }else{
                    p=1+(c-1)*(r-1)+(r-i);
                }
                if(p>s.length()) break;
				if(p>0)
                	ans+=s[p-1];
                c++;
            }
        }
        return ans;
    }
};
int main(){
	cout<<CV_VERSION<<endl;
//	string in="abcdefghijklmno";
//	Solution s;
//	cout<<s.convert(in,4);
	return 0;
}
