CC = cl.exe
INCLUDES = includes
SRC_FILES = src/utils.c \
			src/base16.c \
			src/base32.c \
			src/base64.c

OBJ_FILES = utils.obj base16.obj base64.obj base32.obj

build:
	$(CC) /c /TC /I $(INCLUDES) $(SRC_FILES)
	lib.exe $(OBJ_FILES) /MACHINE:x64 /OUT:cbl_x64.lib
	move cbl_x64.lib lib

all: build
	del $(OBJ_FILES)