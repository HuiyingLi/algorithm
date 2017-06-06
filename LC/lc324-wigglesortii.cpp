#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    void wiggleSort(vector<int>& nums){
        if(nums.size()<3)
            return;
        vector<int> l;
        vector<int> r;
        int tgt=nums.size()/2;
        srand((unsigned)time(0));
        vector<int> v=nums;
        int pvt;
        while(tgt>0){
            l.clear();
            r.clear();
            int same=0;
            int rt=fabs(rand()%v.size());
            pvt=v[rt];
            for(int i=0;i<v.size();i++){
                if(v[i]<pvt){
                    l.push_back(v[i]);
                }else if(v[i]>pvt){
                    r.push_back(v[i]);
                }else{
                    same++;
                }
            }
            if(l.size()<=tgt){
                tgt-=l.size();
                v=r;
                tgt-=same;
            }else{
                v=l;
            }
            
        }
        cout<<pvt<<endl;
        vector<int> n=nums;
        
        int ind1=0,ind2=n.size()/2*2-1;
        for(int i=0;i<n.size();i++){
            if(n[i]<pvt){
                nums[ind1]=n[i];
                ind1+=2;
            }else if(n[i]>pvt){
                nums[ind2]=n[i];
                ind2-=2;
            }
        }
        while(ind1<n.size()){
            nums[ind1]=pvt;
            ind1+=2;
        }
        while(ind2>0){
            nums[ind2]=pvt;
            ind2-=2;
        }
        cout<<"exe"<<endl;
    }
};

int main(){
	int a[5]={1,5,2,6,4};
	int b[6]={1, 3, 2, 2, 3, 1};
	vector<int> v1(a, a+5);
	vector<int> v2(b, b+6);
	Solution s;
	s.wiggleSort(v1);
	s.wiggleSort(v2);
}
