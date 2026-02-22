class Solution {
public:
    bool parseBoolExpr(string e) {
        int n = e.size();
        stack<char> st;
        
        for(int i = 0; i < n; i++) {
            if(e[i] == 't' || e[i] == 'f' || e[i] == '!' || e[i] == '&' || e[i] == '|' || e[i] == '(') {
                st.push(e[i]);
            }
            else if(e[i] == ')') {
                vector<bool> values;
                while(st.top() != '(') {
                    char ch = st.top();
                    st.pop();
                    values.push_back(ch == 't'); // char to bool conversion
                }
                st.pop(); // Remove '('
                
                char op = st.top();
                st.pop();
                
                bool result;
                if(op == '!') {
                    result = !values[0];
                }
                else if(op == '&') {
                    result = true;
                    for(bool v : values) result &= v;
                }
                else { // '|'
                    result = false;
                    for(bool v : values) result |= v;
                }
                
                // Push result back
                st.push(result ? 't' : 'f');
            }
        }
        
        return st.top() == 't';
    }
};