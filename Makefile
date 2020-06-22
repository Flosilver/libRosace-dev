LIB_NAME := libRosace
NEW_LIB := libRosace.a
#TEST := test_catch

# code
SRC_DIR := src
OBJ_DIR := obj
INCLUDE_DIR := include
#INC_F_DIR := rosace

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(patsubst %.cpp, %.o, $(SRC))))
INCS := $(wildcard $(INCLUDE_DIR)/*.hpp)


# tests
#TEST_DIR := unit_test
#TEST_OBJ_DIR := obj_test

#SRC_TEST := $(wildcard $(TEST_DIR)/*.cpp)
#OBJ_TEST := $(addprefix $(TEST_OBJ_DIR)/, $(notdir $(patsubst %.cpp, %.o, $(SRC_TEST)))) #$(addprefix $(TEST_OBJ_DIR)/, $(notdir $(patsubst %.cpp, %.o, $(SRC))))


# dependances
CC := g++
INCLUDE := -Iinclude -I/usr/local/include
CFLAGS := -g -Wall -std=c++11
LDFLAGS := 
LIB_PATH := -L/usr/local/lib
LIBS := -lenet		#-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

.PHONY: all clean mrproper remake

all: $(LIB_NAME)

# Executable
$(LIB_NAME): $(OBJ)
	ar -r $(NEW_LIB) $^
	ranlib $(NEW_LIB)
	sudo cp -i -u $(NEW_LIB) /usr/lib/
	sudo cp -i -u $(INCS) /usr/include/c++/7
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE) $(LIB_PATH) $(LIBS))
	
$(OBJ_DIR):
	mkdir $@

# Tests
#$(TEST): $(OBJ_TEST)
#	$(CC) $^ -o $@ $(LIBS) $(INCLUDE)

#$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(TEST_OBJ_DIR)
#	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

#$(TEST_OBJ_DIR):
#	mkdir $@


clean:
	rm -rf $(OBJ)
	
mrproper: clean
	rm -rf $(NEW_LIB)

remake: mrproper all
