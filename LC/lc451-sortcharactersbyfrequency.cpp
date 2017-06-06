struct pr{
public:
    int freq;
    char c;
    pr(int x, char a):freq(x),c(a){}
    bool operator < (pr& p) const{
        return p.freq<this->freq;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> d;
        for(int i=0;i<s.length();i++){
            if(d.find(s[i])==d.end()){
                d[s[i]]=0;
            }
            d[s[i]]++;
        }
        vector<pr> v;
        for(unordered_map<char,int>::iterator it=d.begin();it!=d.end();it++){
            pr p(it->second, it->first);
            v.push_back(p);
        }
        
        sort(v.begin(),v.end());
        string ans="";
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].freq;j++){
                ans+=v[i].c;
            }
        }
        return ans;
    }
};
