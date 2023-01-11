/*
 * LRU Cache
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and set.
 *
 * - get(key)
 *
 *   Get the value (will always be positive) of the key if the key exists in
 *   the cache, otherwise return -1.
 *
 * - set(key, value)
 *
 *   Set or insert the value if the key is not already present.  When the
 *   cache reached its capacity, it should invalidate the least recently used
 *   item before inserting a new item.
 *
 * Tags: Data Structure
 */

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <unordered_map>
#include <algorithm>

class LRUCache {
 private:
  // A doubly-linked list of key-value pairs, with the font node being the most recently
  // used item, and the back node being the least recently used item.
  std::list<std::pair<int, int>> items;

  // Map keys to iterators (pointers) to items in the doubly-linked list
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;

  // The capacity of the cache
  int capacity;

 public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    if (cache.find(key) == cache.end()) {
        return -1;
    }
    // Move the key-value pair to the front of the list
    items.splice(items.begin(), items, cache[key]);
    return cache[key]->second;
  }

  void put(int key, int value) {
    if (cache.find(key) != cache.end()) {
      // If the key is in the cache then update its associated value and then move the
      // key-value pair to the front of the list
      cache[key]->second = value;
      items.splice(items.begin(), items, cache[key]);
    } else {
      // If the cache is full then remove the least-recently used item at the back of the
      // list
      if (items.size() == capacity) {
        cache.erase(items.back().first);
        items.pop_back();
      }
      items.push_front(std::make_pair(key, value));
      cache[key] = items.begin();
    }
  }

  void print() {
    // for (const auto& item : items) {
    //   std::cout << item.first << "\t" << item.second << std::endl;
    // }
    std::for_each(items.begin(), items.end(), [](const std::pair<int, int>& item) {
      std::cout << item.first << "\t" << item.second << std::endl;
    });
  }
};
