class Solution {
public:
    NestedInteger deserialize(string s) {
        stack<NestedInteger> stk;
        NestedInteger ans;
        if(s.length()==0) return ans;
        stk.push(ans);
        //NestedInteger cur;
        int i=0;
        while(i<s.length()){
            if(s[i]=='['){
                NestedInteger ni;
                stk.push(ni);
                i++;
            }else if(s[i]>='0'&&s[i]<='9'||s[i]=='-'){
                int b=i;
                while(i<s.length()&&s[i]>='0'&&s[i]<='9'||s[i]=='-'){
                    i++;
                }
                string sn=s.substr(b,i-b);
                int v=atoi(sn.c_str());
                cout<<v<<endl;
                NestedInteger ni(v);
                stk.top().add(ni);
            }else if(s[i]==']'){
                NestedInteger ni=stk.top();
                stk.pop();
                stk.top().add(ni);
                i++;
            }else{
                i++;
            }
        }
        return stk.top().getList()[0];
    }
};
