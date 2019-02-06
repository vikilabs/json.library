CC = gcc
AR = ar 
OBJECT = json_test
OPTIONS = -Wall
OPTIONS = -DTRACES_VERIFICATION
OPTIONS += -DTRACES_VERIFICATION

SOURCE = json_test.c
SOURCE += ../src/json.c
INCLUDE = -I../src/

all:
	$(MKDIR_P) $(OBJ_DIR)
	#Create Object File
	$(CC) $(OPTIONS) $(SOURCE) $(INCLUDE) -o$(OBJECT)
	./$(OBJECT)
	rm -rf $(OBJECT)
