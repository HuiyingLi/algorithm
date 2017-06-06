class NumMatrix {
public:
    vector<vector<int> > n;
    NumMatrix(vector<vector<int>> matrix) {
        for(int i=0;i<matrix.size();i++){
            vector<int> v;
            if(i==0){
                v.push_back(matrix[0][0]);
                for(int j=1;j<matrix[0].size();j++)
                    v.push_back(matrix[0][j]+v[j-1]);
                n.push_back(v);
                continue;
            }
            for(int j=0;j<matrix[i].size();j++){
                if(j==0){
                    v.push_back(n[i-1][j]+matrix[i][j]);
                    continue;
                }
                v.push_back(n[i-1][j]+v[j-1]-n[i-1][j-1]+matrix[i][j]);
            }
            n.push_back(v);
        }
        for(int i=0;i<n.size();i++){
            for(int j=0;j<n[0].size();j++){
                cout<<n[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int a, b, c;
        a=row1>0?n[row1-1][col2]:0;
        b=col1>0?n[row2][col1-1]:0;
        c=(row1>0&&col1>0)?n[row1-1][col1-1]:0;
        int res=n[row2][col2]-a-b+c;
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
