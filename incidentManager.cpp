#include "IncidentManager.h"
#include <iostream>
using namespace std;

// ----------- Constructor -----------

IncidentManager::IncidentManager() {
    head = nullptr;
    root = nullptr;
}

// ----------- Linked List Operations -----------

void IncidentManager::addIncident(string t, string l, string d, int s) {
    IncidentNode* newNode = new IncidentNode(t, l, d, s);
    newNode->next = head;
    head = newNode;
}

void IncidentManager::deleteIncident(string t) {
    IncidentNode* temp = head;
    IncidentNode* prev = nullptr;

    while (temp != nullptr) {
        if (temp->type == t) {
            if (prev == nullptr) head = temp->next;
            else prev->next = temp->next;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void IncidentManager::displayLL() {
    IncidentNode* temp = head;
    while (temp != nullptr) {
        cout << "Type: " << temp->type << ", Location: " << temp->location
            << ", Severity: " << temp->severity << endl;
        temp = temp->next;
    }
}

// ----------- Stack Operations -----------

void IncidentManager::pushHistory(IncidentNode* node) {
    stackHistory.push_back(node);
}

IncidentNode* IncidentManager::popHistory() {
    if (stackHistory.empty()) return nullptr;
    IncidentNode* node = stackHistory.back();
    stackHistory.pop_back();
    return node;
}

// ----------- Queue Operations -----------

void IncidentManager::enqueueIncident(IncidentNode* node) {
    queueList.push_back(node);
}

IncidentNode* IncidentManager::dequeueIncident() {
    if (queueList.empty()) return nullptr;
    IncidentNode* node = queueList.front();
    queueList.erase(queueList.begin());
    return node;
}

// ----------- Priority Queue (Min-Heap) -----------

void IncidentManager::insertPQ(IncidentNode* node, int severity) {
    PQitem item = { severity, node };
    minHeap.push_back(item);
    heapifyUp(minHeap.size() - 1);
}

IncidentNode* IncidentManager::extractMinPQ() {
    if (minHeap.empty()) return nullptr;
    IncidentNode* node = minHeap[0].incident;
    minHeap[0] = minHeap.back();
    minHeap.pop_back();
    heapifyDown(0);
    return node;
}

void IncidentManager::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (minHeap[index].severity < minHeap[parent].severity) {
            swap(minHeap[index], minHeap[parent]);
            index = parent;
        }
        else break;
    }
}

void IncidentManager::heapifyDown(int index) {
    int left, right, smallest;
    int size = minHeap.size();

    while (true) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;

        if (left < size && minHeap[left].severity < minHeap[smallest].severity)
            smallest = left;
        if (right < size && minHeap[right].severity < minHeap[smallest].severity)
            smallest = right;

        if (smallest != index) {
            swap(minHeap[index], minHeap[smallest]);
            index = smallest;
        }
        else break;
    }
}

// ----------- BST Operations -----------

BSTNode* IncidentManager::insertBST(BSTNode* root, IncidentNode* node) {
    if (root == nullptr) return new BSTNode(node->type);

    if (node->type < root->type)
        root->left = insertBST(root->left, node);
    else if (node->type > root->type)
        root->right = insertBST(root->right, node);
    else
        root->incidents.push_back(node);

    return root;
}

vector<IncidentNode*> IncidentManager::searchBST(string type) {
    vector<IncidentNode*> result;
    BSTNode* temp = root;

    while (temp != nullptr) {
        if (type == temp->type) return temp->incidents;
        else if (type < temp->type) temp = temp->left;
        else temp = temp->right;
    }
    return result;
}

void IncidentManager::inorderBST(BSTNode* root) {
    if (root == nullptr) return;
    inorderBST(root->left);
    cout << "Type: " << root->type << " (Incidents: " << root->incidents.size() << ")\n";
    inorderBST(root->right);
}

int IncidentManager::totalIncidents() {
    int count = 0;
    IncidentNode* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}
