#include <stdio.h>
#include <stdlib.h>

#include "api.h"
#include "fun.h"

#define COM_LEN 10 /** maximum command length.**/

extern int user_check;

int main()
{
    char p_command[COM_LEN+1];
    unsigned short int k;
    system("color E");
    clear_c();
    A:
    printf("Enter command (h: help): ");
    k = scan_f(p_command);
    while (1){
        switch (k){
        // wrong command.
        case 0:
            goto A;
        // clear command (cls).
        case 1:
            clear_c();
            goto A;
            break;
        // new client (n|N).
        case 'n':
            check_user();
            if(user_check)
            {
                add_client();
            }
            printf("\n");
            goto A;
        // delete client (d|D).
        case 'd':
            check_user();
            while(user_check)
            {

            }
            break;
        // list all client (lst).
        case 'l':
            logout();
            break;
        // exit command (exit).
        case 'x':
            return 0xff;
        // list all command (h|H).
        case 'h':
            printf("------------------------------------\n");
            printf("%-5s -->clear command window\n", "cls");
            printf("%-5s -->list all available command\n", "lst");
            printf("%-5s -->add new client\n", "n,N");
            printf("%-5s -->delete a client\n", "d,D");
            printf("%-5s -->return to main command\n", "cancel");
            printf("%-5s -->exit program\n", "exit");
            printf("------------------------------------\n\n");
            goto A;
        case 'o':
            break;
        default:
            return 0x01;
        }
    }
    return 0;
}
