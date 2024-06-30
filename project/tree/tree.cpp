#include <iostream>
#include <string>
// mohamad khaki 4011406507 
using namespace std;
template < typename input_type > 
class General_Tree_Nodes { 
    public:
        input_type data = input_type(); 
        General_Tree_Nodes<input_type>* father = nullptr;
        General_Tree_Nodes<input_type>* childs = nullptr;
        General_Tree_Nodes<input_type>* right_sibling = nullptr;
        General_Tree_Nodes<input_type>* left_sibling = nullptr;
        General_Tree_Nodes(input_type value){ 
            this->data = value; 
            add_child(data);
        }
        void add_child(input_type value){ 
            int check = 0;
            input_type* array;
            do{
                cout<<"Those "<<value<<" has any childs? \nenter 1 for true or 0 for false: ";
                cin>>check;
            }while(check != 0 && check != 1);
            int num1 = 0 ;
            if(check){
                cout<<"How many kids those "<<value<<" have? ";
                cin>>num1;
                array = new input_type[num1];
                cout<<"-----------------------------------------------------\n";
                for (int j = 0 ; j < num1 ; j++){
                    string num = number_word(j+1);
                    cout<<"Enter value of "<<j+1<<" child of "<<value<<": ";
                    cin>>array[j];    
                }
            }else{
                num1 = 0 ;
            }
            cout<<"-----------------------------------------------------\n";
            for(int i = 0 ; i < num1 ; i++){
                cout<<array[i]<<" is child of "<<this->data<<".\n";
                General_Tree_Nodes<input_type>* new_child = new General_Tree_Nodes<input_type>(array[i]);
                new_child->father = this;
                if(i == 0){
                    childs = new_child;
                }else{
                    General_Tree_Nodes<input_type>* temp = childs; 
                    while(temp->right_sibling != nullptr){
                        temp = temp->right_sibling;
                    }
                    new_child->left_sibling = temp;
                    temp->right_sibling = new_child;
                }
            }
        }
}; 
template < typename input_type > 
class Binary_Tree_Nodes{
    public:
        input_type data = input_type();
        Binary_Tree_Nodes<input_type>* parent = nullptr;
        Binary_Tree_Nodes<input_type>* left_child = nullptr;
        Binary_Tree_Nodes<input_type>* right_child = nullptr;
        Binary_Tree_Nodes(input_type value){
            this->data = value;
        }
};
template < typename input_type > 
class Result {
    public:
        Binary_Tree_Nodes<input_type>* Binary_head = nullptr;
        General_Tree_Nodes<input_type>* General_head = nullptr;
        General_Tree_Nodes<input_type>* General_temp = nullptr;
        Result(input_type value){
            General_head = new General_Tree_Nodes<input_type>(value);
            General_temp = new General_Tree_Nodes<input_type>(*General_head);
            General_to_binary(General_temp, Binary_head);
        }
        void General_to_binary(General_Tree_Nodes<input_type>* head, Binary_Tree_Nodes<input_type>* Binary_temp){
            if(head->childs == nullptr)     return; 
            if(Binary_temp == nullptr){
                Binary_head = new Binary_Tree_Nodes(head->data);
                General_to_binary(head, Binary_head);
            }else{
                if(Binary_temp->left_child == nullptr){
                    Binary_Tree_Nodes<input_type>* add = new Binary_Tree_Nodes(head->childs->data);
                    add->parent = Binary_temp;
                    Binary_temp->left_child = add;
                    General_to_binary(head->childs, Binary_temp->left_child);
                    head->childs = head->childs->right_sibling;
                    General_to_binary(head, Binary_temp);
                }else{
                    Binary_temp = Binary_temp->left_child;
                    while(head->childs != nullptr){
                        Binary_Tree_Nodes<input_type>* add = new Binary_Tree_Nodes(head->childs->data);
                        add->parent = Binary_temp;
                        Binary_temp->right_child = add;
                        General_to_binary(head->childs, Binary_temp->right_child);
                        Binary_temp = Binary_temp->right_child;
                        head->childs = head->childs->right_sibling;
                    }
                }
            }
        }
};
int main(){
    Result<int> tree(10);
    cout<<"binary tree of your tree has been make you can see it in debug terminal";
    return 0;
}

