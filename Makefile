CC := g++
PROJECT_DIR := .
SRC_DIR := $(PROJECT_DIR)/src
INC_DIR := $(PROJECT_DIR)/inc
BIN_DIR := $(PROJECT_DIR)/bin
OBJ_DIR := $(PROJECT_DIR)/obj
TEST_DIR := $(PROJECT_DIR)/test

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.cpp=.o)))

INC_FLAGS := -I$(INC_DIR)
CF_FLAGS := -std=c++14 -g -Wall

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if [ ! -d $(OBJ_DIR) ]; \
		then echo "mkdir -p $(OBJ_DIR)"; mkdir -p $(OBJ_DIR); \
		fi
	$(CC) $(CF_FLAGS) $^ $(INC_FLAGS) -c -o $@

a:$(OBJS)
	@if [ ! -d $(BIN_DIR) ]; \
		then echo "mkdir -p $(BIN_DIR)"; mkdir -p $(BIN_DIR); \
		fi
	$(CC) $(CF_FLAGS) $^ $(INC_FLAGS) -o $(BIN_DIR)/$@

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
