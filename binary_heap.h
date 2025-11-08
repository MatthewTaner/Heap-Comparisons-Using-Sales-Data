//
// Created by josia on 11/4/2025.
//

#ifndef COP3530_BINARY_HEAP_H
#define COP3530_BINARY_HEAP_H

#include <vector>
#include "record.h"


class BinaryHeap {
public:
    void build(const std::vector<Record>& rows); // bottom-up heapify
    void push(const Record& r);          // insert one
    const Record& top() const;     // read max
    void pop();            // remove max
    bool empty() const { return heap.empty(); }

private:
    std::vector<Record> heap;

    // index math
    static inline std::size_t left (std::size_t i)  { return 2*i + 1; }
    static inline std::size_t right(std::size_t i)  { return 2*i + 2; }
    static inline std::size_t parent(std::size_t i) { return (i - 1) / 2; }

    void heapify_up(std::size_t i);      // after push
    void heapify_down(std::size_t i);    // after pop
};












#endif //COP3530_BINARY_HEAP_H