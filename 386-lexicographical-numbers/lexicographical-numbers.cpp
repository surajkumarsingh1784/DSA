class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int num = 1;

        for (int i = 0; i < n; ++i) {
            result.push_back(num);

            if (num * 10 <= n) {
                // Go deeper in the tree
                num *= 10;
            } else {
                // If next number exceeds n, move up until we can increment
                if (num >= n) num /= 10;

                num += 1;

                while (num % 10 == 0) num /= 10; // remove trailing zeros
            }
        }

        return result;
    }
};