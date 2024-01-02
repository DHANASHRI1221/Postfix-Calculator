#include<iostream>
#include<stdexcept>

#include"stack_a.h"
using namespace std;

Stack_A ::Stack_A(){
   
    size=0;
}
 

   

void Stack_A ::push(int data){
    if(  size < 1024){
      stk[size]=data;
       size=size+1;

   
    }
    else{
    throw std::runtime_error("Stack Full");
    
    }

    }
   int Stack_A ::pop(){
    if (size<1){
     throw std::runtime_error("Empty Stack");
     
    //  return -1;
    }
    else{
      size=size-1;
      return stk[size]; 
    }
   
    }
int Stack_A :: get_element_from_top(int idx){


    int s=size-1-idx;
    if(s>-1 && s<size){
     return stk[s];    
    }
    else{
    throw std::runtime_error("Index out of range");
    }
  
  
}
int Stack_A ::get_element_from_bottom(int idx){
    if(idx>-1){
    return stk[idx];
    }
    else{
    throw std::runtime_error("Index out of range");
    }

}
 void  Stack_A ::print_stack(bool top_or_bottom){
    if(top_or_bottom==true){
     for(int i=size-1;i>-1;i--){
        cout<<stk[i]<<endl;
     }
    }
    else{
      for(int i=0;i<(size);i++){
        cout<<stk[i]<<endl;
    }
    }
    }
 
 
 int  Stack_A :: add(){
    if(size>=2){
    int x= stk[size-1]+stk[size-2];
    pop();
    pop();
  
    push(x);
    return stk[size-1];
    }
    else{
      throw std::runtime_error( "Not Enough Arguments");
      // return -1;
    }

 }
 
 int  Stack_A ::subtract(){
    if(size>=2 ){
    int x= stk[size-2]-stk[size-1];
    pop();
    pop();
    push(x);
    return stk[size-1];
    }
    else{
      throw std::runtime_error( "Not Enough Arguments");
      // return -1;
    }

 }
 int  Stack_A :: multiply(){
  if(size>=2){
    int x= stk[size-2]*stk[size-1];
    pop();
    pop();
    push(x);
    return stk[size-1];
    }
    else{
      throw std::runtime_error( "Not Enough Arguments");
      // return -1;
    }  

 }

 int Stack_A ::divide(){
  if (size>=2){
   int top=stk[size-1];
    if(top!=0){
      int x=stk[size-2];

      int i= x/top;
      int d;
      if(i==0 && x>=0 && top>0 ||i==0 && x<=0 && top<0){
         d=0;
      }
      else if(i<0 && (x % top)!=0){
        d=i-1;
      }
     
      else if(i==0 && x>0 && top<0 || i==0 && x<0 && top>0 ){
         d=i-1;
        
      }
      else{
         d=i;
      }
     pop();
     pop();
     push(d);
     return d;
    }else{
      throw std::runtime_error("Divide by Zero Error");
    }
  }
    else{
      throw std::runtime_error("Not Enough Arguments");
    }
  }

 
 int* Stack_A :: get_stack(){
  int* ptr= stk;
  return ptr;
 }
 int  Stack_A ::get_size(){
   
    return size;
 }
 
