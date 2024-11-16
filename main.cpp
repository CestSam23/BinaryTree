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
    cout<< "[8].  Mostrar altura." << endl;
    cout<< "[9].  Mostrar grado." << endl;
    cout<< "[10]. Mostrar descendientes." << endl;
    cout<< "[11]. Mostrar ancestros." << endl;
    cout<< "\n[12]. PRE-Order." << endl;
    cout<< "[13]. IN-Order." << endl;
    cout<< "[14]. POST-Order." << endl;
    cout<<"[15]. Charge preload Tree"<<endl;
    cout << "[16]. BFS. " << endl;
    cout<<"[17]. Delete Node"<<endl;
    cout<< "\n[0]. Salir." ;
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
int height(BinaryTree<int> *tree);
string descendant(BinaryTree<int> *tree);
string ancestors(BinaryTree<int> *tree);
string preOrder(BinaryTree<int> *tree);
string inOrder(BinaryTree<int> *tree);
string postOrder(BinaryTree<int> *tree);
void bfs(BinaryTree<int> *tree);
void delete_node(BinaryTree<int> *tree);


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
                cout << "- - - - - - - - - - - - - - - - M O S T R A R  A L T U R A - - - - - - - - - - - - - - - - \n";
                cout << height(tree);
                break;
            case 9:
                cout << "- - - - - - - - - - - - - - - - M O S T R A R  G R A D O - - - - - - - - - - - - - - - - \n";
                cout << degree(tree);
                break;
            case 10:
                cout << "- - - - - - - - - - - - M O S T R A R  D E S C E N D I E N T E S  - - - - - - - - - - - - \n";
                cout<<descendant(tree);
                break;
            case 11:
                cout << "- - - - - - - - - - - - - - - M O S T R A R  A N C E S T R O S - - - - - - - - - - - - - - \n";
                cout<<ancestors(tree);
                break;

            case 12:
                cout << "- - - - - - - - - - - - - - - P R E   O R D E R - - - - - - - - - - - - - - \n";
                cout<< preOrder(tree);
                break;

            case 13:
                cout << "- - - - - - - - - - - - - - - I N   O R D E R - - - - - - - - - - - - - - \n";
                cout<< inOrder(tree);
                break;

            case 14:
                cout << "- - - - - - - - - - - - - - - P O S   O R D E R - - - - - - - - - - - - - - \n";
                cout<< postOrder(tree);
                break;

            case 15:
                cout<<"- - - - - - - - - - - - - - - - LOADING... - - - - - - - - - - - - - - - - - - \n";
                tree->insert(8);
                tree->insert(3);
                tree->insert(1);
                /*tree->insert(10);
                tree->insert(6);
                tree->insert(14);
                tree->insert(4);
                tree->insert(7);
                tree->insert(13);
                tree->insert(4);*/
                break;
            case 16:
                cout << "- - - - - - - - - - - - - - - Búsqueda por Anchura - - - - - - - - - - - - - - \n";
                bfs(tree);
                break;

            case 17:
                cout<<"- - - - - - - - - - - - - - - - Delete Node- - - - - - - - - - - - - - - - - - - \n";
                delete_node(tree);
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

int height(BinaryTree<int> *tree){
    cout<<" Altura del arbol: ";
    return tree->height();
}

int degree(BinaryTree<int> *tree){
    cout<<" Grado del arbol: ";
    return tree->degree();
}

string descendant(BinaryTree<int> *tree) {
    int data;
    cout<<"Ingrese el nodo: ";
    cin>>data;
    return tree->decendents(data);
}

string ancestors(BinaryTree<int> *tree) {
    int data;
    cout<<"Ingrese el nodo: ";
    cin>>data;
    return tree->ancestors(data);
}

string preOrder(BinaryTree<int> *tree) {
    cout << "Algoritmo PRE ORDER \n-> ";
    return tree->preOrder();
}

string inOrder(BinaryTree<int> *tree) {
    cout << "Algoritmo IN ORDER \n-> ";
    return tree->inOrder();
}

string postOrder(BinaryTree<int> *tree) {
    cout << "Algoritmo POST ORDER \n-> ";
    return tree->postOrder();
}

void bfs(BinaryTree<int> *tree){
    int data;
    cout << "Ingrese el dato a buscar: ";
    cin >> data;

    if(tree->breadthFirstSearch(data)){
        cout << "Elemento existente" << endl;
    } else {
        cout << "Elemento no existente" << endl;
    }
}

void delete_node(BinaryTree<int> *tree){
    int data;
    cout<<"Ingrese el nodo: ";
    cin>>data;
    tree->delete_nodo(data);
    cout<<"\nNODO BORRADO\n";
}
