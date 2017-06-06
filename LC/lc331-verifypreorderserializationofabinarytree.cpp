class Solution {
public:
    bool isValidSerialization(string po) {
        int i=po.length()-1;
        int b=i+1;
        while(i>=0){
           
            while(i>=0&&po[i]!=',')
                i--;
            string c=po.substr(i+1,b-i-1);
            if(c=="#"){
                b=i;
                i--;
                continue;
            }
            
            if(po.length()-i-1>=c.length()+4){
                if(po.substr(i+c.length()+1,4)==",#,#"){
                    po=po.substr(0,i+1)+po.substr(i+c.length()+4,po.length()-i-c.length()-4);
                }else{
                    return false;
                }
            }else{
                return false;
            }
            b=i;
            i--;
        }
        
        if(po=="#")
            return true;
        return false;
    }
};
