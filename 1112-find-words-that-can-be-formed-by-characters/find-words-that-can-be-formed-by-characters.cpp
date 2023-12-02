class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> ch;

        for (char c : chars) {
            ch[c]++;
        }

        int res = 0;
        for (const string& word : words) {
            map<char, int> copy = ch;

            for (char c : word) {
                if (copy.find(c) != copy.end() && copy[c] != 0) {
                    copy[c] -= 1;
                } else {
                    res -= word.length();
                    break;
                }
            }

            res += word.length();
        }

        return res;     
    }
};