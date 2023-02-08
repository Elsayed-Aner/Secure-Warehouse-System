#include <stdio.h>
#include <stdlib.h>

#include "api.h"
#include "fun.h"

extern char entered_user[];
extern char entered_pass[];
extern int user_check;

struct name{
    char first[10];
    char last[10];
};
struct items{
    char name[10];
    char q[4];
};
struct client{
    struct name c_name;
    char age[3];
    char phone[11];
    struct items c_items;
};

struct client s_client, clean_client;

FILE *fptr;

/*****************************************************************************
 * clear_c: clear the command.                                               *
 *                                                                           *
 *****************************************************************************/
void clear_c (void)
{
    system("cls");
    printf("\n\t\t==> Safe system <==\n");
    printf("    ------------------------------------------\n\n\n");
}

/*****************************************************************************
 * add_client: add client data to data base system                           *
 *             return 0 for data ignored, return 1 for client data added     *
 *             successfully.                                                 *
 *****************************************************************************/
int add_client (void)
{
    char c;
    printf("\n");
    printf("new client...\n");
    printf("------------------------------------------\n");
    printf("Enter client first name: ");
    scanf(" %[^\n]%*c", s_client.c_name.first);
    CHECK(s_client.c_name.first)
    printf("Enter client last name: ");
    scanf(" %[^\n]%*c", s_client.c_name.last);
    CHECK(s_client.c_name.last)
    printf("Enter client age: ");
    scanf(" %[^\n]%*c", s_client.age);
    CHECK(s_client.age)
    printf("Enter client phone number: ");
    scanf(" %[^\n]%*c", s_client.phone);
    CHECK(s_client.phone)
    printf("Enter client item name: ");
    scanf(" %[^\n]%*c", s_client.c_items.name);
    CHECK(s_client.c_items.name)
    printf("Enter client item quantity: ");
    scanf(" %[^\n]%*c", s_client.c_items.q);
    CHECK(s_client.c_items.q)
    printf("\n------------------------------------------\n");
    printf("------------------------------------------\n");
    printf("%-15s%s %s\n", "Name", s_client.c_name.first, s_client.c_name.last);
    printf("%-15s%s\n", "Age", s_client.age);
    printf("%-15s%s\n", "Phone", s_client.phone);
    printf("%-15s%s\n", "item", s_client.c_items.name);
    printf("%-15s%s\n", "quantity", s_client.c_items.q);
    printf("\n------------------------------------------\n");
    printf("------------------------------------------\n");
    printf("save client data(Y/N): ");
    scanf(" %c", &c);
    if (c == 'n' || c == 'N')
    {
        B:
        s_client = clean_client;
        printf("client data ignored.\n\n");
        return 0;
    }
    else if (c == 'y' || c == 'Y')
    {
        fptr = fopen("data/safe.txt", "w");
        if(fptr == NULL)
        {
            /* File not created hence exit */
            printf("Unable to create file.\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            /* Write data to file */
            fprintf(fptr, "First name: %s\nlast name: %s\nAge: %s\nPhone number: %s\nItem: %s\nItem quantity: %s", \
                    s_client.c_name.first, s_client.c_name.last, s_client.age, s_client.phone, s_client.c_items.name, \
                    s_client.c_items.q);
            /* Close file to save file data */
            fclose(fptr);
            printf("new client added successfully.\n\n");
            return 1;
        }
    }
    return 2;
}

/*****************************************************************************
 * delete_client:                                                            *
 *                                                                           *
 *****************************************************************************/
void delete_client (void)
{

}

/*****************************************************************************
 * show_d:                                                                   *
 *                                                                           *
 *****************************************************************************/
void show_d (void)
{

}

/*****************************************************************************
 * list_d:                                                                   *
 *                                                                           *
 *****************************************************************************/
void list_d (void)
{

}

/*****************************************************************************
 * logout:                                                                   *
 *                                                                           *
 *****************************************************************************/
void logout (void)
{
    for(int i=0; i<=10; i++)
    {
        entered_user[i] = '\0';
        entered_pass[i] = '\0';
    }
    user_check = 0;
}
