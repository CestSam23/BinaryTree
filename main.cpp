#include <iostream>
#include "BinaryTree.h"
using namespace std;

int menu(){
    int option;
    cout << "\n\n- - - - - - - - - - - - - - - - M E N U - - - - - - - - - - - - - - - - - -"<<endl;
    cout<< "[1]. Ingresar datos." << endl;
    cout<< "[2]. Mostrar arbol." << endl;
    cout<< "[3]. Buscar padres." << endl;
    cout<< "[4]. Buscar hijos." << endl;
    cout<< "[5]. Buscar hermanos." << endl;
    cout<< "[6]. Mostrar niveles." << endl;
    cout<< "[7]. Mostrar peso." << endl;
    cout<< "[8]  Mostrar grado." << endl;
    cout<< "[0]. Salir." ;
    cout<< "\nDigite una opcion: " ;
    cin>>option;
    return option;
}

void insert(BinaryTree<int> *tree);
string showTree(BinaryTree<int> *tree);
int parent(BinaryTree<int> *tree);
string children(BinaryTree<int> *tree);
string silbings(BinaryTree<int> *tree);
int levels(BinaryTree<int> *tree);
int weight(BinaryTree<int> *tree);
int degree(BinaryTree<int> *tree);

int main() {
    BinaryTree<int> *tree = new BinaryTree<int>;
   int choice;
    while((choice=menu())!=0){
        switch (choice) {
            case 1:
                cout << "- - - - - - - - - - - - - - - - I N G R E S A R  N O D O - - - - - - - - - - - - - - - - \n";
                insert(tree);
                break;

            case 2:
                cout << "- - - - - - - - - - - - - - - - M O S T R A R  A R B O L - - - - - - - - - - - - - - - - \n";
                cout << showTree(tree) << endl;
                break;

            case 3:
                cout << "- - - - - - - - - - - - - - - - M O S T R A R  P A D R E - - - - - - - - - - - - - - - - \n";
                cout << parent(tree);
                break;

            case 4:
                cout << "- - - - - - - - - - - - - - - - M O S T R A R  H I J O S - - - - - - - - - - - - - - - - \n";
                cout << children(tree);
                break;

            case 5:
                cout << "- - - - - - - - - - - - - - - - M O S T R A R  H E R M A N O - - - - - - - - - - - - - - - - \n";
                cout << silbings(tree);
                break;

            case 6:
                cout << "- - - - - - - - - - - - - - - - M O S T R A R  N I V E L - - - - - - - - - - - - - - - - \n";
                cout << levels(tree);
                break;

            case 7:
                cout << "- - - - - - - - - - - - - - - - M O S T R A R  P E S O - - - - - - - - - - - - - - - - \n";
                cout << weight(tree);
                break;

            case 8:
                cout << "- - - - - - - - - - - - - - - - M O S T R A R  G R A D O - - - - - - - - - - - - - - - - \n";
                cout << degree(tree);
                break;

            default: cout << "Ingresa una opción valida... " << endl;
                break;
        }
    }
}

void insert(BinaryTree<int> *tree){
    int data;
    cout<<"Ingrese el nodo: ";
    cin>>data;
    tree->insert(data);
    cout<<"\nElemento Ingresado :)" << endl;
}

string showTree(BinaryTree<int> *tree){
    cout << " a r b o l " << endl;
    return " ->  " + tree->preOrder();
}

int parent(BinaryTree<int> *tree){
    int data;
    cout << "Ingrese el nodo: ";
    cin >> data;
    cout << "\n\nPadre del nodo: ";
    return tree->parent(data);
}

string children(BinaryTree<int> *tree){
    int data;
    cout<< "Ingrese el nodo: ";
    cin>>data;
    return tree->children(data);
}

string silbings(BinaryTree<int> *tree) {
    int data;
    cout << "Ingrese el nodo: ";
    cin >> data;
    return tree->sibling(data);
}

int weight(BinaryTree<int> *tree){
    cout << " Peso del arbol: ";
    return tree->getWeight();
}

int levels(BinaryTree<int> *tree){
    int data;
   cout<<"Ingrese el nodo: ";
   cin>>data;
   return tree->levelOf(data);
}

int degree(BinaryTree<int> *tree){
    cout<<" Grado del arbol: ";
    return tree->degree();
}