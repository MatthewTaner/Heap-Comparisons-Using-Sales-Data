//
// Created by mattj on 11/4/2025.
//

#include "fourary_heap.h"
#include "helpers.h"
#include <stdexcept>
using namespace std;

fourary_heap::fourary_heap() {

}


void fourary_heap::build(const std::vector<Record>& records) {
    heap = records;
    int n = static_cast<int>(heap.size());
    for (int i = n/4 - 1; i >= 0; --i) {
        heapifyDown(i);
    }
}

int fourary_heap::firstChild(int ind) {
    return (ind * 4) + 1;
}

void fourary_heap::push(const Record& record)
 {
    heap.push_back(record);
    heapifyUp(heap.size() - 1);
}

void fourary_heap::pop() {
    if (heap.size() > 1) {
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapifyDown(0);
    }
    else if (heap.size() == 1) {
        heap.pop_back();
    }
}

const Record& fourary_heap::top() const
{
    if (heap.size() == 0) {
        throw out_of_range("heap is empty");
    }
    return heap[0];
}

void fourary_heap::heapifyUp(int ind) {
    if (ind == 0) return;

    int parent = (ind - 1) / 4;

    if (heap[ind].get_sales() > heap[parent].get_sales()) {
        swap(heap[ind], heap[parent]);
        heapifyUp(parent);
    }
}

void fourary_heap::heapifyDown(int ind) {
    int greatest = ind;
    int first = firstChild(ind);

    for (int i = 0; i < 4; i++) {
        int current = first + i;

        if (current >= heap.size()) {
            break;
        }

        if (heap[current].get_sales() > heap[greatest].get_sales()) {
            greatest = current;
        }
    }

    if (greatest != ind) {
        swap(heap[ind], heap[greatest]);
        heapifyDown(greatest);
    }
}