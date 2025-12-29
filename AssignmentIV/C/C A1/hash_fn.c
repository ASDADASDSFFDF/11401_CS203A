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
    
    
    return (key % m + m)*13+11 % m;
    }

int myHashString(const char *str, int m) {
    // 雜湊算法中使用的素數
    const int p = 13;
    // 雜湊值。使用 unsigned long 以確保在計算中間結果時不會溢出 (雖然最終會模 m)。
    unsigned long hash = 0;
    // p_pow 用於儲存 p 的當前冪次 (p^i)，迭代更新以避免昂貴的求冪運算。
    unsigned long p_pow = 1;
    // C 語言中通常使用索引或檢查空字元 '\0' 來遍歷字串。
    for (size_t i = 0; str[i] != '\0'; i++) {
        // 獲取當前字符的 ASCII 值
        unsigned long char_val = (unsigned long)str[i];
        //(char_val * p_pow) % m : 計算當前項並模 m
        unsigned long term = (char_val * p_pow) % m;
        // 更新 p 的冪次：p_pow = (p_pow * p) mod m
        p_pow = (p_pow * p) % m;
    }
    // 將最終的雜湊值轉換為 int 類型並返回
    return (int)hash;
}
