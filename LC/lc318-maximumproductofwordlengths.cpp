class Solution {
public:
    static bool myfunction (string a,string b) { return (a.length()>b.length()); }
    int maxProduct(vector<string>& words) {
        int ml=0;
        sort(words.begin(),words.end(),myfunction);
        vector<long> wp;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            long nn=0;
            for(int k=0;k<s.length();k++){
                int p=s[k]-'a';
                long m=(1<<p);
                nn|=m;
    //            cout<<nn<<" ";
            }
   //         cout<<hex<<nn<<"\n";
            wp.push_back(nn);
        }
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if((wp[i]&wp[j])==0){
                    int pd=words[i].length()*words[j].length();
                    if(pd>ml)
                        ml=pd;
                    break;
                }
            }
        }
        return ml;
    }
};
