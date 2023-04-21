#include "gender.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

char *gender_to_text(enum gender_t _gender)
{
    char *text = malloc(10);
    text[0] = '\0';

    switch (_gender)
    {
    case GENDER_MALE:
        strcpy(text, "male");
        break;
    case GENDER_FEMALE:
        strcpy(text, "female");
        break;
    default:
        strcpy(text, "None");
    }

    return text;
}