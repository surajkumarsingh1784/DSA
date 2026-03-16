class Solution {
public:
    string decodeString(string s) {
        stack<int> countSt;
        stack<string> strSt;

        string curr = "";
        int num = 0;

        for(char c : s){

            if(isdigit(c)){
                num = num*10 + (c-'0');
            }

            else if(c == '['){
                countSt.push(num);
                strSt.push(curr);
                num = 0;
                curr = "";
            }

            else if(c == ']'){
                int repeat = countSt.top();
                countSt.pop();

                string temp = curr;
                curr = strSt.top();
                strSt.pop();

                while(repeat--){
                    curr += temp;
                }
            }

            else{
                curr += c;
            }
        }

        return curr;
    }
};