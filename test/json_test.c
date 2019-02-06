#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "json.h"

void object_test1()
{
	char *expected_output = "{\"key1\":\"1\",\"key2\":2,\"key3\":null,\"key4\":false}";
    char *json_object = json_object_create();
    json_object_append(&json_object, "key1", "1", JSON_STRING);
    json_object_append(&json_object, "key2", "2", JSON_NUMBER);
    json_object_append(&json_object, "key3", "null", JSON_NULL);
    json_object_append(&json_object, "key4", "false", JSON_BOOL);

    printf("[ INFO ] JSON OBJ = %s\n", json_object);

	if(strcmp(json_object, expected_output) != 0){
		printf("[ FAILURE ] object_test1\n");
		exit(-1);
	}else{
		printf("[ SUCCESS ] object_test1\n");
	}

    json_free(json_object);
}

void array_test1()
{
	char *expected_output = "[1,\"2\",true,null,\"value5\"]";
    char *json_array = json_array_create();

    json_array_append(&json_array, "1", JSON_NUMBER);
    json_array_append(&json_array, "2", JSON_STRING);
    json_array_append(&json_array, "true", JSON_BOOL);
    json_array_append(&json_array, "null", JSON_NULL);
    json_array_append(&json_array, "value5", JSON_STRING);

    printf("[ INFO ] JSON ARR = %s\n", json_array);
	if(strcmp(json_array, expected_output) != 0){
		printf("[ FAILURE ] array_test1\n");
	}else{
		printf("[ SUCCESS ] array_test1\n");
	}


    json_free(json_array);
}

void test3()
{
	char *expected_output = "[{\"KEY1\":\"12456458\",\"KEY2\":\"Wed Feb  6 15:46:00 CET 2019\",\"KEY3\":22.1234,\"KEY4\":1.4444,\"array1\":[{\"key11\":\"sat\",\"key12\":1},{\"key22\":\"cat\",\"key33\":20}]},{\"KEY1\":\"1232155555444\",\"KEY2\":\"Wed Oct  10 15:46:00 CET 1000\",\"KEY3\":10.2344,\"KEY4\":11.2242,\"array2\":[{\"key11\":\"tom\",\"key12\":4},{\"key33\":\"jerry\",\"key44\":10}]}]";
    char *marr = NULL;
	char *arr1 = NULL;
	char *arr2 = NULL;
	char *obj1 = NULL;
	char *obj11 = NULL;
	char *obj12 = NULL;
	char *obj2 = NULL;
	char *obj21 = NULL;
	char *obj22 = NULL;

    json_object_append(&obj11, "key11", "sat", JSON_STRING);
    json_object_append(&obj11, "key12", "1", JSON_NUMBER);

	json_object_append(&obj12, "key22", "cat", JSON_STRING);
    json_object_append(&obj12, "key33", "20", JSON_NUMBER);

    json_object_append(&obj21, "key11", "tom", JSON_STRING);
    json_object_append(&obj21, "key12", "4", JSON_NUMBER);

	json_object_append(&obj22, "key33", "jerry", JSON_STRING);
    json_object_append(&obj22, "key44", "10", JSON_NUMBER);

    json_array_append(&arr1, obj11, JSON_OBJECT);
    json_array_append(&arr1, obj12, JSON_OBJECT);

    json_array_append(&arr2, obj21, JSON_OBJECT);
    json_array_append(&arr2, obj22, JSON_OBJECT);

    json_object_append(&obj1, "KEY1", "12456458", JSON_STRING);
    json_object_append(&obj1, "KEY2", "Wed Feb  6 15:46:00 CET 2019", JSON_STRING);
    json_object_append(&obj1, "KEY3", "22.1234", JSON_NUMBER);
    json_object_append(&obj1, "KEY4", "1.4444", JSON_NUMBER);
    json_object_append(&obj1, "array1", arr1, JSON_ARRAY);

    json_object_append(&obj2, "KEY1", "1232155555444", JSON_STRING);
    json_object_append(&obj2, "KEY2", "Wed Oct  10 15:46:00 CET 1000", JSON_STRING);
    json_object_append(&obj2, "KEY3", "10.2344", JSON_NUMBER);
    json_object_append(&obj2, "KEY4", "11.2242", JSON_NUMBER);
    json_object_append(&obj2, "array2", arr2, JSON_ARRAY);


    json_array_append(&marr, obj1, JSON_OBJECT);
    json_array_append(&marr, obj2, JSON_OBJECT);

    printf("[ INFO ] JSON ARR = %s\n", marr);
	
	if(strcmp(marr, expected_output) != 0){
		printf("[ FAILURE ] test3\n");
	}else{
		printf("[ SUCCESS ] test3\n");
	}

    json_free(marr);
    json_free(arr1);
    json_free(arr2);
    json_free(obj1);
    json_free(obj11);
    json_free(obj12);
    json_free(obj2);
    json_free(obj21);
    json_free(obj22);
}



int main()
{
    object_test1();
    array_test1();
	test3();
    return 0;
}

