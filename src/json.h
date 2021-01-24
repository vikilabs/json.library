/**
 *
 * @FILE        	: JSON.H 
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

#ifndef JSON_H
#define JSON_H
/* Library to create simple json object  
 * 
 *                          Author  : Vignesh Natarajan (a) Viki
 *                          Contact : viki@vikilabs.org 
 */

/* JSON 
 *
 * Key   : Must be a string enclosed inside double quotes
 * 
 * Value : [ Can be one of the following ]
 *
 *              1. String
 *              2. Number
 *              3. Boolean
 *              4. Object
 *              5. Arrays
 *              6. NULL
 *
 * Array : [ Can be array of ]
 *
 *              1. String
 *              2. Number
 *              3. Boolean
 *              4. Object
 *              5. Arrays
 *              6. NULL
 *
 * Object Notation : { }    -> { Key1 : Value1, Key2 : Value 2 ....... }
 * Array Notation  : [ ]    -> [ Value1, Value2, Value3 ..... ]
 */

typedef enum{
    JSON_NUMBER=1,
    JSON_STRING,
    JSON_BOOL,
    JSON_ARRAY,
    JSON_OBJECT,
    JSON_NULL
}json_value_t;

/* Object will be allocated with the safety buffer
 * Reduce this value, if you are using a system with low memory 
 */
#define SAFETY_BUFFER 4

char *json_object_create();
/* Free the memory allocated for the object
 *
 * object: json_object or json_array
 */
int8_t json_free(char *object);
char *json_array_create();

/* value : string
 *
 * type  : one among the following
 *          - JSON_STRING
 *          - JSON_NUMBER
 *          - JSON_BOOL
 *          - JSON_OBJECT
 *          - JSON_NULL
 *          - JSON_ARRAU
 */

int8_t json_object_append(char **object, char *key, char *value, json_value_t type);

/* value : string
 *
 * type  : one among the following
 *          - JSON_STRING
 *          - JSON_NUMBER
 *          - JSON_BOOL
 *          - JSON_OBJECT
 *          - JSON_NULL
 *          - JSON_ARRAU
 */
int8_t json_array_append(char **array, char *value, json_value_t type);
#endif
