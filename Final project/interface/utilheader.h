// PATH: FINAL PROJECT/INTERFACE/UTILHEADER.H

#ifndef UTILHEADER_H
#define UTILHEADER_H

// INCLUDE USER DEFINED HEADER FILES
#include "../brain/master_header.h"
#include "menu.h"
#include "signup.h"
#include "login.h"
#include "update_password.h"
#include "update_username.h"

// INCLUDE BUILTIN LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// DEFINE
#define ADRESS "C:/Users/Abuzar/Documents/C Programs/Final project/system_user/"
// STRUCT BODY DECLARATION
struct user
{
    char name[100];
    char email[100];
    char username[100];
    char mob_num[100];
    char password[100];
    char c_pass[100];
};

#endif