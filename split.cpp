/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
 /* Add code here */
 //base case, when all elements of in have been split, return
 if(in == nullptr){
   return;
 }
 //if element is even
 if(in->value % 2 == 0){
   //if evens is empty, set evens to temp (aka in), advance in pointer
   //and set evens next to null so that evens doesn't point to rest of in
   //then recursive call to take care of next element
   if(evens == nullptr){
     Node* temp = in;
     evens = temp;
     in = in->next;
     evens->next = nullptr;
     split(in, odds, evens);
   }
   //if evens not empty, set evens->next to in, advance in, and set the 
   //newly added elements next poiner to null so evens don't point to rest of in
   //then recursive call using next evens node so don't go over previous one
   else{
     evens->next = in;
     in = in->next;
     evens->next->next = nullptr;
     split(in, odds, evens->next);
   }
 }
 //else if odd
 else if(in->value % 1 == 0){
   //if odds empty, set odds to temp (aka in), advance in pointer
   //and set odds next to null so that evens doesn't point to rest of in
   //then recursive call to take care of next element
   if(odds == nullptr){
     Node *temp = in;
     odds = temp;
     in = in->next;
     odds->next = nullptr;
     split(in, odds, evens);
   }
   //if odds not empty, set odds->next to in (aka add in node to odds), 
   //advance in, and set the newly added elements next poiner to null so 
   //evens don't point to rest of in then recursive call using next odds 
   //node so don't go over previous one
   else{
     odds->next = in;
     in = in->next;
     odds->next->next = nullptr;
     split(in, odds->next, evens);
   }
 }
}


/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE