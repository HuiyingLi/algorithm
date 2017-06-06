class Solution {
public:
    string getHint(string secret, string guess) {
        int freq[10]={0};
        int As=0,Bs=0;
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                As++;
                guess[i]='-';
            }else
                freq[secret[i]-'0']++;
        }
        for(int i=0;i<guess.length();i++){
            if(guess[i]!='-'){
                if(freq[guess[i]-'0']!=0){
                    freq[guess[i]-'0']--;
                    Bs++;
                }
            }
        }
        return to_string(As)+"A"+to_string(Bs)+"B";
    }
};
