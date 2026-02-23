class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> adj;
    unordered_map<string, int> level;
    string begin;

    void dfs(string word, vector<string>& path) {
        if (word == begin) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (auto prev : adj[word]) {
            path.push_back(prev);
            dfs(prev, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        begin = beginWord;
        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;

        int wordLen = beginWord.size();

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            int currLevel = level[word];

            for (int i = 0; i < wordLen; i++) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (!dict.count(temp)) continue;

                    if (!level.count(temp)) {
                        level[temp] = currLevel + 1;
                        q.push(temp);
                        adj[temp].push_back(word);
                    }
                    else if (level[temp] == currLevel + 1) {
                        adj[temp].push_back(word);
                    }
                }
            }
        }

        if (!level.count(endWord)) return {};

        vector<string> path;
        path.push_back(endWord);
        dfs(endWord, path);

        return ans;
    }
};