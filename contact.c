#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"

void listContacts(AddressBook *addressBook) // used to list the contacts
{
    printf("\033[1;47m%-11s %-20s %-20s %s\033[0m\n", "SL.no", "NAME", "PHONE", "EMAIL");
    for (int i = 0; i < addressBook->contactCount; i++) // running loop for size/contact count time to optain the stored contacts
    {
        printf("%d%-10s %-20s %-20s %s\n", i, ".",
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }
}

void initialize(AddressBook *addressBook) // initialize the contacts from file to array or simple updatation of data to program
{
    addressBook->contactCount = 0;
    loadContactsFromFile(addressBook); // calling function for load contact from file
}

void saveAndExit(AddressBook *addressBook) // save and exit used to save the contacts to file
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(0);                         // Exit the program
}

void createContact(AddressBook *addressBook) // to creat new contact
{
    char name[20], phone[50], email[50];
    if (addressBook->contactCount < MAX_CONTACTS)
    {
        do // to wait for vaid input from user using do while loop
        {
            printf("Enter the name: ");
            getchar();
            scanf("%[^\n]", name);
            if (!valnam(name)) // since reading name from user need to vaildate if its only aphabet or not
                printf("Please enter a valid name\n");
        } while (!valnam(name));
        strcpy(addressBook->contacts[addressBook->contactCount].name, name); // copy user entered name to new contact
        do
        {
            printf("Enter the phone: ");
            getchar();
            scanf("%[^\n]", phone);
            if (!valphone(phone)) // vaildation for number
                printf("Please enter a vaild phone\n");
            if (repphone(phone, addressBook) != -1) // vaildation for repeated number
                printf("This number already exist for %s\n", addressBook->contacts[repphone(phone, addressBook)].name);
        } while (!valphone(phone) || repphone(phone, addressBook) != -1);
        strcpy(addressBook->contacts[addressBook->contactCount].phone, phone); // copy phone string to new contact phone
        do
        {
            printf("Enter the email: ");
            getchar();
            scanf("%[^\n]", email);
            if (!valemail(email)) // vaildation for email
                printf("Please enter a vaild email\n");
            if (repemail(email, addressBook) != -1) // checks for repeatation of email
                printf("This email already exist for %s\n", addressBook->contacts[repemail(email, addressBook)].name);
        } while (!valemail(email) || repemail(email, addressBook) != -1);
        strcpy(addressBook->contacts[addressBook->contactCount].email, email); // copy user entered email to new contacts email

        addressBook->contactCount++; // increamenting the count
        printf("Contact sucessfully saved\n");
    }
    else
    {
        printf("Addressbook FULL!!\n");
    }
}

int searchContact(AddressBook *addressBook) // used to serach contacts based on name phone and email
{
    int flag = -1, option;
    char str[20];
    int arr[25]; // array to keep track of index
    int count = 0, index = 0, flag2 = 0;
    printf("SEARCH BY\n1.Name\t2.Phone\t3.Email\t4.For main menu\n");
    getchar();
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        do
        {
            printf("Enter the name to be searched: ");
            getchar();
            scanf("%[^\n]", str);
            if (!valnam(str))
                printf("Please enter a valid name\n");
        } while (!valnam(str));
        printf("\033[1;47m%-11s %-20s %-20s %s\033[0m\n", "SL.no", "NAME", "PHONE", "EMAIL");
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(str, addressBook->contacts[i].name) == 0) // string comparison if matched will be printing the respective index contact
            {
                flag = i;
                printf("%d%-10s %-20s %-20s %s\n", flag, ".", addressBook->contacts[flag].name, addressBook->contacts[flag].phone, addressBook->contacts[flag].email);
                arr[count++] = i;
            }
        }
        if (flag == -1)
        {
            printf("Person not found\n");
            return -1;
        }
        else
        {
            printf("Select contact : "); // asking user to enter the index display, sometimes contacts can be with same name and checking if it matches like a 2 step verification
            scanf(" %d", &index);
            for (int i = 0; i < count; i++)
            {
                if (arr[i] == index)
                {
                    flag2++;
                    break;
                }
            }
            if (flag2)
            {
                printf("%d%-10s %-20s %-20s %s\n", flag, ".", addressBook->contacts[index].name, addressBook->contacts[index].phone, addressBook->contacts[index].email);
                return index;
            }
            else
            {

                printf("You have Enter the Invalid slno\n");
            }
        }
        break;
    case 2:
        do
        {
            printf("Enter the phone number to be searched: ");
            getchar();
            scanf("%[^\n]", str);
            if (!valphone(str))
                printf("Please enter a vaild phone\n");
        } while (!valphone(str));
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(str, addressBook->contacts[i].phone) == 0) // string comparison if matched will be printing the respective index contact
            {
                flag = i;
                arr[count++] = i;
                break;
            }
        }
        if (flag == -1)
        {
            printf("Phone number not found\n");
            return -1;
        }
        else
        {
            printf("\033[1;47m%-11s %-20s %-20s %s\033[0m\n", "SL.no", "NAME", "PHONE", "EMAIL");
            printf("%d%-10s %-20s %-20s %s\n", flag, ".", addressBook->contacts[flag].name, addressBook->contacts[flag].phone, addressBook->contacts[flag].email);
            return flag;
        }
        break;
    case 3:
        do
        {
            printf("Enter the email to be searched: ");
            getchar();
            scanf("%[^\n]", str);
            if (!valemail(str))
                printf("Please enter a vaild email\n");
        } while (!valemail(str));
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(str, addressBook->contacts[i].email) == 0) // string comparison if matched will be printing the respective index contact
            {
                flag = i;
                arr[count++] = i;
                break;
            }
        }
        if (flag == -1)
        {
            printf("Email not found\n");
            return -1;
        }
        else
        {
            printf("\033[1;47m%-11s %-20s %-20s %s\033[0m\n", "SL.no", "NAME", "PHONE", "EMAIL");
            printf("%d%-10s %-20s %-20s %s\n", flag, ".", addressBook->contacts[flag].name, addressBook->contacts[flag].phone, addressBook->contacts[flag].email);
            return flag;
        }
        break;
    case 4:
        return -1;
        break;
    default:
        printf("Enter the vaild input\n");
    }
}

void editContact(AddressBook *addressBook) // used to edit contact
{
    char name[20], phone[50], email[50];
    int index = 0, option;
    index = searchContact(addressBook); // searching contact based on name, phone and email, consider returned index as contact to be edited
    if (index == -1)
    {
        printf("Enter a vaild detials\n");
    }
    else
    {
        printf("EDIT\n1.Name\t2.Phone\t3.Email\t4.For main menu\n");
        scanf(" %d", &option);
        switch (option)
        {
        case 1:
            do
            {
                printf("Enter the name: ");
                getchar();
                scanf("%[^\n]", name);
                if (!valnam(name))
                    printf("Please enter a valid name\n");
            } while (!valnam(name));
            strcpy(addressBook->contacts[index].name, name); // editing the name in respective index
            printf("Contact saved sucessfully\n");
            break;
        case 2:
            do
            {
                printf("Enter the phone: ");
                getchar();
                scanf("%[^\n]", phone);
                if (!valphone(phone))
                    printf("Please enter a vaild phone\n");
                if (repphone(phone, addressBook) != -1)
                    printf("This number already exist for %s\n", addressBook->contacts[repphone(phone, addressBook)].name);
            } while (!valphone(phone) || repphone(phone, addressBook) != -1);
            strcpy(addressBook->contacts[index].phone, phone); // editing phone in respective index
            printf("Contact saved sucessfully\n");
            break;
        case 3:
            do
            {
                printf("Enter the email: ");
                getchar();
                scanf("%[^\n]", email);
                if (!valemail(email))
                    printf("Please enter a vaild email\n");
                if (repemail(email, addressBook) != -1)
                    printf("This email already exist for %s\n", addressBook->contacts[repemail(email, addressBook)].name);
            } while (!valemail(email) || repemail(email, addressBook) != -1);
            strcpy(addressBook->contacts[index].email, email); // editing email in respective index
            printf("Contact saved sucessfully\n");
            break;
        case 4:
            break;
        default:
            printf("Enter a vaild number\n");
        }
    }
}

void deleteContact(AddressBook *addressBook) // use to delete contact
{
    int index = 0, token = 0, flag = 0;
    char ch;
    index = searchContact(addressBook); // searching contacts with help of serachcontact function and returning index
    if (index == -1)
    {
        printf("Enter a vaild detials\n");
    }
    else
    {
        printf("Do you want to delete this contact press 'y' for yes or 'n' for no and go back to main menu\n"); // 2 step verification
        scanf(" %c", &ch);
        switch (ch)
        {
        case 'y': // for both Y and y case
        case 'Y':
            for (int i = index; i < addressBook->contactCount; i++)
            {
                addressBook->contacts[i] = addressBook->contacts[i + 1];
            }
            addressBook->contactCount--;
            printf("Contact sucessfully deleted\n");
            break;
        case 'n': // for both n and N case
        case 'N':
            break;
        default:
            printf("Enter a vaild character\n");
        }
    }
}

void quickSearch(AddressBook *addressBook) // this option help user to find contact based on first litter with ease lists all the matched contacts
{
    int flag = -1;
    char ch;
    printf("SEARCH BY CHARACTER\n");
    getchar();
    scanf("%c", &ch);
    printf("\033[1;47m%-11s %-20s %-20s %s\033[0m\n", "SL.no", "NAME", "PHONE", "EMAIL");
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (ch == (addressBook->contacts[i].name[0])) // compairing first index of all contacts with user provided char
        {
            flag = i;
            printf("%d%-10s %-20s %-20s %s\n", flag, ".", addressBook->contacts[flag].name, addressBook->contacts[flag].phone, addressBook->contacts[flag].email);
        }
    }
    if (flag == -1)
    {
        printf("Person not found\n");
    }
}
// validation and supporting functions
int valnam(const char *str) // vaildates if name only consists of string or alphabets
{
    int size = 0, flag = 0;
    size = strlen(str);
    for (int i = 0; i < size; i++)
    {
        if (str[i] >= 33 && str[i] <= 64 || str[i] >= 91 && str[i] <= 96 || str[i] >= 123 && str[i] <= 127)
        {
            flag++;
        }
    }
    if (flag)
        return 0;
    else
        return 1;
}
int valphone(const char *str) // vaildates phone number if it has exactly 10 number, checks aphabetic char
{
    int size = 0, flag = 0;
    size = strlen(str);
    if (size == 10)
    {
        for (int i = 0; i < size; i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                flag++;
            }
        }
        if (flag == 10)
            return 1;
        else
            return 0;
    }
    else
    {
        return 0;
    }
}
int valemail(const char *str) // vaildates email based on @ and . character and if atleast one char in between @ and .
{
    int size = 0, flag = 0;
    size = strlen(str);
    if (!(islower(str[0])))
    {
        return 0;
    }
    for (int i = 0; i < size; i++)
    {

        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] == ' ')
        {
            return 0;
        }
        if (str[i] == '@' && str[i + 1] != '.')
        {
            flag++;
        }
        if (str[i] == '.')
        {
            flag++;
        }
    }
    if (flag == 2)
        return 1;
    else
        return 0;
}
int repphone(const char *phone, AddressBook *addressBook) // check phone number if its already exists for any contacts
{
    int flag = -1;
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(phone, addressBook->contacts[i].phone) == 0)
        {
            flag = i;
            break;
        }
    }
    if (flag == -1)
    {
        return -1;
    }
    else
    {
        return flag;
    }
}
int repemail(const char *email, AddressBook *addressBook) // checks for email if its already exists for any contacts
{
    int flag = -1;
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(email, addressBook->contacts[i].email) == 0)
        {
            flag = i;
            break;
        }
    }
    if (flag == -1)
    {
        return -1;
    }
    else
    {
        return flag;
    }
}
