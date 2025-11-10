OBJ_DIR = build
SRC_DIR = src

CFLAGS = -MMD -MP #used for auto creation of dependencies so that if there is a change in a header file then we do not need to recompile everything

sources = $(wildcard $(SRC_DIR)/*.c)
objects = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(sources))

app: $(objects) 
	gcc -o app $^

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR) # we do | so that there is a prerequisite so that a build dir is build 
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d app.exe

rebuild: clean app

run: app
	./app

install: app
	mkdir -p bin
	cp app bin/app

.PHONY: all clean rebuild run #tells make that all these targets are for commands so that if a file named clean or rebuild exits it does not mistake it for the target

# @ is used so that a command is not shown in terminal