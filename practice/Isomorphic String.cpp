class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        map<char, int> m1, m2;
        for (int k=0; k<n; k++){
            if (m1[s[k]]==0 && m2[t[k]]==0){
                m1[s[k]] = k+1;
                m2[t[k]] = k+1;
            }
            if (m1[s[k]]!=m2[t[k]]){
                return false;
            }
        }
        return true;
    }
};


// Question link - https://leetcode.com/problems/isomorphic-strings/
