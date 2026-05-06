#include <iostream>
#include <cassert>
#include "binarytree.cpp"

using namespace binarytree;

void test_1()
{
    std::cout << "Teste 1" << std::endl;
    node *root = nullptr;
    assert(is_strict(root) == true);
}

void test_2()
{
    std::cout << "Teste 2" << std::endl;
    node *root = createnode("A");
    assert(is_strict(root) == true);
    destroy(root);
}

void test_3()
{
    std::cout << "Teste 3" << std::endl;
    node *root = createnode("A");
    root->left = createnode("B");
    root->right = createnode("C");
    assert(is_strict(root) == true);
    destroy(root);
}

void test_4()
{
    std::cout << "Teste 4" << std::endl;
    node *root = createnode("A");
    root->left = createnode("B");
    assert(is_strict(root) == false);
    destroy(root);
}

void test_5()
{
    std::cout << "Teste 5" << std::endl;
    node *root = createnode("A");
    root->right = createnode("B");
    assert(is_strict(root) == false);
    destroy(root);
}

void test_6()
{
    std::cout << "Teste 6" << std::endl;
    node *root = createnode("A");
    root->left = createnode("B");
    root->right = createnode("C");
    root->left->left = createnode("D");
    root->left->right = createnode("E");
    root->right->left = createnode("F");
    root->right->right = createnode("G");
    
    assert(is_strict(root) == true);
    destroy(root);
}

void test_7()
{
    std::cout << "Teste 7" << std::endl;
    node *root = createnode("A");
    root->left = createnode("B");
    root->right = createnode("C");
    root->left->left = createnode("D");
    root->left->right = createnode("E");
    
    assert(is_strict(root) == true);
    destroy(root);
}

void test_8()
{
    std::cout << "Teste 8" << std::endl;
    node *root = createnode("A");
    root->left = createnode("B");
    root->right = createnode("C");
    root->left->left = createnode("D");

    assert(is_strict(root) == false);
    destroy(root);
}

void test_9()
{
    std::cout << "Teste 9" << std::endl;
    node *root = createnode("A");
    root->left = createnode("B");
    root->right = createnode("C");
    root->left->left = createnode("D");
    root->left->right = createnode("E");
    root->right->left = createnode("F");
    
    assert(is_strict(root) == false);
    destroy(root);
}

int main()
{  
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    test_7();
    test_8();
    test_9();

    std::cout << "TODOS OS TESTES PASSARAM COM SUCESSO!" << std::endl;
}