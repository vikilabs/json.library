CC = gcc
AR = ar 
MKDIR_P = mkdir -p
OBJ_DIR = ../lib
OBJECT = $(OBJ_DIR)/json.o
ARCHIVE= $(OBJ_DIR)/libjson.a
SO = $(OBJ_DIR)/libjson.so
OPTIONS = -Wall
OPTIONS = -DTRACES_VERIFICATION
OPTIONS += -DTRACES_VERIFICATION

SOURCE = json.c

#LIBS = -ldl
STRIP_SYMBOL = strip
#INCLUDE = -I../include

all:
	$(MKDIR_P) $(OBJ_DIR)
	#Create Object File
	$(CC) -c $(OPTIONS) $(SOURCE) -o$(OBJECT)

	#Create Static Library
	$(AR) rcs $(ARCHIVE) $(OBJECT)

	#Create Shared Library
	$(CC) -shared -fPIC $(SOURCE) -o $(SO)
	rm -rf $(OBJECT) 

clean:
	rm -rf $(OBJECT) 
	rm -rf $(SO) 
	rm -rf $(ARCHIVE) 
