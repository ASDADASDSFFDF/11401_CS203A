/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp

   Developer: 張景翔 <Ben950810@gmail.com>
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
   rreturn ((key % m + m)*19+13) % m;
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 2166136261u;
    for (char c : str) {
        hash ^= c;
        hash *= 16777619;
    }
    return hash % m;
}
