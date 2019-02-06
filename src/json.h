/* Library to create simple json object  
 * 
 * This library can be used for free. Feel free to use, modify and distribute
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

