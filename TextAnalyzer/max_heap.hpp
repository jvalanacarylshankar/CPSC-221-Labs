/*-- max_heap.h -------------------------------------------------------------

  This header file defines a Max Heap data type.
  Basic operations:
    empty:        Checks if a heap is empty
    insert:       Modifies a heap by adding a value at valid location
    deleteMax:    Modifies tree by removing the value with maximum priority
	size:         Produces the number of items currently in a heap
---------------------------------------------------------------------------*/
#pragma once
#include <vector>
#include "text_item.h"

class max_heap
{
 private:
  /***** Data Members *****/
  text_item *data;
  int numItems;

  void swap_down(int i);
  void swap_up(int i);

 public:
  /***** Function Members *****/

  /***** Constructors *****/
  /*-----------------------------------------------------------------------
    Construct a heap object, with an underlying array of size n

    Precondition:  None.
    Postcondition: An empty heap object has been constructed.
  -----------------------------------------------------------------------*/
  max_heap(int n);

  /***** Destructor *****/
  /*-----------------------------------------------------------------------
    Class destructor

    Precondition:  None.
    Postcondition: The items in the data array have been deallocated
  -----------------------------------------------------------------------*/
  ~max_heap();

  /*-----------------------------------------------------------------------
    Check if heap is empty.

    Precondition:  None.
    Postcondition: Returns true if heap is empty and false otherwise.
  -----------------------------------------------------------------------*/
  bool empty() const;

  /*-----------------------------------------------------------------------
    Returns the number of elements currently in a heap.

    Precondition:  Heap is nonempty.
    Postcondition: Heap has not been modified, number of unique elements
    in Heap has been returned.
  -----------------------------------------------------------------------*/
  int size() const;

  /*-----------------------------------------------------------------------
    Returns a reference to the top of the heap.

    Precondition:  Heap is nonempty.
    Postcondition: Heap has not been modified, a reference to the
	top of the Heap is returned.
  -----------------------------------------------------------------------*/
  text_item& top();

    /*-----------------------------------------------------------------------
    Removes the item with the highest key from the heap.

    Precondition:  None.
    Postcondition: The item with the maximum key value has been removed.
	From the remaining items, the item with the maximum key is now at
	the top of the heap.
  -----------------------------------------------------------------------*/
  text_item delete_max();

  /*-----------------------------------------------------------------------
    Add an item to the heap, and makes sure the order invariant is
	not violated for any parent-child pair.

    Precondition:  w is to be added to the heap
    Postcondition: w is added and heap invariant holds
  -----------------------------------------------------------------------*/
    void insert(text_item const& item);

    void heapify(int* heap, int size);
    void sort(int* heap, int size)

}; // end of class declaration
