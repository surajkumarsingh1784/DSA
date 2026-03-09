class Solution {
public:
    int lengthLongestPath(string input) {
        unordered_map<int, int> pathLen; // depth -> cumulative length
        pathLen[0] = 0; // root level
        int maxLen = 0;

        int i = 0;
        while (i < input.size()) {
            // Determine the depth by counting '\t'
            int depth = 0;
            while (i < input.size() && input[i] == '\t') {
                depth++;
                i++;
            }

            // Read the name until '\n' or end
            int start = i;
            while (i < input.size() && input[i] != '\n') i++;
            string name = input.substr(start, i - start);
            i++; // skip '\n'

            if (name.find('.') != string::npos) {
                // It's a file, update max length
                maxLen = max(maxLen, pathLen[depth] + (int)name.size());
            } else {
                // It's a directory, update cumulative length for next depth
                pathLen[depth + 1] = pathLen[depth] + (int)name.size() + 1; // +1 for '/'
            }
        }

        return maxLen;
    }
};