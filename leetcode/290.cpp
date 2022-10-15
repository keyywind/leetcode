class SolutionSub
{
public:
    static inline string format_key(const string & key)
    {
        return "0" + key;
    }
    static void separate_words(vector <string> & wordList, const string & str)
    {
        int start = 0, dist = 1, i, length = str.length();
        for (i = 0; i < length; ++i)
        {
            if (str[i] == ' ')
            {
                wordList.push_back(str.substr(start, dist));
                start = i + 1;
            }
            else
            {
                dist = i - start + 1;
            }
        }
        wordList.push_back(str.substr(start, dist));
    }
    static bool word_pattern(const string & pattern, const string & s)
    {
        map <string, string> dictionary;
        vector <string> wordList;  separate_words(wordList, s);
        string key1, key2;
        int i, len1 = pattern.length(), len2 = wordList.size();
        if (len1 != len2)
            return false;
        for (i = 0; i < len1; ++i)
        {
            key1 = pattern[i];
            key2 = format_key(wordList[i]);
            if ((dictionary.find(key1) != dictionary.end()) &&
                (dictionary.find(key2) != dictionary.end())) {
                if ((dictionary[key1] != key2) || (dictionary[key2] != key1))
                    return false;
            }
            else if ((dictionary.find(key1) == dictionary.end()) &&
                     (dictionary.find(key2) == dictionary.end())) {
                dictionary[key1] = key2;
                dictionary[key2] = key1;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        return SolutionSub::word_pattern(pattern, s);
    }
};
