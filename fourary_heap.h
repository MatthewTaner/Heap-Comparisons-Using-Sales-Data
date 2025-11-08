//
// Created by mattj on 11/4/2025.
//
#pragma once
#include <vector>
#include "record.h"

class fourary_heap {
public:
    fourary_heap();
    void build(const std::vector<Record>& records);
    void push(const Record& record);
    void pop();
    const Record& top() const;
    bool empty() const { return heap.empty(); }
    std::size_t size() const { return heap.size(); }

private:
    std::vector<Record> heap;
    int firstChild(int ind);
    void heapifyUp(int ind);
    void heapifyDown(int ind);
};
