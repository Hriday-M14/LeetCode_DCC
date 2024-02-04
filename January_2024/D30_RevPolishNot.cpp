// Evaluate Reverse Polish Notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> s;
        int sz = tokens.size();
        for(int i=0; i<sz; i++){
            if(tokens[i].size()>1 || isdigit(tokens[i][0]))
                s.push(stoi(tokens[i]));
            else{
                char curr = tokens[i][0];
                long long int a = s.top();
                s.pop();
                long long int b = s.top();
                s.pop();
                if(curr=='+')
                    s.push(b+a);
                else if(curr=='-')
                    s.push(b-a);
                else if(curr=='*')
                    s.push(b*a);
                else
                    s.push(b/a);
            }
        }
        return s.top();
    }
};