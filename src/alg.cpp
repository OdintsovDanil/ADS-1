// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"

bool checkPrime(uint64_t value) {
    if (value == 2) {
        return true;
    }
    if (value == 0 || value == 1 || value % 2 == 0) {
        return false;
    }
    for (uint64_t i = 3; i <= sqrt(value); i += 2) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 1) {
        return 2;
    }
    uint64_t check = 1;
    for (uint64_t i = 3; true; i += 2) {
        if (checkPrime(i)) {
            ++check;
        }
        if (check == n) {
            return i;
        }
    }
}

uint64_t nextPrime(uint64_t value) {
    for (++value; true; value++) {
        if (checkPrime(value)) {
            return value;
        }
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t summ = 2;
    if (hbound == 2) {
        return summ;
    }
    for (uint64_t i = 3; i < hbound; i++) {
        if (checkPrime(i)) {
            summ += i;
        }
    }
    return summ;
}
