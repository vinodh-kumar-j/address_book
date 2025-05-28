#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100 // max contact that can be stored can be altered to our requirements , macro max contacts
#include <stdio.h>
#include <ctype.h>
typedef struct
{ // user defined datatype/structure with name phone and email strings
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct
{ // array of sturctures and contactcount
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

// function prototype
void createContact(AddressBook *addressBook);
int searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);
void quickSearch(AddressBook *addressBook);
void saveAndExit(AddressBook *addressBook);
// validation function prototype
int valnam(const char *str);
int valemail(const char *str);
int valphone(const char *str);
int repphone(const char *phone, AddressBook *addressBook);
int repemail(const char *email, AddressBook *addressBook);
#endif
