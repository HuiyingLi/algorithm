struct pr{
public:
    int freq;
    int val;
    pr(int f, int v):freq(f),val(v){}
    bool operator <(pr a) const  {  return freq < a.freq; }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pr> q;
        map<int, int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])==m.end()){
                m[nums[i]]=0;
            }
            m[nums[i]]+=1;
        }
        for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
            int key=it->first;
            int v=it->second;
            pr p(v,key);
            q.push(p);
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(q.top().val);
            q.pop();
        }
        return ans;
    }
};
