class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;

        int maxl = 0;

        unordered_set<char> seen;
        seen.insert(s[0]);

        int i = 0, j = 1;
        while (j < s.size()) {

            if(seen.count(s[j])){
                maxl=max(maxl,j-i);
                while(s[i]!=s[j]) {
                    seen.erase(s[i]);
                    i++;
                }
                i++;

            }
            else seen.insert(s[j]);

            j++;
        }

        maxl=max(maxl,j-i);
        return maxl;
    }
};
