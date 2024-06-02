#include <string>

class Trie {
public:
    Trie * m[26];
    bool end;

    Trie() {
        for (int i = 0; i < 26; i++) m[i] = nullptr;
        end = false;
    }
    
    void insert(std::string word) {
        Trie * iter = this;
    
        for (int i = 0; i < word.size(); ++i) {
            if (!iter->m[word[i] - 'a']) {
                iter->m[word[i] - 'a'] = new Trie();
            }

            iter = iter->m[word[i] - 'a'];
        }

        iter->end = true;
    }
    
    bool search(std::string word) {
        Trie * iter = this;
    
        for (int i = 0; i < word.size(); ++i) {
            if (!iter->m[word[i] - 'a']) {
                return false;
            }

            iter = iter->m[word[i] - 'a'];
        }

        if (!iter->end) return false;

        return true;
    }
    
    bool startsWith(std::string prefix) {
        Trie * iter = this;
    
        for (int i = 0; i < prefix.size(); ++i) {
            if (!iter->m[prefix[i] - 'a']) {
                return false;
            }

            iter = iter->m[prefix[i] - 'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */