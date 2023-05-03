#include <string>
#include <iostream>
#include <memory>
#include <map>

#define ALPHABET_SIZE 26

struct TrieNode {
    bool is_word;
    std::map<char, std::shared_ptr<TrieNode>> next;

    TrieNode() = default;
};

class Trie {
public:
    Trie() {
        root = std::make_shared<TrieNode>();
    }

    void insert(std::string word) {
        auto p = root;
        for (int ix = 0; ix < word.length(); ++ix) {
            char ch = word[ix];
            if (p->next.count(ch) == 0) {
                p->next[ch] = std::make_shared<TrieNode>();
            }
            if (ix == word.length() - 1) {
                p->next[ch]->is_word = true;
            }
            p = p->next[ch];
        }
    }
    
    bool search(std::string word) {
        auto p = root;
        for (int ix = 0; ix < word.length(); ++ix) {
            char ch = word[ix];
            if (p->next.count(ch) == 0) {
                return false;
            } else if (ix == word.length() - 1 && !p->next[ch]->is_word) {
                return false;
            }
            p = p->next[ch];
        }

        return true;
    }
    
    bool startsWith(std::string prefix) {
        auto p = root;
        for (int ix = 0; ix < prefix.length(); ++ix) {
            char ch = prefix[ix];
            if (p->next.count(ch) == 0) {
                return false;
            }
            p = p->next[ch];
        }

        return true;
    }

private:
    std::shared_ptr<TrieNode> root{nullptr};
};

int main() {
    Trie *trie = new Trie();
    trie->insert("apple");
    std::cout << trie->search("apple") << std::endl;
    std::cout << trie->search("app") << std::endl;
    std::cout << trie->startsWith("app") << std::endl;

    return 0;
}
