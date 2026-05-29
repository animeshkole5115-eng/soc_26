class Solution {
public:
    bool isAnagram(string s, string t) {
        int alp[26]={0};
        if(s.length()==t.length()){
            for(int i=0;i<s.length();i++){
                alp[s[i]-'a']++;
                alp[t[i]-'a']--;

            }
            for(int i=0;i<26;i++){
                if(alp[i]!=0)
                return 0;
            }
            return 1;

        }
        else
        return 0;
    }
};