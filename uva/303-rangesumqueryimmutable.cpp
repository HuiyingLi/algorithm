class NumArray {
public:
    vector<int> n;
    NumArray(vector<int> nums) {
        int sum=0;
        n.push_back(0);
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            n.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        return n[j+1]-n[i];
    }
};

