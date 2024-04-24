#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H
#include <queue>

template <typename T>
class Node{
public:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node<T>* father;

    //Constructor of the class Node
    Node(T data){
        this->data = data;
        left = nullptr;
        right = nullptr;
        father = nullptr;
    }
};

template <typename T>
class BinaryTree{
private:
    Node<T>* root;
    Node<T>* iterator;
    int levelOfIterator;
    int weight;
    int degreeOfTheTree;

    void recursiveInsertion(Node<T>*& node,Node<T>* prevNode, T data);
    void recursiveSearch(Node<T>*& node, T data);
    void recursiveChildren(Node<T> *node, std::string &toReturn);
    void recursiveAncestors(Node<T> *node, std::string &toReturn);
    int recursiveDegree(Node<T> *node, T data);


    void recursivePreOrder(Node<T>* node, std::string &toReturn);
    void recursiveInOrder(Node<T> *node, std::string &toReturn);
    void recursivePostOrder(Node<T>* node, std::string &toReturn);

    void replace(Node<T> *node, Node<T> *newnodo);

public:
    //Constructor and destructor of the class
    BinaryTree();
    ~BinaryTree();

    //Manage the information
    void insert(T data);

    //Search for information
    void moveTo(T data);
    bool search(T data);

    //Iterate through the tree
    std::string preOrder();
    std::string postOrder();
    std::string inOrder();
    bool breadthFirstSearch(T data);

    //Functions of the teacher
    int getWeight();
    T parent(T data);
    std::string children(T data);
    std::string sibling(T data);
    int levelOf(T data);
    int degree();
    int height();
    std::string decendents(T data);
    std::string ancestors(T data);
    void delete_nodo(T data) ;
};

//Constructor of the class
template<typename T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
    iterator=root;
    weight = 0;
    levelOfIterator = 0;
    degreeOfTheTree=0;
}

//Destructor of the class
template<typename T>
BinaryTree<T>::~BinaryTree() {

}

//Manage the information
template <typename T>
void BinaryTree<T>::insert(T data) {
    levelOfIterator = 0;
    recursiveInsertion(root, nullptr,data);
    degreeOfTheTree = (levelOfIterator>degreeOfTheTree) ? levelOfIterator : degreeOfTheTree;
    weight++;
}

template<typename T>
void BinaryTree<T>::recursiveInsertion(Node<T> *&node,Node<T> *prevNode, T data) {
    if(node== nullptr){
        node = new Node<T>(data);
        node->father = prevNode;
    } else if(data<node->data){
        levelOfIterator++;
        recursiveInsertion(node->left,node,data);
    } else {
        levelOfIterator++;
        recursiveInsertion(node->right,node, data);
    }
}

//Search for information
template<typename T>
void BinaryTree<T>::moveTo(T data) {
    iterator=root;
    levelOfIterator = 0;
    recursiveSearch(root,data);
}

template<typename T>
bool BinaryTree<T>::search(T data) {
    moveTo(data);
    return iterator != NULL;
}

template<typename T>
void BinaryTree<T>::recursiveSearch(Node<T> *&node, T data) {
    if(node==nullptr) return;
    if(data<node->data){
        iterator = iterator->left;
        levelOfIterator++;
        recursiveSearch(node->left,data);
    } else if(data>node->data){
        iterator = iterator->right;
        levelOfIterator++;
        recursiveSearch(node->right,data);
    }
}

//Iterate through the tree
template<typename T>
std::string BinaryTree<T>::preOrder() {
    iterator=root;
    std::string toReturn;
    recursivePreOrder(iterator,toReturn);
    return toReturn;
}

template<typename T>
void BinaryTree<T>::recursivePreOrder(Node<T> *node, std::string &toReturn) {
    if(node==NULL) return;
    toReturn.append(std::to_string(node->data) + " - ");
    recursivePreOrder(node->left,toReturn);
    recursivePreOrder(node->right,toReturn);
}

template<typename T>
std::string BinaryTree<T>::inOrder() {
    iterator=root;
    std::string toReturn;
    recursiveInOrder(iterator,toReturn);
    return toReturn;
}

template<typename T>
void BinaryTree<T>::recursiveInOrder(Node<T> *node, std::string &toReturn) {
    if(node==NULL) return;
    recursiveInOrder(node->left,toReturn);
    toReturn.append(std::to_string(node->data) + " - ");
    recursiveInOrder(node->right,toReturn);
}

template<typename T>
std::string BinaryTree<T>::postOrder() {
    iterator=root;
    std::string toReturn;
    recursivePostOrder(iterator,toReturn);
    return toReturn;
}

template<typename T>
void BinaryTree<T>::recursivePostOrder(Node<T> *node, std::string &toReturn) {
    if(node==NULL) return;
    recursivePostOrder(node->left,toReturn);
    recursivePostOrder(node->right,toReturn);
    toReturn.append(std::to_string(node->data) + " - ");
}

template<typename T>
bool BinaryTree<T>::breadthFirstSearch(T data) {
    std::queue<Node<T> *> *auxiliarQueue = new std::queue<Node<T> *>;
    auxiliarQueue->push(root);

    while(auxiliarQueue->size()!=0){
        Node<T> *auxiliar = auxiliarQueue->front();
        auxiliarQueue->pop();
        if(auxiliar->data == data){
            return true;
        } else{
            if(auxiliar->left!=NULL) auxiliarQueue->push(auxiliar->left);

            if(auxiliar->right!=NULL)  auxiliarQueue->push(auxiliar->right);
        }
    }
    return false;
}


template<typename T>
int BinaryTree<T>::getWeight() {return weight;}

template<typename T>
T BinaryTree<T>::parent(T data) {
    moveTo(data);
    if(iterator!= nullptr && iterator->father != nullptr){
        return iterator->father->data;
    } else {
        throw std::domain_error("No");
    }
}

template<typename T>
std::string BinaryTree<T>::children(T data) {
    moveTo(data);
    std::string toReturn;
    if(iterator!= nullptr) {
        if (iterator->right != nullptr) {
            toReturn.append(std::to_string(iterator->right->data) + " ");
        }
        if (iterator->left != nullptr) {
            toReturn.append(std::to_string(iterator->left->data) + " ");
        }
        return toReturn;
    }
    return "-";
}

template<typename T>
std::string BinaryTree<T>::sibling(T data) {
    moveTo(data);
    std::string toReturn;
    if(iterator!= nullptr && iterator->father != nullptr) {
            if (iterator->father->left != iterator && iterator->father->left!= nullptr){
                return std::to_string(iterator->father->left->data);
            }
            if(iterator->father->right != iterator && iterator->father->right!= nullptr){
                return std::to_string(iterator->father->right->data);
            }
    }
    return "-";
}

template<typename T>
int BinaryTree<T>::levelOf(T data) {
    moveTo(data);
    if(iterator== nullptr) return -1;
    return levelOfIterator;
}

template<typename T>
int BinaryTree<T>::height() {
    return degreeOfTheTree+1;
}

template<typename T>
int BinaryTree<T>::degree() {
    iterator=root;
    int degree=0;
    return recursiveDegree(iterator,degree);
}

template<typename T>
int BinaryTree<T>::recursiveDegree(Node<T> *node, T data) {
    if (node->right != nullptr) {
        data++;
        recursiveDegree(node->right,data);
    }
    if (node->left != nullptr) {
        data++;
        recursiveDegree(node->left,data);
    }
    return data;
}

template<typename T>
std::string BinaryTree<T>::decendents(T data){
    moveTo(data);
    std::string toReturn;
    recursiveChildren(iterator,toReturn);
    return toReturn;
}

template<typename  T>
void BinaryTree<T>::recursiveChildren(Node<T> *node, std::string &toReturn) {
    if(node!= nullptr) {
        if (node->right != nullptr) {
            toReturn.append(std::to_string(node->right->data) + " ");
            recursiveChildren(node->right, toReturn);
        }
        if (node->left != nullptr) {
            toReturn.append(std::to_string(node->left->data) + " ");
            recursiveChildren(node->left,toReturn);
        }
    }
}

template<typename T>
std::string BinaryTree<T>::ancestors(T data){
    moveTo(data);
    std::string toReturn;
    recursiveAncestors(iterator,toReturn);
    return toReturn;
}

template<typename  T>
void BinaryTree<T>::recursiveAncestors(Node<T> *node, std::string &toReturn) {
    if(node!= nullptr && node->father != nullptr){
        toReturn.append(std::to_string(node->father->data) + " ");
        recursiveAncestors(node->father,toReturn);
    } else {
        toReturn.append("NULL");
    }
}

template<typename  T>
void BinaryTree<T>::replace(Node<T> *node, Node<T> *newnodo) {
    if(node->father){
        if(node->father->right!=NULL && node->data == node->father->right->data){
            node->father->right = newnodo;
        }
        else if( node->father->left!=NULL && node->data == node->father->left->data){
            node->father->left = newnodo;
        }
    }
    if (newnodo){
        newnodo->father = node->father;
    }

}

template<typename  T>
void BinaryTree<T>::delete_nodo(T data) {
    moveTo(data);
    if(iterator->left==NULL || iterator->right==NULL){
        if (iterator->left) {
            replace(iterator,iterator->left);
            iterator->left = NULL;
            iterator->right = NULL;
            delete(iterator);

        } else if(iterator->right) {
            replace(iterator,iterator->right);
            iterator->left = NULL;
            iterator->right = NULL;
            delete(iterator);
        }
    }
}


#endif //BINARYTREE_BINARYTREE_Hreturn