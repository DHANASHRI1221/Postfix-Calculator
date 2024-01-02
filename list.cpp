#include<iostream>
#include<stdexcept>
#include"list.h"

using namespace std;

//  List:: List(){
//    size=0;
   
//  try{
//  sentinel_head= new Node(true);
//  sentinel_tail= new Node(true);
 
 
//  sentinel_head->next=sentinel_tail;
//  sentinel_tail->prev=sentinel_head;
//  }
//   catch (const bad_alloc& e){
//         throw  std::runtime_error("Out Of Memory");
//        }
//  }
List:: List(){
   size=0;
//  try{
 sentinel_head= new(nothrow) Node(true);
 sentinel_tail= new(nothrow) Node(true);
 if(!sentinel_head || !sentinel_tail){
  delete sentinel_head;
        delete sentinel_tail;
        throw std::runtime_error("Out Of Memory");
 }
 
 sentinel_head->next=sentinel_tail;
 sentinel_tail->prev=sentinel_head;
}

 List:: ~List(){
   Node* temp = sentinel_head->next;
   
   while(temp!=sentinel_tail){
      Node* d=temp;
   temp=temp->next;
   delete d;
   }
   delete sentinel_head;
   delete sentinel_tail;


  

 }
 
//  void List::insert(int v){
//    try{
//    Node* n= new Node(v,nullptr,nullptr);
//    n->prev=sentinel_tail->prev;
//    n->next=sentinel_tail;
//    sentinel_tail->prev->next=n;
//    sentinel_tail->prev=n;
//   size=size+1;
//    }
//    catch (const bad_alloc& e){
//         throw  std::runtime_error("Out Of Memory");
//        }
   
   
  
//  }
void List::insert(int v) {
    // try {
        Node* n = new (nothrow) Node(v, nullptr, nullptr);
        if (!n) {
            throw runtime_error("Out Of Memory");
        }

        n->prev = sentinel_tail->prev;
        n->next = sentinel_tail;
        sentinel_tail->prev->next = n;
        sentinel_tail->prev = n;
        size = size + 1;
    // } catch (const bad_alloc& e) {
    //     throw runtime_error("Memory allocation failed");
    // }
}
Node* List:: get_head(){
  Node* pointer= sentinel_head;
  return sentinel_head;

   }


int List:: delete_tail(){
   
  Node* temp= sentinel_tail->prev;
  int data= temp->get_value(); 
  sentinel_tail->prev=temp->prev;
  temp->prev->next=sentinel_tail;
  delete temp;


 size=size-1;
 return data;
  }
int List:: get_size(){
   return size;

   }

