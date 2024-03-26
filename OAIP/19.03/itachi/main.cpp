
#include <iostream>
#include <cstdlib>

using namespace std;

class TreeNode {
    int* keys;
    int t;
    TreeNode** C;
    int n;
    bool leaf;

public:
    TreeNode(int temp, bool bool_leaf);

    void insertNonFull(int k);
    void splitChild(int i, TreeNode* y);

    void deleteKey(int k);
    int getPred(int idx);
    int getSucc(int idx);
    void fill(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void merge(int idx);
    void traverse();

    TreeNode* search(int k);

    friend class BTree;
};

class BTree {
    TreeNode* root;
    int t;

public:
    BTree(int temp) {
        root = NULL;
        t = temp;
    }

    void traverse() {
        if (root != NULL)
            root->traverse();
    }

    TreeNode* search(int k) {
        return (root == NULL) ? NULL : root->search(k);
    }

    void insert(int k);

};

TreeNode::TreeNode(int t1, bool leaf1) {
    t = t1;
    leaf = leaf1;

    keys = new int[2 * t - 1];
    C = new TreeNode * [2 * t];

    n = 0;
}

void TreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (leaf == false)
            C[i]->traverse();
        cout << " " << keys[i];
    }

    if (leaf == false)
        C[i]->traverse();
}

TreeNode* TreeNode::search(int k) {
    int i = 0;
    while (i < n && k > keys[i])
        i++;

    if (keys[i] == k)
        return this;

    if (leaf == true)
        return NULL;

    return C[i]->search(k);
}

void BTree::insert(int k) {
    if (root == NULL) {
        root = new TreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    }
    else {
        if (root->n == 2 * t - 1) {
            TreeNode* s = new TreeNode(t, false);

            s->C[0] = root;
            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k);

            root = s;
        }
        else
            root->insertNonFull(k);
    }
}

void TreeNode::insertNonFull(int k) {
    int i = n - 1;

    if (leaf == true) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = k;
        n = n + 1;
    }
    else {
        while (i >= 0 && keys[i] > k)
            i--;

        if (C[i + 1]->n == 2 * t - 1) {
            splitChild(i + 1, C[i + 1]);

            if (keys[i + 1] < k)
                i++;
        }
        C[i + 1]->insertNonFull(k);
    }
}

void TreeNode::splitChild(int i, TreeNode* y) {
    TreeNode* z = new TreeNode(y->t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (y->leaf == false) {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    y->n = t - 1;
    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    C[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];
    n = n + 1;
}

void TreeNode::deleteKey(int k) {
    int idx = 0;
    while (idx < n && keys[idx] < k)
        idx++;

    if (idx < n && keys[idx] == k) {
        if (leaf) {
            for (int i = idx; i < n - 1; i++)
                keys[i] = keys[i + 1];
            n--;
        }
        else {
            // Находим предшествующий ключ в поддереве, корнем которого является C[idx]
            // Заменяем ключ, который нужно удалить, предшествующим ключом
            // Рекурсивно удаляем предшествующий ключ из поддерева
            int pred = getPred(idx);
            keys[idx] = pred;
            C[idx]->deleteKey(pred);
        }
    }
    else {
        if (leaf) {
            // Ключ отсутствует в узле
            return;
        }

        bool flag = (idx == n);

        if (C[idx]->n < t) {
            // Выполняем необходимые действия, чтобы убедиться, что C[idx] имеет как минимум t ключей
            fill(idx);
        }

        if (flag && idx > n)
            C[idx - 1]->deleteKey(k);
        else
            C[idx]->deleteKey(k);
    }
}

int TreeNode::getPred(int idx) {
    TreeNode* curr = C[idx];
    while (!curr->leaf)
        curr = curr->C[curr->n];
    return curr->keys[curr->n - 1];
}

int TreeNode::getSucc(int idx) {
    TreeNode* curr = C[idx + 1];
    while (!curr->leaf)
        curr = curr->C[0];
    return curr->keys[0];
}

void TreeNode::fill(int idx) {
    if (idx != 0 && C[idx - 1]->n >= t)
        borrowFromPrev(idx);
    else if (idx != n && C[idx + 1]->n >= t)
        borrowFromNext(idx);
    else {
        if (idx != n)
            merge(idx);
        else
            merge(idx - 1);
    }
}

void TreeNode::borrowFromPrev(int idx) {
    TreeNode* child = C[idx];
    TreeNode* sibling = C[idx - 1];

    for (int i = child->n - 1; i >= 0; i--)
        child->keys[i + 1] = child->keys[i];

    if (!child->leaf) {
        for (int i = child->n; i >= 0; i--)
            child->C[i + 1] = child->C[i];
    }

    child->keys[0] = keys[idx - 1];

    if (!leaf)
        child->C[0] = sibling->C[sibling->n];

    keys[idx - 1] = sibling->keys[sibling->n - 1];

    child->n++;
    sibling->n--;
}

void TreeNode::borrowFromNext(int idx) {
    TreeNode* child = C[idx];
    TreeNode* sibling = C[idx + 1];

    child->keys[child->n] = keys[idx];

    if (!child->leaf)
        child->C[child->n + 1] = sibling->C[0];

    keys[idx] = sibling->keys[0];

    for (int i = 1; i < sibling->n; i++)
        sibling->keys[i - 1] = sibling->keys[i];

    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; i++)
            sibling->C[i - 1] = sibling->C[i];
    }

    child->n++;
    sibling->n--;
}

void TreeNode::merge(int idx) {
    TreeNode* child = C[idx];
    TreeNode* sibling = C[idx + 1];

    child->keys[t - 1] = keys[idx];

    for (int i = 0; i < sibling->n; i++)
        child->keys[i + t] = sibling->keys[i];

    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; i++)
            child->C[i + t] = sibling->C[i];
    }

    for (int i = idx + 1; i < n; i++)
        keys[i - 1] = keys[i];

    for (int i = idx + 2; i <= n; i++)
        C[i - 1] = C[i];

    child->n += sibling->n + 1;
    n--;

    delete sibling;
}


int main() {
    BTree t(10);
    
    srand((unsigned)time(NULL));

    for (int i = 0; i < 10000; i++) {
        t.insert(rand() % 100000);
    };

    cout << "B-дерево: ";
    t.traverse();

    int k;
    cout << endl<<" Введите эллемент: ";
    cin >> k;
    (t.search(k) != NULL) ? cout << endl
        << k << " найдено"
        : cout << endl
        << k << " не найдено";

}