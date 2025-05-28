/*
************************************************************DOCUMATION************************************************************************************
NAME:- VINODH KUMAR J
DATE:- 28/05/2025
PROJECT NAME:- ADDRESS_BOOK
***********************************************************************************************************************************************************
*/
#include "contact.h" // including contact.h library

int main()
{
        AddressBook info;  // declaring structure variable
        initialize(&info); // calling function to initialize contacts
        int input = 0;
        while (1)
        {
                printf("ADDRESSBOOK_MENU\n");
                printf("\033[1;42m--------------------------------------------------------------------------------\033[0m\n");
                printf("1. \033[1;31mCreate Contact\033[0m\n2. \033[1;32mSearch Contact\033[0m\n3. \033[1;33mQuick Search\033[0m\n4. \033[1;34mEdit Contact\033[0m\n5. \033[1;35mDelete contact\033[0m\n6. List Contact\n7. \033[1;36mSave and Exit\033[0m\n");
                printf("\033[1;42m--------------------------------------------------------------------------------\033[0m\n");
                printf("Enter Option\n");
                if (scanf("%d", &input) == 0) // vaildation for number 1-6
                {
                        printf("Invalid try enter num 1-6\n");
                        return 0;
                }
                else
                {
                        switch (input) // switch case for selected option
                        {
                        case 1:
                                printf("\033[1;41mCreate Contact\033[0m\n");
                                createContact(&info); // calling function to create contact
                                break;
                        case 2:
                                printf("\033[1;41mSearch Contact\033[0m\n");
                                searchContact(&info); // calling fuction to search contact
                                break;
                        case 3:
                                printf("\033[1;41mQuick Search\033[0m\n");
                                quickSearch(&info); // calling function to quick contact
                                break;
                        case 4:
                                printf("\033[1;41mEdit Contact\033[0m\n");
                                editContact(&info); // calling function to edit contact
                                break;
                        case 5:
                                printf("\033[1;41mDelete contact\033[0m\n");
                                deleteContact(&info); // calling function to delete contact
                                break;
                        case 6:
                                printf("\033[1;41mList Contact\033[0m\n");
                                listContacts(&info); // list all the contacts
                                break;
                        case 7:
                                printf("\033[1;41mSave and Exit\033[0m\n");
                                saveAndExit(&info); // calling function to save and exit
                                return 0;           // terminates the program
                        default:
                                printf("Enter a vaild number");
                        }
                }
        }
}
