#include "AuthorityIncidentManager.h"

AuthorityIncidentManager::AuthorityIncidentManager() {
    head = nullptr;
}

void AuthorityIncidentManager::addIncident(string t, string l, string d, int s) {

    AuthorityIncident* newNode = new AuthorityIncident(t, l, d, s);

    if (head == nullptr) {
        head = newNode;
    }
    else {
        AuthorityIncident* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void AuthorityIncidentManager::displayIncidents() {

    AuthorityIncident* temp = head;

    while (temp != nullptr) {
        cout << "Type: " << temp->type << endl;
        cout << "Location: " << temp->location << endl;
        cout << "Description: " << temp->description << endl;
        cout << "Severity: " << temp->severity << endl;
        cout << "----------------------" << endl;
        temp = temp->next;
    }
}

int AuthorityIncidentManager::totalIncidents() {

    int count = 0;
    AuthorityIncident* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}
