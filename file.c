#include <stdio.h> //standard input output library
#include "file.h"  //file.h to use file pointer and related functions

void saveContactsToFile(AddressBook *addressBook) // to save the contact info to file
{
    FILE *fp = fopen("contacts.txt", "w");          // open file
    fprintf(fp, "%d\n", addressBook->contactCount); // size
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp, "%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    fclose(fp); // close file
}

void loadContactsFromFile(AddressBook *addressBook) // to load the contact from the file to structure
{
    FILE *fp = fopen("contacts.txt", "r"); // open file
    if (fp == NULL)                        // verifies if file is present or not
    {
        printf("file not found\n");
        return;
    }
    fscanf(fp, "%d\n", &addressBook->contactCount); // size
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fscanf(fp, "\n%[^,],%[^,],%[^\n]\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    fclose(fp); // close file
}
