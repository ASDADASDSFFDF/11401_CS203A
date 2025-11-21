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
    // TODO: replace with your own design
   return (key % m + m) % m;  // basic division method
}

int myHashString(const std::string& str, int m) {
const int p = 31;
    unsigned long hash = 0;
    // p_pow 用於儲存 p 的當前冪次 (p^i)，迭代更新以避免昂貴的求冪運算。
    unsigned long p_pow = 1;
    // 遍歷字串中的每個字符
    for (char c : str) {
        hash = (hash + ((unsigned long)c * p_pow)) % m;
        p_pow = (p_pow * p) % m;
    }
    return static_cast<int>(hash);
}