#make命令不带参数的话只执行第一条规则

CC = gcc

INC_DIR := ./include
SRC_DIR := ./source
OBJ_DIR := ./obj
#SRC_LIST := $(wildcard $(SRC_DIR)/*.c)
#OBJ_LIST := $(subst $(SRC_DIR),$(OBJ_DIR),$(SRC_LIST:.c=.o))
CFLAGS = -g  -I$(INC_DIR)
DEPS_H =  $(INC_DIR)/Command.h

server_objs = $(OBJ_DIR)/service.o $(OBJ_DIR)/command.o
client_objs = $(OBJ_DIR)/client.o $(OBJ_DIR)/command.o

.PHONY : all clean print_var

all: service.out client.out
	
service.out: $(server_objs) 
	$(CC) -o $@ $^ $(CFLAGS)
	 
client.out: $(client_objs) 
	$(CC) -o $@ $^ $(CFLAGS)


$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(DEPS_H)
	@if [ ! -d $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi;
	$(CC) -o $@ -c $< $(CFLAGS)


clean :
	-rm $(OBJ_DIR)/*.o 
	-rm *.out

print_var :
	@echo "    INC_DIR:"    $(INC_DIR)
	@echo "    SRC_DIR:"    $(SRC_DIR)
	@echo "    OBJ_DIR:"    $(OBJ_DIR)
#	@echo "    SRC_LIST:"   $(SRC_LIST)
#	@echo "    OBJ_LIST:"   $(OBJ_LIST)
	@echo "    DEPS_H:"     $(DEPS_H)
	@echo "    CFLAGS:"     $(CFLAGS)

