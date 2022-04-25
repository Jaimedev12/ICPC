// UVa 11988. Broken Keyboard

#include <iostream>

using namespace std;

string s;

class Node {
public:
    char Character;
    Node* Next;
};

void insertAtTheFront(Node** head, char newChar){
    // Preparar nuevo Nodo
    Node* newNode = new Node();
    newNode->Character = newChar; 
    // Ponerlo en frente de la cabeza
    newNode->Next = *head;
    // Cambiar el valor de la cabeza
    *head = newNode;
}

void insertAtTheBack(Node** head, char newChar){
    
    // Prepara nuevo Nodo
    Node* newNode = new Node();
    newNode->Character = newChar;
    newNode->Next = NULL;
    // Si la lista está vacía, esta será la cabeza
    if (*head == NULL){
        *head ==  newNode;
        return;
    }
    // Encontrar último elemento
    Node* last = *head;
    while(last->Next != NULL){
        last = last->Next;
    }
    // Agregar el puntero al último elemento
    last->Next = newNode;
}

void printList(Node* node){
    
    while(node != NULL){
        cout << node->Character;
        node = node->Next;
    }
    
}

int main()
{
    cin >> s;
    
    Node* head = new Node();
    
    for (int i = 0; i < s.length(); i++){
        insertAtTheBack(&head, s[i]);
    }
    
    printList(head);
    
    return 0;
}

// This_is_a_[Beiju]_text
