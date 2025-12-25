#include "Incident.h"


Incident::Incident() {
    incidentID = 0;
    incidentType = "";
    location = "";
    description = "";
    dateTime = "";
    severityLevel = 0;
    status = "pending";

            // Citizen information

    citizenName = "";
    citizenContact = "";
}

Incident::Incident(int id, string type, string loc, string desc,
    string datetime, int severity, string stat,
    string cName, string cContact)
{
    incidentID = id;
    incidentType = type;
    location = loc;
    description = desc;
    dateTime = datetime;
    severityLevel = severity;
    status = stat;

    citizenName = cName;
    citizenContact = cContact;
}


int Incident::getID() const {
    return incidentID;
}

string Incident::getType() const {
    return incidentType;
}

string Incident::getLocation() const {
    return location;
}

string Incident::getDateTime() const {
    return dateTime;
}

int Incident::getSeverity() const {
    return severityLevel;
}

string Incident::getStatus() const {
    return status;
}

string Incident::getCitizenName() const {
    return citizenName;
}

string Incident::getCitizenContact() const {
    return citizenContact;
}

void Incident::setStatus(string newStatus) {
    status = newStatus;
}

void Incident::setSeverity(int sev) {
    severityLevel = sev;
}
