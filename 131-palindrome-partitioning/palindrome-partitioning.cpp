class Solution {
public:
    bool isPal(string s, int start, int end){
        while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
        return true;
    }

    void part(int idx, string s, vector<vector<string>>&ans, vector<string>&path){
        if(idx == s.size()){
            ans.push_back(path);
            return;
        }
        
        for(int i = idx; i<s.size(); i++){
            if(!isPal(s, idx, i)) continue; //selected part is not a palindrome
            path.push_back(s.substr(idx, i-idx+1));
            part(i+1, s, ans, path);
            path.pop_back();
        }
        
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        part(0, s, ans, path);
        return ans;
    }
};