#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class RandomizedCollection {
  private:
      std::vector<int> keys_;
      std::unordered_map<int, std::vector<std::size_t>> map_;

  public:
    /** Initializes data structure here. */
    RandomizedCollection() {}

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int key) {
        bool retval = false;
        if (map_.find(key) == map_.end()) {
            retval = true;
        }
        map_[key].push_back(keys_.size());
        keys_.push_back(key);
        return retval;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int key) {
        
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        
    }
};


int main(int argc, char **argv) {
    return 0;
}
