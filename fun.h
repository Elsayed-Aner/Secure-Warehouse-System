#ifndef FUN_H
#define FUN_H

#define CHECK_U(elemint) for(int i=0; i<=7; i++) \
            {                                    \
                if ("cancel\0"[i] != elemint[i]) \
                    break;                       \
                else if (i == 7)                 \
                return user_check;                         \
            }

/*****************************************************************************
 * scan_f:                                                                   *
 *                                                                           *
 *****************************************************************************/
int scan_f (char *c);

/*****************************************************************************
 * assess: return list: 0-> wrong command.                                   *
 *                      1-> clear(cls).                                      *
 *                      n-> new client(n|N).                                 *
 *                      x-> exit(exit|EXIT).                                 *
 *                      l-> list(lst).                                       *
 *                      h-> help(h|H).                                       *
 *****************************************************************************/
int assess (char *c);

/*****************************************************************************
 * check_user:                                                               *
 *                                                                           *
 *****************************************************************************/
 int check_user (void);

#endif // FUN_H
