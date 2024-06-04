#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> s(wordList.begin(), wordList.end());

        if (s.find(endWord) == s.end()) return 0;

        std::queue<std::string> q;
        q.push(beginWord);
        s.erase(beginWord);

        int count = 1;
        while (!q.empty()) {
            int size = q.size();
            
            for (int k = 0; k < size; ++k) {
                std::string str = q.front();
                q.pop();

                if (str == endWord) return count;

                for (int i = 0; i < str.size(); ++i) {
                    char c = str[i];

                    for (int j = 0; j < 26; ++j) {
                        str[i] = j + 'a';
                        
                        std::unordered_set<std::string>::const_iterator got = s.find(str);

                        if (got == s.end()) continue;

                        q.push(str);
                        s.erase(str);
                    }

                    str[i] = c;
                }
            }

            ++count;
        }

        return 0;
    }
};