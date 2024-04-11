CC=g++

SRC_DIR=src
OBJ_DIR=target/obj
TARGET_DIR=target

SOURCES:=$(wildcard $(SRC_DIR)/*.cpp)

OBJECTS:=$(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

LIBS=`wx-config --libs`
FLAGS=`wx-config --cxxflags`

EXECUTABLE:=Calculator

ifndef VERBOSE
.SILENT:
endif

compile: config $(EXECUTABLE)

config:
	mkdir -p $(SRC_DIR)
	mkdir -p $(TARGET_DIR)
	mkdir -p $(OBJ_DIR)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(ARGS) $(OBJECTS) -o $(TARGET_DIR)/$(EXECUTABLE) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(ARGS) -c $< -o $@ $(FLAGS)

exec: compile
	./$(TARGET_DIR)/$(EXECUTABLE)

clean:
	rm -f $(OBJECTS) $(TARGET_DIR)/$(EXECUTABLE)
