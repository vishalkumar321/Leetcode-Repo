class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char ch : expression) {
            if (ch == ',')
                continue;

            if (ch != ')') {
                st.push(ch);
                continue;
            }

            bool hasTrue = false;
            bool hasFalse = false;

            while (st.top() != '(') {
                char val = st.top();
                st.pop();

                if (val == 't')
                    hasTrue = true;
                else if (val == 'f')
                    hasFalse = true;
            }

            st.pop(); 

            char op = st.top();
            st.pop();

            bool result;

            if (op == '!') {
                result = hasFalse;
            } else if (op == '&') {
                result = !hasFalse;
            } else { 
                result = hasTrue;
            }

            st.push(result ? 't' : 'f');
        }

        return st.top() == 't';
    }
};

