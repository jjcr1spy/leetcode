#include <string>

class Trie {
public:
    Trie * m[26];
    bool end;

    Trie() {
        for (int i = 0; i < 26; i++) m[i] = nullptr;
        end = false;
    }
    
    void insert(std::string& word) {
        Trie * iter = this;
    
        for (int i = 0; i < word.size(); ++i) {
            if (!iter->m[word[i] - 'a']) {
                iter->m[word[i] - 'a'] = new Trie();
            }

            iter = iter->m[word[i] - 'a'];
        }

        iter->end = true;
    }
    
    bool search(std::string& word, int start, Trie * node) {
        if (!node) return false;

        if (start == word.size()) {
            return node->end;
        }

        if (word[start] != '.') {
            return search(word, start + 1, node->m[word[start] - 'a']);
        }

        if (word[start] == '.') {
            for (int i = 0; i < 26; i++) {
                if (search(word, start + 1, node->m[i])) {
                    return true;
                }
            }
        } 

        return false;
    }
};

class WordDictionary {
public:
    Trie * m;

    WordDictionary() {
        m = new Trie();
    }
    
    void addWord(std::string word) {
        m->insert(word);
    }
    
    bool search(std::string word) {
        return m->search(word, 0, m);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */