class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
            a.push(')');
            else if(s[i]=='[')
            a.push(']');
            else if(s[i]=='{')
            a.push('}');

            else{
                if(!a.empty() && a.top()==s[i]){
                a.pop();
                continue;
                }
                else
                return false;
            }

        }
        if(a.empty())
        return true;
        else
        return false;
    }
};