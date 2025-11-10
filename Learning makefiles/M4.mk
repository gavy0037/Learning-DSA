OBJ_DIR = build
SRC_DIR = src

CFLAGS = -MMD -MP #used for auto creation of dependencies

sources = $(wildcard $(SRC_DIR)/*.c)
objects = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(sources))

app: $(objects)
	gcc -o app $^

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR) # the prerequisites after | are the ones that need to exist for this rule but if they change then there is no need for recomplilation
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d app.exe

# @ is used to silence a command