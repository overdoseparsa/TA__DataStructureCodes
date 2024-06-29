
//mohamad khakiy link list
#include <iostream>
using namespace std;
template < typename input_type > 
class Node { 
public: 
    input_type data; 
    Node* next;
    Node* previous; 
    Node(input_type value){ 
        this->data = value; 
        this->next = nullptr; 
        this->previous = nullptr;
    } 
};  
template < typename input_type > 
// we are create here None class with constreactor 


class link_list{
    private:
        Node<input_type>* head;
    public:
        int size = 0;
        link_list(){
            head = nullptr;
        }
        
        bool is_emptyer(){
            return (head == nullptr || size == 0);
        }
       
        void append_fronter(input_type value){        
            
            Node<input_type>* newNode = new Node<input_type>(value);
            if(is_emptyer()){
                head = newNode;
            }else{
                Node<input_type>* temp = head; 
                while (temp->next != nullptr) { 
                    temp = temp->next; 
                }  
                temp->next = newNode; 
                newNode->previous = temp;
            }
            size++;     
        } 
        
        void append_rear(input_type value){       
           
            Node<input_type>* newNode = new Node<input_type>(value);
            if(is_emptyer()){
                head = newNode;
            }else{
                newNode->next = head;
                head->previous = newNode;
                head = newNode;
            }
            size++;     
        }   
       
        void append_between(input_type data1, input_type data2, input_type value){
            if(!is_emptyer()){
                Node<input_type>* temp = head; 
                bool flag1 = false;
                bool flag2 = false;
                while( temp->next != nullptr ){
                    if( temp->data == data1 ){
                        flag1 = true;
                        temp = temp->next;
                        if( temp->data == data2 ){
                            flag2 = true;
                            break;
                        }
                        break;
                    }
                    temp = temp->next;
                }
                if( flag1 == true && flag2 == true ){
                    
                    Node<input_type>* newNode = new Node<input_type>(value);  
                    Node<input_type>* temp_before = temp->previous; 
                    temp = temp_before->next;
                    //------------------------------
                    temp->previous = newNode;
                    temp_before->next = newNode;
                    newNode->next = temp;
                    newNode->previous = temp_before;
                }else{
                    
                }
                size++;    
            }
        }
        void replace(input_type find, input_type replace){
        
            if(!is_emptyer()){
                Node<input_type>* temp = head; 
                while(temp->data != find)
                    temp = temp->next;
                temp->data = replace;
            }else{
               
            }
        }
        
        int count(){
          
            if(!is_emptyer()){
                return size;
            }else{
                return -1;
            }
        }
        
        
        
        void reverse(){
            if(!is_emptyer()){
                Node<input_type>* first = head; 
                Node<input_type>* last = head; 
                input_type data_temp;
                while(last->next != nullptr)
                    last = last->next;
                while((first != last) && (first->previous != last) && (last->next != first)){
                    data_temp = first->data;
                    first->data = last->data;
                    last->data = data_temp;
                    first = first->next;
                    last = last->previous;
                }
            }else{
               //Do nothing because link list is empty 
            }
        }
       

        
        
        void delete_index(int index){
            Node<input_type>* temp = head;
            if(!is_emptyer() && index < this->size){
                while(index > 0){
                    temp = temp->next;
                    index--;
                }
                if(temp->previous != nullptr){
                    temp->previous->next = temp->next;
                }else{
                    head = temp->next;
                }
                if(temp->next != nullptr){
                    temp->next->previous = temp->previous;
                }
                delete temp;
                this->size--;
                }
            }
        
        
        void delete_value(input_type value){
            Node<input_type>* temp = head;
            bool flag = false;
            if(!is_emptyer()){
                while(temp->data != value && temp != nullptr){
                    if (temp->next == nullptr){
                        cout<<value<<" doesn`t find in link list\n";
                        flag = true;
                        break;
                    }
                    temp = temp->next;
                }
                if(temp != nullptr && flag == false){
                    if(temp->previous != nullptr){
                        temp->previous->next = temp->next;
                    }else{
                        head = temp->next;
                    }
                    if(temp->next != nullptr){
                        temp->next->previous = temp->previous;
                    }
                    delete temp;
                    this->size--;
                }
            }

        }

        int find_value__index(input_type value){
            int index = 0 ;
            Node<input_type>* temp = head;
            if(!is_emptyer()){ 
                while(temp->data != value){
                    index++;
                    temp = temp->next;
                    if(index >= size){
                        return -1;
                    }
                }
                return index;
            }else{
                return -1;
            }
        }
        
        input_type f(int index){
            Node<input_type>* temp = head; 
            if(!is_emptyer() && index <= size){
                for(int i = 0 ; i != index ; i++){
                    temp = temp->next;
                }
                return temp->data;
            }else{
                cout<<"index "<<index<<" is out of range";
                return input_type();
            }
        }
        input_type max_value(){
            if(!is_emptyer()){
                Node<input_type>* temp = head; 
                input_type max = temp->data;
                while(temp != nullptr){
                    if(temp->data > max){
                        max = temp->data;
                    }
                    temp = temp->next;
                }
                return max;
            }else{
                return input_type();
            }
        }
        
        void deleteer(input_type key){
            Node<input_type>* temp1 = head; 
            if(temp1 == nullptr || temp1->next == nullptr)  return;
            while(temp1 != nullptr && temp1->data != key){
                temp1 = temp1->next;
            }
            if(temp1 == nullptr)    return;
            Node<input_type>* temp2 = temp1->next;
            while(temp2 != nullptr){
                if(key == temp2->data){
                    temp2->previous->next = temp2->next;
                    if(temp2->next != nullptr){
                        temp2->next->previous = temp2->previous;
                    }
                    Node<input_type>* temp3 = temp2->next;
                    delete temp2;
                    this->size--;//reduce size one time
                    temp2 = temp3;
                }else{
                    temp2 = temp2->next;
                }
            } 
        }
        

       
        input_type min_value(){//return minimum value of link list
            if(!is_emptyer()){
                Node<input_type>* temp = head; 
                input_type min = temp->data;//give value of first node to min
                while(temp != nullptr){
                    if(temp->data < min){
                        min = temp->data;
                    }
                    temp = temp->next;
                }
                return min;
            }else{
                return input_type();
            }
        }
        void show_values(){
            if(!is_emptyer()){
                Node<input_type>* temp = head; 
                for (int i = 0 ; temp != nullptr ; i++){
                    cout<<temp->data<<", ";
                    temp = temp->next;
                }
                cout<<'\n';
            }
        }
        
        input_type sum(){//return summation of all values
            if(!is_emptyer()){
                Node<input_type>* temp = head; 
                input_type sum = input_type();
                while(temp != nullptr){
                    sum += temp->data;
                    temp = temp->next;
                }
                return sum;
            }else{
                return input_type();
            }
        }
       

        input_type pop_last(){
       
            if(!is_emptyer()){
                Node<input_type>* temp = head; 
                for (int i = 0 ; temp->next != nullptr ; i++){
                    temp = temp->next;
                }
                input_type value = temp->data;
                if(temp->previous != nullptr){
                    temp->previous->next = nullptr;
                }
                delete temp;
                size--;
                return value;
            }else{
                return input_type();
            }
        }



        input_type pop_firster(){
      
            if(!is_emptyer()){
                input_type value = head->data;
                if(head->next != nullptr){
                    head = head->next;
                }
                delete head->previous;
                head->previous = nullptr;
                size--;
                return value;
            }else{
                return input_type();
            }
        }

       
};
int main(){
    link_list<int> a;
    a.append_fronter(45454);
    
    a.append_fronter(5645);
    a.append_fronter(45645);
    a.append_rear(-5656);

    a.show_values();
    a.delete_value(5645);
    a.show_values();
    
    
    cout<<a.find_value__index(365422)<<'\n';
    a.show_values();
    a.deleteer(45454);
    cout<<a.pop_firster()<<'\n';

    return 0;
}
