//
// Created by josia on 11/4/2025.
//

#ifndef COP3530_HELPERS_H
#define COP3530_HELPERS_H
#include "record.h"

//comparator for both heaps

inline bool higher(const Record& a, const Record& b) {
    return a.get_sales() > b.get_sales();
}









#endif //COP3530_HELPERS_H