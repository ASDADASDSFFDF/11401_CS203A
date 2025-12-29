/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h

   Developer: 張景翔 <Ben950810@gmail.com>
 */

#include "hash_fn.h"

int myHashInt(int key, int m) {
      return ((key % m + m)*13+17) % m;
}
int myHashString(const char *str, int m) {
    unsigned long hash = 5381;
    int c;
    const int p = 13;
    unsigned long p_pow = 1;
    while ((c = *str++)) {
        hash = ((hash*33 + c)* p_pow) % m; // hash * 33 + c
        p_pow = (p_pow * p) % m;
    }
     return hash;
}
