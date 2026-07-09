class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.emplace(beginWord, 1);
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            if (word == endWord)
                return level;
            for (int i = 0; i < word.size(); i++) {
                char original = word[i]; // h
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c; // word = ait , bit , cit
                    if (st.find(word) != st.end()) {
                        q.emplace(word, level + 1);
                        st.erase(word);
                    }
                }

                word[i] = original;
            }
        }
        return 0;
    }
};