#include<iostream>
#include<stdexcept>
#include"stack_c.h"

using namespace std;

Stack_C :: Stack_C(){
    // try{
   stk= new List();
 
}
Stack_C ::~Stack_C(){
    delete stk;

}
void Stack_C ::push(int data){
    
    return stk->insert(data);
}

int Stack_C ::pop(){
    if(stk->get_size()==0){
        throw std::runtime_error("Empty Stack");
        // return -1;
    }
    return stk->delete_tail();


}

int Stack_C :: get_element_from_top(int idx){
    
    if(idx>=stk->get_size() || idx<0){
        throw std::runtime_error("Index out of range"); 
        // return -1;
    }
        else{
            int sizex=stk->get_size();
            int sizey=sizex-idx-1;
        
            Node* temp=stk->get_head()->next;
            for(int j=0;j<sizey;++j){
              temp=temp->next;
            }
            return temp->get_value();
        }
    }
    



int Stack_C :: get_element_from_bottom(int idx){
    if(idx>=stk->get_size() || idx<0){
        throw std::runtime_error("Index out of range"); 
        // return -1;
    }
        else{
            Node* temp=stk->get_head()->next;
            for(int j=0;j<idx;++j){
              temp=temp->next;
            }
            return temp->get_value();
        }

 }
void Stack_C :: print_stack(bool top_or_bottom){
    Node* temp = stk->get_head()->next;
  if (top_or_bottom==false){
    for(;temp!=nullptr;temp=temp->next){
        cout<<temp->get_value()<<endl;
       

    }
    
   
  }
else{
   int sizex=stk->get_size();
  for(int i=0;i<sizex;i++){
    temp=temp->next;
  }
    Node* now=temp;
         
          for(int i=sizex;i>0;i--){
            cout<<now->get_value()<<endl;
          now=now->prev;
          }
}
          cout<<endl;
  
}
  int Stack_C :: add(){
    if(stk->get_size()>1){

   int a=pop();
   int b=pop();
   int c=a+b;
   push(c);
   return c;
    }
    else{
         throw std::runtime_error( "Not Enough Arguments");
        //  return -1;
    }


    


  }
  int Stack_C :: subtract(){
    if(stk->get_size()>1){

    int a=pop();
   int b=pop();
   int c= b-a;
   push(c);
   return c;


  }
  else{
         throw std::runtime_error( "Not Enough Arguments");
        //  return -1;
    
    }
  }
  int Stack_C :: multiply(){
    if(stk->get_size()>=2){

   int a=pop();
   int b=pop();
   int c=a*b;
   push(c);
   return c;


  }
  else{
         throw std::runtime_error( "Not Enough Arguments");
        //  return -1;
    
    }
  }
  int Stack_C :: divide(){
    if(stk->get_size()>=2){


   int a=pop();
   int b=pop();
   if(a!=0){
  int i= b /a;
  int d;

   if(i==0 && b>=0 && a>0 ||i==0 && b<=0 && a<0){
         d=0;
      }
      else if(i<0 && (b % a)!=0){
        d=i-1;
      }
     
      else if(i==0 && b>0 && a<0 || i==0 && b<0 && a>0 ){
         d=i-1;
        
      }
      else{
         d=i;
      }

   push(d);
   return d;

   }
   else{
    throw std::runtime_error("Divide by Zero Error");


   }
    }
    else{
         throw std::runtime_error( "Not Enough Arguments");
    
    
    }

  }
  List* Stack_C :: get_stack(){
    return stk;

  }
  int Stack_C :: get_size(){
    return stk->get_size();
    

  }
  
  
