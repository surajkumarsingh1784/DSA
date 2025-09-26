class Solution {
public:
    string reverseWords(string s) {
         stringstream ss(s);
    string word;
    vector<string> words;

    // Extract each word (ignores extra spaces automatically)
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse the order of words
    reverse(words.begin(), words.end());

    // Join words with single space
    string result;
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1)
            result += " ";
    }

    return result;
    }
};