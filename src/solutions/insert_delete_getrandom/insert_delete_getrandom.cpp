#include <cstdlib>
#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <algorithm>


class RandomizedSet {
  private:
    std::vector<int> keys_;
    std::unordered_map<int, std::vector<int>::size_type> map_;

  public:
    /**
     * Inserts a value to the set.
     * @param {int} key
     * @return {bool} true if the set did not already contain the specified key.
     */
    bool insert(int key) {
        if (map_.find(key) != map_.end()) {
            return false;
        }
        map_[key] = keys_.size();
        keys_.push_back(key);
        return true;
    }

    /**
     * Removes the specified key from the set.
     * @return {bool} true if the set contained the specified key.
     */
    bool remove(int key) {
        if (map_.find(key) == map_.end()) {
            return false;
        }

        std::vector<int>::size_type index = map_[key];
        map_[keys_.back()] = index;
        keys_[index] = keys_.back();

        keys_.resize(keys_.size() - 1);
        map_.erase(key);

        return true;
    }

    /**
     * Randomly picks a key from the set and returns it.
     * @return {int}
     */
    int getRandom() {
        int index = rand() % keys_.size();
        return keys_[index];
    }

    /**
     * Prints the internal data structure to std::cout.
     */
    void print() {
        std::copy(keys_.begin(), keys_.end(),
                  std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }
};


int main(int argc, char **argv) {
    RandomizedSet container;
    std::string operation;
    while (std::cin >> operation) {
        if (operation == "remove") {
            int key;
            std::cin >> key;
            container.remove(key);
            // container.print();
        } else if (operation == "insert") {
            int key;
            std::cin >> key;
            container.insert(key);
            // container.print();
        } else if (operation == "get") {
            std::cout << container.getRandom() << std::endl;
        } else if (operation == "print") {
            // container.print();
        }
    }
    return 0;
}
