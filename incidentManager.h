#ifndef INCIDENT_MANAGER_H
#define INCIDENT_MANAGER_H

#include <string>
#include <vector>
using namespace std;

struct IncidentNode {
    string type, location, description;
    int severity;
    IncidentNode* next;

    IncidentNode(string t, string l, string d, int s) {
        type = t; location = l; description = d; severity = s;
        next = nullptr;
    }
};

struct BSTNode {
    string type;
    vector<IncidentNode*> incidents;
    BSTNode* left;
    BSTNode* right;

    BSTNode(string t) {
        type = t;
        left = right = nullptr;
    }
};

class IncidentManager {
private:
    IncidentNode* head;
    BSTNode* root;

public:
    IncidentManager();

    // Linked List
    void addIncident(string, string, string, int);
    void deleteIncident(string);
    void displayLL();
    int totalIncidents();

    // BST
    BSTNode* insertBST(BSTNode*, IncidentNode*);
    vector<IncidentNode*> searchBST(string);
    void inorderBST(BSTNode*);

    // FILE LOADING ⭐
    void loadFromFile(string filename);
};

#endif

