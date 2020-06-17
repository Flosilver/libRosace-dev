#EXE := main
#TEST := test_catch

# code
SRC_DIR := src
OBJ_DIR := obj

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(patsubst %.cpp, %.o, $(SRC))))

# tests
#TEST_DIR := unit_test
#TEST_OBJ_DIR := obj_test

#SRC_TEST := $(wildcard $(TEST_DIR)/*.cpp)
#OBJ_TEST := $(addprefix $(TEST_OBJ_DIR)/, $(notdir $(patsubst %.cpp, %.o, $(SRC_TEST)))) #$(addprefix $(TEST_OBJ_DIR)/, $(notdir $(patsubst %.cpp, %.o, $(SRC))))


# dependances
CC := g++
INCLUDE := -Iinclude
CFLAGS := -g -Wall
LDFLAGS := 
LIBS := 		#-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

.PHONY: all clean mrproper remake

#all: $(EXE) 		#$(TEST)

# Executable
#$(EXE): $(OBJ)
#	$(CC) $^ -o $@ $(LIBS) $(INCLUDE)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)
	
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
	#rm -rf $(OBJ_TEST)
	
mrproper: clean
	rm -rf $(EXE) 
	#$(TEST)

remake: mrproper all
