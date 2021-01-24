/**
 *
 * @FILE        	: JSON.C 
 * @DESCRIPTION 	: LIBRARY TO CREATE SIMPLE JSON OBJECT
 *
 * @AUTHOR      	: VIKI (A) VIGNESH NATARAJAN
 * @CONTACT         : VIKILABS.ORG
 *
 */

/*
    Copyright (c) 2016 Viki( Vignesh Natarajan )

    Contact @ vikilabs.org

    Permission is hereby granted, free of charge, to any person obtaining
    a copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the Software
    is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
    OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "json.h"

char *json_object_create()
{
    char *json_obj_str = "{}";
    int len = strlen(json_obj_str) + 1;
    char *json_object = (char*) calloc(len + SAFETY_BUFFER, sizeof(char));

    if(!json_object){
        return NULL;
    }

    strcpy(json_object, json_obj_str);
    return json_object;
}

int8_t json_free(char *object)
{
    if(object){
        free(object);
    }

    return 0;
}

char *json_array_create()
{
    char *json_arr_str = "[]";
    int len = strlen(json_arr_str) + 1;
    char *json_array = (char*) calloc(len + SAFETY_BUFFER, sizeof(char));

    if(!json_array){
        return NULL;
    }

    strcpy(json_array, json_arr_str);
    return json_array;
}

int8_t json_object_append(char **object, char *key, char *value, json_value_t type)
{
    char value_quote[4];
    char *delimiter = ":";
    char *key_quote = "\"";
    char *new_object = NULL, *old_object = NULL;
    int len, i;
    uint8_t entry_exist = 0;
    

    if(!object){
        printf("[ error ] object null\n");
        return (-1);
    }

    /*create object of not created already*/
    if(!*object){
        *object = json_object_create();
    }

    old_object = *object;

    if(type == JSON_STRING)
    {
        strcpy(value_quote, "\"");
    }else{
        strcpy(value_quote, "");
    }

    len = strlen(old_object) + 
          strlen(key_quote) + strlen(key) + strlen(key_quote) + 
          strlen(delimiter) +
          strlen(value_quote) + strlen(value) + strlen(value_quote);

    new_object = (char *)calloc(len + SAFETY_BUFFER, sizeof(char));

    if(!new_object){
        printf("[error] object memory allocation\n");
        return -1;
    }
    
    len = strlen(old_object);

    /*Remove curly closing brace from old_object*/
    for(i=(len-1); i>=0; i--){
        if(old_object[i] == '}'){
           old_object[i] = '\0';
            break;
        }
    }

    len = strlen(old_object);
    /*Search for existing entry*/
    for(i=0; i<len; i++){
        if(old_object[i] == ':'){
            entry_exist = 1;
            break;
        }
    }


    strcpy(new_object, old_object);

    if(entry_exist){ /* Append key value after inserting comma */
        strcat(new_object, ",");
    }

    strcat(new_object, key_quote);
    strcat(new_object, key);
    strcat(new_object, key_quote);
    strcat(new_object, delimiter);
    strcat(new_object, value_quote);
    strcat(new_object, value);
    strcat(new_object, value_quote);
    strcat(new_object, "}"); /*close object*/

    free(old_object);
    *object = new_object;
    return 0;

}

/* value : string
 *
 * type  : one among the following
 *          - JSON_STRING
 *          - JSON_NUM
 *          - JSON_BOOL
 *          - JSON_OBJECT
 *          - JSON_NULL
 */
int8_t json_array_append(char **array, char *value, json_value_t type)
{
    char value_quote[4];
    char *new_array = NULL, *old_array = NULL;
    int len, i;
    uint8_t entry_exist = 0; 

    if(!array){
        printf("[ error ] array null\n");
        return (-1);
    }

    /*create object of not created already*/
    if(!*array){
        *array = json_array_create();
    }


    old_array = *array;

    if(type == JSON_STRING)
    {
        strcpy(value_quote, "\"");
    }else{
        strcpy(value_quote, "");
    }

    len = strlen(old_array) + 
          strlen(value_quote) + strlen(value) + strlen(value_quote);

    new_array = (char *)calloc(len + SAFETY_BUFFER, sizeof(char));

    if(!new_array){
        printf("[error] array memory allocation\n");
        return -1;
    }
    
    len = strlen(old_array);

    /*Remove  closing square braket from old_array*/
    for(i=(len-1); i>=0; i--){
        if(old_array[i] == ']'){
           old_array[i] = '\0';
            break;
        }
    }

    len = strlen(old_array);
    /*Search for existing entry*/
    for(i=0; i<len; i++){
        if((old_array[i] != '[') &&
           (old_array[i] != ']') &&
           (old_array[i] != ' ')){
            entry_exist = 1;
            break;
        }
    }


    strcpy(new_array, old_array);

    if(entry_exist){ /* append a comma before copying value*/
        strcat(new_array, ",");
    }
    strcat(new_array, value_quote);
    strcat(new_array, value);
    strcat(new_array, value_quote);
    strcat(new_array, "]"); /*close array*/

    free(old_array);
    *array = new_array;
    return 0;

}


