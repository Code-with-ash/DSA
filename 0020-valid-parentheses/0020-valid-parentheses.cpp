class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int x = 0;
        int n = s.size();

        while (x < n) {

            if (s[x] == ')') {
                if (st.empty() || st.top() != '(')
                    return false;

                st.pop();
            }

            else if (s[x] == ']') {
                if (st.empty() || st.top() != '[')
                    return false;

                st.pop();
            }

            else if (s[x] == '}') {
                if (st.empty() || st.top() != '{')
                    return false;

                st.pop();
            }

            else {
                st.push(s[x]);
            }

            x++;
        }

        return st.empty();
    }
};