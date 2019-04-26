/*--- max_heap.cpp -----------------------------------------------
  This file implements hax_heap.hpp member functions.
-------------------------------------------------------------------------*/

#include "max_heap.h"
#include <stdexcept>

max_heap::max_heap(int n){
	data = new text_item[n];
	numItems = 0;
}

int c;

max_heap::~max_heap()
{
	delete [] data;
}

bool max_heap::empty() const {
	return (numItems == 0);
}

int max_heap::size() const {
	return numItems;
}

text_item& max_heap::top() {
	if (empty()) {
		throw std::logic_error("Heap is empty, can't access top!");
	}
	return data[0];
}


//--- You must comple the following functions:


text_item max_heap::delete_max() {
	if (empty()) {
		throw std::logic_error("Cannot delete, heap is empty!");
	} else {
		// ADD CODE HERE
        text_item deleted = top();
        swap_down(0);
        delete data[c];
        numItems--;
        sort(data, numItems);
		// Fix this so it correctly deletes
		// and maintains the heap-order property
		// required for a max-heap

		// returning something so it compiles:
		return deleted;
	}
}

void max_heap::swap_down(int i) {
	// ADD CODE HERE
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    int min = i;
    if (leftChild < numItems && data[leftChild].freq < data[min].freq)
        min = leftChild;
    if (rightChild < numItems && data[rightChild].freq < data[min].freq)
        min = rightChild;
    if (max != i) {
        swap(data[i], data[min]);
        swap_down(min);
    }
    c = min;
	// Fix this so it correctly swaps
}

void max_heap::insert(const text_item & item) {
	// ADD CODE HERE

	// Fix this so it correctly inserts
	// and maintains the heap-order property
	// required for a max-heap
	numItems++;
    data[numItems-1] = item;
    swap_up(numItems-1);
}

int max_heap::parent(int i){
    if(i%2 == 0)
        return ((i - 2)/2);
    else
        return ((i - 1)/2);
}

void max_heap::swap_up(int i) {
    while (data[parent(i)].freq < data[i].freq) {
        swap(data[i], data[parent(i)]);
        i = parent(i);
    }
}

void max_heap::heapify(int* heap, int size) {
    for (int i = (size - 2) / 2; i >= 0; i--)
        swapDown(i);
}

void max_heap::sort(int* heap, int size) {
    heapify(heap, size);
    for (int i = size - 1; i > 0; i--) {
        swap(heap[0], heap[i]);
        swapDown(i);
    }
}
