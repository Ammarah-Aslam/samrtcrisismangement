#ifndef AUTHORITY_INCIDENT_H
#define AUTHORITY_INCIDENT_H

#include <string>
using namespace std;

struct AuthorityIncident {
    string type;
    string location;
    string description;
    int severity;

    AuthorityIncident* next;

    AuthorityIncident(string t, string l, string d, int s) {
        type = t;
        location = l;
        description = d;
        severity = s;
        next = nullptr;
    }
};

#endif
#pragma once
