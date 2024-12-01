# Компилятор и флаги
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude
LDFLAGS = -Llib
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Пути
SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin
LIB_DIR = lib
ASSETS_DIR = assets


SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)
STATIC_LIB = $(LIB_DIR)/libgame.a
EXECUTABLE = $(BIN_DIR)/game.exe


all: $(EXECUTABLE)

$(EXECUTABLE): $(STATIC_LIB) $(BIN_DIR)/main.o
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(BIN_DIR)/main.o -o $@ $(LDFLAGS) -lgame $(LDLIBS)


$(STATIC_LIB): $(filter-out $(BIN_DIR)/main.o, $(OBJECTS))
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $^


$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	DEL /Q $(BIN_DIR)\*.o $(BIN_DIR)\*.exe $(LIB_DIR)\*.a
	RMDIR /S /Q $(BIN_DIR) $(LIB_DIR)


test: all
	$(EXECUTABLE)
