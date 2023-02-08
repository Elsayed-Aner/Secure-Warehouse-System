#include <stdio.h>
#include "fun.h"

char user_1[] = "Elsayed\0";
char pass_1[] = "1234\0";
char entered_user[10];
char entered_pass[10];
int user_check = 0;

/*****************************************************************************
 * scan_f:                                                                   *
 *                                                                           *
 *****************************************************************************/
int scan_f (char *c)
{
    scanf(" %[^\n]%*c", c);
    return assess(c);
}

/*****************************************************************************
 * assess: return list: 0-> wrong command.                                   *
 *                      1-> clear(cls).                                      *
 *                      n-> new client(n|N).                                 *
 *                      x-> exit(exit|EXIT).                                 *
 *                      l-> list(lst).                                       *
 *                      h-> help(h|H).                                       *
 *****************************************************************************/
int assess (char *c)
{
    int i=0;
    char *p = c;
    while (*p++ != '\0'){
        i++;
        if (*p == ' ')
        {
            printf("\'%s\' is not recognized as an internal or external command!\n\n", p-i);
            return 0;
        }
    }
    switch (c[0]){

        // 1. cls: clear.
        case 'c':
            for(int i=1; i<=3; i++)
            {
                if ("cls\0"[i] != c[i])
                {
                    printf("\'%s\' is not recognized as an internal or external command!\n\n", c);
                    return 0;
                }
            }
            return 1;

        // 2. n&N: new client.
        case 'n': case 'N':
            return 'n';

        // 3. exit: exit program.
        case 'e': case 'E':
            for(int i=1; i<=4; i++)
            {
                if ("exit\0"[i] != c[i])
                {
                    printf("\'%s\' is not recognized as an internal or external command!\n\n", c);
                    return 0;
                }
            }
            return 'x';

        // 4. lst: list all client.
        case 'l': case 'L':
            for(int i=1; i<=3; i++)
            {
                if ("lst\0"[i] != c[i])
                {
                    printf("\'%s\' is not recognized as an internal or external command!\n\n", c);
                    return 'l';
                }
            }
            return 'l';

        // 5. d&D: delete client.
        case 'd': case 'D':
            return 'd';

        // 6. h|H: help.
        case 'h': case 'H':
            return 'h';
        // 7. out: logout user.
        case 'o':
            for(int i=1; i<=3; i++)
            {
                if ("user\0"[i] != c[i])
                {
                    printf("\'%s\' is not recognized as an internal or external command!\n\n", c);
                    return 'l';
                }
            }
            return 'o';
        // wrong command.
        default:
            printf("\'%s\' is not recognized as an internal or external command!\n\n", c);
            return 0;
        }
    return 0xff;
}

/*****************************************************************************
 * check_user:                                                               *
 *                                                                           *
 *****************************************************************************/
 int check_user (void)
 {
     if (user_check == 0)
     {
         printf("\n------------------------------------------\n");
         printf("checking credential required...\n");
         A:
         printf("Enter user name: ");
         scanf(" %[^\n]%*c", entered_user);
         CHECK_U(entered_user)
         printf("Enter password: ");
         scanf(" %[^\n]%*c", entered_pass);
         CHECK_U(entered_pass)
         for(int i = 0; entered_user[i] != '\0'; i++)
            {
                if (entered_user[i] != user_1[i])
                {
                    printf("incorrect user name or password!\n\n");
                    goto A;
                }
            }
         for(int i = 0; entered_pass[i] != '\0'; i++)
            {
                if (entered_pass[i] != pass_1[i])
                {
                    printf("incorrect user name or password!\n\n");
                    goto A;
                }
            }
            printf("access granted...\n");
     printf("welcome Mr.%s\n", user_1);
     user_check = 1;
     }
     else
        user_check = 1;
     return user_check;
 }
