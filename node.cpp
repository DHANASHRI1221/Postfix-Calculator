#include<iostream>
#include<stdexcept>
#include"node.h"
using namespace std;
Node :: Node(bool sentinel){
   
    prev=nullptr;
    next=nullptr;
    // value=0;
    is_sentinel=sentinel;

}
Node ::  Node(int v, Node* nxt=nullptr, Node* prv=nullptr) {
  value=v;
  next=nxt;
  prev=prv;

}
bool Node ::  is_sentinel_node(){
// if(  sentinel== true){
//  return true;
// }
// else{
//     return false;
// }
return is_sentinel;

}
int Node :: get_value(){

    return value;
}
