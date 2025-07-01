class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        int record[1000]; // Max size according to constraints
        int index = 0;

        for (int i = 0; i < n; ++i) {
            string op = operations[i];

            if (op == "C") {
                index--; // Remove last score
            } 
            else if (op == "D") {
                record[index] = 2 * record[index - 1];
                index++;
            } 
            else if (op == "+") {
                record[index] = record[index - 1] + record[index - 2];
                index++;
            } 
            else {
                record[index] = stoi(op);
                index++;
            }
        }

        int sum = 0;
        for (int i = 0; i < index; ++i) {
            sum += record[i];
        }

        return sum;
    }
};

