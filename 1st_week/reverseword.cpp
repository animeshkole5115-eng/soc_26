class Solution {
public:
    string reverseWords(string s) {
        int  size=s.length();
        string ans;
        reverse(s.begin(),s.end());
        for(int i=0;i<size;i++){
            string word;
            while(i<size && s[i]!=' '){
                word=word+s[i];
                i++;
            }
            if(word.length()>0){
                reverse(word.begin(),word.end());
                ans+=" "+word;
            }
            
        }
        return(ans.substr(1));
    }
};