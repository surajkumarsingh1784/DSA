class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n1 = s1.size();
        int n2 = s2.size();
        
        if(n1 > n2) return false;
        
        vector<int> a(26,0), b(26,0);
        
        for(int i = 0; i < n1; i++){
            a[s1[i]-'a']++;
            b[s2[i]-'a']++;
        }
        
        if(a == b) return true;
        
        for(int i = n1; i < n2; i++){
            b[s2[i]-'a']++;
            b[s2[i-n1]-'a']--;
            
            if(a == b) return true;
        }
        
        return false;
    }
};