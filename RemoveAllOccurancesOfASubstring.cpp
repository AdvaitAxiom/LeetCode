https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/?envType=daily-question&envId=2025-02-11


//ANS-1
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos;
        while((pos=s.find(part))!=string::npos){    //s.find(part) returns the index where part occurs first in the s.
        // string ::npos is a special constant in cpp that means "not found" and is the largest possible size_t value.
            s.erase(pos,part.length());
        }
        return(s);
    }
};

//ANS-2
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans;
        int m = part.length();

        for(char ch : s){
            ans += ch;
            if(ans.length() >= part.length() && ans.substr(ans.length()-m, m)==part){
                ans.erase(ans.length()-m);  //erase from last index
            }
        }
        return ans;
    }
};