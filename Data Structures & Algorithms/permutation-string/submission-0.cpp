class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size()) return false;

        unordered_map<char, int> mp1, mp2;

        for (char c : s1)
            mp1[c]++;

        int i = 0, j = 0;

        for (; j < s1.size(); j++)
            mp2[s2[j]]++;

        if (mp1 == mp2) return true;

        while (j < s2.size()) {

            mp2[s2[i]]--;
            if (mp2[s2[i]] == 0)
                mp2.erase(s2[i]);

            mp2[s2[j]]++;

            if (mp1 == mp2)
                return true;

            i++;
            j++;
        }

        return false;
    }
};