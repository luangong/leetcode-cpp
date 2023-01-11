class TrieNode {
private:
    bool terminal;
    TrieNode *children[26];
public:
    // Initialize your data structure here.
    TrieNode(bool terminal=true) : terminal(terminal) {
        fill(children, children + 26, nullptr);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        insert(root, s);
    }

    void insert(TrieNode *root, string s) {
        if (s.empty()) {
            root->terminal = true;
            return;
        }
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *node = root;
        while () {}
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
