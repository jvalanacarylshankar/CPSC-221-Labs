/*--- LQueue.cpp ----------------------------------------------------------
  This file implements LQueue member functions.
  From:  "ADTs, Data Structures, and Problem Solving with C++", 2nd edition
         by Larry Nyhoff
-------------------------------------------------------------------------*/
 
#include <iostream>
using namespace std;

#include "LQueue.h"

//--- Definition of Queue constructor
Queue::Queue()
: myFront(0), myBack(0)
{}

//--- Definition of Queue copy constructor
Queue::Queue(const Queue & original)
{
   myFront = myBack = 0;
   if (!original.empty())
   {
      // Copy first node
      myFront = myBack = new Queue::Node(original.front());

      // Set pointer to run through original's linked list
      Queue::NodePointer origPtr = original.myFront->next;
      while (origPtr != 0)
      {
         myBack->next = new Queue::Node(origPtr->data);
         myBack = myBack->next;
         origPtr = origPtr->next;
      }
   }
}

//--- Definition of Queue destructor
Queue::~Queue()
{ 
  // Set pointer to run through the queue
  Queue::NodePointer prev = myFront,
                     ptr;
  while (prev != 0)
    {
      ptr = prev->next;
      delete prev;
      prev = ptr;
    }
}

//--- Definition of assignment operator
const Queue & Queue::operator=(const Queue & rightHandSide)
{
   if (this != &rightHandSide)         // check that not q = q
   {
      this->~Queue();                  // destroy current linked list
      if (rightHandSide.empty())       // empty queue
         myFront = myBack = 0;
      else
      {                                // copy rightHandSide's list
         // Copy first node
         myFront = myBack = new Queue::Node(rightHandSide.front());

         // Set pointer to run through rightHandSide's linked list
         Queue::NodePointer rhsPtr = rightHandSide.myFront->next;
         while (rhsPtr != 0)
         {
           myBack->next = new Queue::Node(rhsPtr->data);
           myBack = myBack->next;
           rhsPtr = rhsPtr->next;
         }
      }
   }
   return *this;
}

//--- Definition of empty()
bool Queue::empty() const
{ 
   return (myFront == 0); 
}

//--- Definition of enqueue()
void Queue::enqueue(const QueueElement & value)
{
   Queue::NodePointer newptr = new Queue::Node(value);
   if (empty())
      myFront = myBack = newptr;
   else
   {
      myBack->next = newptr;
      myBack = newptr;
   }
}

//--- Definition of display()
void Queue::display(ostream & out) const
{
   Queue::NodePointer ptr;
   for (ptr = myFront; ptr != 0; ptr = ptr->next)
     out << ptr->data << "  ";
   out << endl;
}

//--- Definition of front()
QueueElement Queue::front() const
{
   if (!empty())
      return (myFront->data);
   else
   {
	return 0;
   }
}

//--- Definition of dequeue()
void Queue::dequeue()
{
   if (!empty())
   {
      Queue::NodePointer ptr = myFront;
      myFront = myFront->next;
      delete ptr;
      if (myFront == 0)     // queue is now empty
         myBack = 0;
   }   
   else
      cerr << "*** Queue is empty -- can't remove a value ***\n";
}

//--- Definition of move_to_front()
void Queue::move_to_front(QueueElement val)
{
   Queue::NodePointer prev = myFront;
   Queue::NodePointer curr = myFront->next;
   while(curr)
   {
      if(curr->data == val)
         {
            Queue::NodePointer temp = curr;
            prev->next = curr->next;
            temp->next = myFront;
            myFront = temp;
            return;
         }
      curr = curr->next;
      prev = prev->next;
   }
   
}

//-- Definition of getMyFrontVal()
int Queue::getMyFrontVal()
{
   int val = (int) myFront->data;
   return val;
}


//-- Definition of length()
int Queue::length()
{
   Node* temp = myFront;
   int size = 0;
   while(temp)
   {
      size++;
      temp = temp->next;
   }
   return size;
}

//--- Definition of merge_two_queues()
void Queue::merge_two_queues(Queue & q2)
{
  //Node* temp1 = this;
  
  if((empty() && q2.empty()) || q2.empty())
    return;
  
  if(empty())
   {
      Node* temp = q2.myFront;
      enqueue(temp->data);
      temp = temp->next;
      while(temp)
      {
          enqueue(temp->data);
          temp = temp->next;
      }
     
      while(q2.myFront)
        q2.dequeue();
        
      return;
    }
    
   Queue q3;
   int l1 = length();
   int l2 = q2.length();
   
   int i1 = 0;
   int i2 = 0;

   Node* temp1 = myFront;
   Node* temp2 = q2.myFront;


   while(i1 < l1 && i2 < l2)
   {
       if(temp1->data < temp2->data)
       {
          q3.enqueue(temp1->data);
          i1++;
          temp1 = temp1->next;
       }
       else
       {
          q3.enqueue(temp2->data);
          i2++;
          temp2 = temp2->next;
       }
   }

   while(i1 < l1)
   {
       q3.enqueue(temp1->data);
       i1++;
       temp1 = temp1->next;
   }

   while(i2 < l2)
   {
       q3.enqueue(temp2->data);
       i2++;
       temp2 = temp2->next;
   }

   while(q2.myFront)
      q2.dequeue();

   while(myFront)
      dequeue();

   
   while(q3.myFront)
   {
      Node* temp = q3.myFront;
      enqueue(temp->data);
      temp = temp->next;
      while(temp)
      {
          enqueue(temp->data);
          temp = temp->next;
      }
      
      while(q3.myFront)
        q3.dequeue();
        
      return;
   }
   
}