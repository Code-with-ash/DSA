class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int x = 0;
        int n = tokens.size();
        while (x < n) {
            if (tokens[x] == "+") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second + first);
            } else if (tokens[x] == "/") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second / first);
            } else if (tokens[x] == "*") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second * first);
            } else if (tokens[x] == "-") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second - first);
            } else {
              st.push(stoi(tokens[x]));
            }
            x++;
        }
        return st.top();
    }
};