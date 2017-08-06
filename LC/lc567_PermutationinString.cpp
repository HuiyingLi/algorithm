
class Solution {
public:
   
    bool checkInclusion(string s1, string s2) {
        if(s2.length()==0)
            return false;
        if(s2.length()<s1.length())
            return false;
        else if(s1==s2)
            return true;
        int freq[30];
        memset(freq, 0, sizeof(freq));
        for(int i=0; i<s1.length();i++){
            freq[s1[i]-'a']++;
        }
        bool ans = false;
        int f[30];
        memset(f, 0, sizeof(f));
        
        for(int i=0; i<s1.length();i++){
            f[s2[i]-'a']++;
        }
        for(int i=0; i < 26; i++){
            f[i] -= freq[i];
        }
        bool eq=true;
        for(int m=0;m<26;m++)
            if(f[m]!=0){
                eq=false;
                break;
            }
        if(eq)
            return true;
       
        for(int i=0; i< s2.length()-s1.length(); i++){//start
            //omit s2[i]
            int o = s2[i]-'a';
            f[o]--;
            //add s2[i+len(s1)]
            int a = s2[i+s1.length()]-'a';
            f[a]++;
            
            
            if(f[o]==0&&f[a]==0){
                bool eq=true;
                for(int m=0;m<26;m++)
                    if(f[m]!=0){
                        eq=false;
                        break;
                    }
                if(eq)
                    return true;
            }
        }
        return false;
    }
};
