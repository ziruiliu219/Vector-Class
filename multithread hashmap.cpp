//
//  multithread hashmap.cpp
//  
//
//  Created by ZIRUI LIU on 2023-12-25.
//

#include "multithread hashmap.hpp"
#include <iostream>
#include <unordered_map>
#include <mutex>
#include <thread>

template<typename Key, typename Value>
class ConcurrentHashMap {
public:
    void insert(const Key& key, const Value& value) {
        std::unique_lock<std::mutex> lock(mutex_);
        map_[key] = value;
    }

    bool get(const Key& key, Value& value) {
        std::unique_lock<std::mutex> lock(mutex_);
        auto it = map_.find(key);
        if (it != map_.end()) {
            value = it->second;
            return true;
        }
        return false;
    }

    bool update(const Key& key, const Value& value) {
        std::unique_lock<std::mutex> lock(mutex_);
        auto it = map_.find(key);
        if (it != map_.end()) {
            it->second = value;
            return true;
        }
        return false;
    }

    bool remove(const Key& key) {
        std::unique_lock<std::mutex> lock(mutex_);
        auto it = map_.find(key);
        if (it != map_.end()) {
            map_.erase(it);
            return true;
        }
        return false;
    }

    void clear() {
        std::unique_lock<std::mutex> lock(mutex_);
        map_.clear();
    }

private:
    std::unordered_map<Key, Value> map_;
    std::mutex mutex_;
};

int main() {
    ConcurrentHashMap<std::string, int> myMap;

    // Thread 1
    std::thread t1([&myMap]() {
        myMap.insert("One", 1);
        myMap.insert("Two", 2);
        myMap.insert("Three", 3);
    });

    // Thread 2
    std::thread t2([&myMap]() {
        int value;
        if (myMap.get("Two", value)) {
            std::cout << "Thread 2: Value for key 'Two' is " << value << std::endl;
        } else {
            std::cout << "Thread 2: Key 'Two' not found" << std::endl;
        }
    });

    // Thread 3
    std::thread t3([&myMap]() {
        myMap.update("Two", 22);
    });

    // Thread 4
    std::thread t4([&myMap]() {
        myMap.remove("Three");
    });

    // Thread 5
    std::thread t5([&myMap]() {
        myMap.clear();
    });

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}

