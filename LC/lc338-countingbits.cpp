class Solution {
public:
    int pow[32]={1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
    vector<int> countBits(int num) {
        vector<int> ans;
        int n=2;
        int cnt=0;
        for(int i=0;i<=num;i++){
            if(i==0)
                ans.push_back(0);
            else if(i==1)
                ans.push_back(1);
            else if(i==2)
                ans.push_back(1);
            else if(i==3)
                ans.push_back(2);
            else{
                
                ans.push_back(ans[cnt]+1);
                if(cnt==pow[n]-1){
                    cnt=0;
                    n++;
                }else
                    cnt++;
            }
        }
        return ans;
    }
};
