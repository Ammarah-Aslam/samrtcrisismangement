#include "Incident.h"

// Default constructor
Incident::Incident()
    : incidentID(0),
      incidentType(""),
      location(""),
      description(""),
      dateTime(""),
      severityLevel(0),
      status("pending"),
      citizenName(""),
      citizenContact("")
{
}

// Parameterized constructor
Incident::Incident(int incId, string incType, string incLocation,
                   string incDescription, string incDateTime,
                   int level, string incStatus,
                   string name, string contact)
    : incidentID(incId),
      incidentType(incType),
      location(incLocation),
      description(incDescription),
      dateTime(incDateTime),
      severityLevel(level),
      status(incStatus),
      citizenName(name),
      citizenContact(contact)
{
}

// Getters
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

// Setters
void Incident::setStatus(string updatedStatus) {
    status = updatedStatus;
}

void Incident::setSeverity(int newSeverity) {
    severityLevel = newSeverity;
}
