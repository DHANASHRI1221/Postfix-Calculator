#include<iostream>
#include<stdexcept>

#include"stack_b.h"
using namespace std;

// #define C 2
Stack_B ::Stack_B() {
   size=0;
   capacity=1024;
   stk=new int[capacity];
   

    
}
Stack_B ::~Stack_B(){
   delete[] stk;
   
}

   

// void Stack_B ::push(int data){
//   try{
//     if(size>=capacity){
//       int capacity2=capacity*2; 
//       int*temp = new int[capacity2];
//       for(int i=0;i<size;i++){
//          temp[i]=stk[i];
//          }
//        delete[] stk;
//        stk=temp;
//        capacity=capacity2;
       
//     }
  
       
         
//           size=size+1;
//           stk[size-1]=data;
        
     
       
//   }
    
    
//        catch (const bad_alloc& e){
//         throw  std::runtime_error("Out Of Memory");
//        }
    
// }

void Stack_B ::push(int data){
 
    if(size>=capacity){
      int capacity2=capacity*2; 
      int*temp = new(std::nothrow) int[capacity2];
     if(temp){
        for(int i=0;i<size;i++){
         temp[i]=stk[i];
         }
        delete[] stk;
       stk=temp;
       capacity=capacity2;
       
    }
    else{
      throw std::runtime_error("Out Of Memory");
    }
    }
        stk[size]=data;
         size=size+1;
        
  }

    
int Stack_B ::pop(){
     if (size == 0){
     throw std::runtime_error("Empty Stack");
     }
    int result=stk[size-1];
        size=size-1;
      if((capacity/4)>1024){
        if(size<(capacity/4)){
      int capacity2=(capacity/2);
      int *temp= new int[capacity2];
      for(int i=0;i<size;i++){
         temp[i]=stk[i];
         
      }
       delete[] stk;
         stk=temp;
         capacity=capacity2;
    }
        }
   
      return result; 
    
   
    }
int Stack_B :: get_element_from_top(int idx){
    int s=size-1-idx;
    if(s>-1 && idx<size){
     return stk[s];    
    }
    else{
    throw std::runtime_error("Index out of range");
    }
}
int Stack_B ::get_element_from_bottom(int idx){
    if(idx>-1){
    return stk[idx];
    }
    else{
    throw std::runtime_error("Index out of range");
    }

}
 void  Stack_B ::print_stack(bool top_or_bottom){
    // if (size==0){
    //      throw std::runtime_error("Index out of range");
    // }
    // else{
    if(top_or_bottom==true){
     for(int i=(size-1);i>-1;i--){
        cout<<stk[i]<<endl;
     }
    }
    else{
      for(int i=0;i<(size);i++){
        cout<<stk[i]<<endl;
    }
    }
    }
 
 
 int  Stack_B :: add(){
    
        
    if(size>=2){
    int x= stk[size-1]+stk[size-2];
    pop();
    pop();
    push(x);
    return stk[size-1];
    }
    else{
      throw std::runtime_error( "Not Enough Arguments");
    }

 }
 
 
int  Stack_B ::subtract(){
    if(size>=2){
    int x= stk[size-2]-stk[size-1];
    pop();
   pop();
    push(x);
     return stk[size-1];
    }
    else{
      throw std::runtime_error( "Not Enough Arguments");
    }

 }
int  Stack_B :: multiply(){
  if(size>=2){
    int x= stk[size-2]*stk[size-1];
    pop();
    pop();
    push(x);
     return stk[size-1];
    }
    else{
      throw std::runtime_error( "Not Enough Arguments");
    }  

 }
 
 int Stack_B ::divide(){
  if (size>=2){
   int top=stk[size-1];
   if(top==0){
    throw std::runtime_error("Divide by Zero Error");
   }
   else{
      int x=stk[size-2];
      int i= x/top;
      int d;
      // if(i<=0 && (x % top)!=0){
      //    i=i-1;
      // }
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
    
  }
  }
    else{
      throw std::runtime_error("Not Enough Arguments");
    }
  }

 
 int* Stack_B :: get_stack(){
  int* pointer=stk;
  return pointer;
 }
 int  Stack_B ::get_size(){
    // int s = counter +1;
    // if(size!=0){
    return size;
    // }
    // else{
    //   throw std::runtime_error("Empty Stack");  
    // }

 }
 