#ifndef INCIDENTMANAGER_H
#define INCIDENTMANAGER_H

#include <string>
#include <vector>
using namespace std;

// Incident Node for Linked List

struct IncidentNode {
    string type;
    string location;
    string description;
    int severity;
    IncidentNode* next;

    IncidentNode(string t, string l, string d, int s)
        : type(t), location(l), description(d), severity(s), next(nullptr) {
    }
};


// BST Node (Search incidents by type)

struct BSTNode {
    string type;
    vector<IncidentNode*> incidents;
    BSTNode* left;
    BSTNode* right;

    BSTNode(string t) : type(t), left(nullptr), right(nullptr) {}
};

struct PQitem {                              // Priority Queue (Min-Heap based on severity)

    int severity;
    IncidentNode* incident;
};

// IncidentManager CLASS

class IncidentManager {
private:

    IncidentNode* head;
    vector<IncidentNode*> stackHistory;
    vector<IncidentNode*> queueList;
    vector<PQitem> minHeap;

    BSTNode* root;

public:

    // ----------- Constructor -----------
    IncidentManager();

    void addIncident(string t, string l, string d, int s);
    void deleteIncident(string t);
    void displayLL();

    void pushHistory(IncidentNode* node);
    IncidentNode* popHistory();

    void enqueueIncident(IncidentNode* node);
    IncidentNode* dequeueIncident();

    void insertPQ(IncidentNode* node, int severity);
    IncidentNode* extractMinPQ();
    void heapifyUp(int index);
    void heapifyDown(int index);

    BSTNode* insertBST(BSTNode* root, IncidentNode* node);
    vector<IncidentNode*> searchBST(string type);
    void inorderBST(BSTNode* root);

    int totalIncidents();
    // ADD ONLY
    void loadFromCSV(string filename);

};

#endif#pragma once



