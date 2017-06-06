class NestedIterator {
public:
    queue<int> ans;
    //vector<NestedInteger> l;
    void dfs(vector<NestedInteger>& in){
        for(int i=0;i<in.size();i++){
            if(in[i].isInteger()){
                ans.push(in[i].getInteger());
            }else{
                dfs(in[i].getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
    }

    int next() {
        int a=ans.front();
        ans.pop();
        return a;
    }

    bool hasNext() {
        return !ans.empty();
            
    }
};

