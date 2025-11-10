OBJ_DIR = build
SRC_DIR = src

sources = $(wildcard $(SRC_DIR)/*.c)
objects = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(sources))

app: $(objects) 
	gcc -o app $^

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR) # we do | so that there is a prerequisite so that a build dir is build 
	gcc -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o app.exe
