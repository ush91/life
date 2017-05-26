TARGET_EXEC = life

BUILD_DIR = ./build
SRC_DIR = ./src

SRCS = $(shell find $(SRC_DIR) -name *.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

TEST_DIR = ./test
TEST_SRC = $(shell find $(SRC_DIR) -name *.cpp -and ! -name main.cpp)
TEST_OBJ = $(TEST_SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

CXX = clang++
CXXFLAGS = -std=c++11 -Wall -Wno-deprecated-declarations
FRAMEWORK = -framework OpenGL -framework GLUT

MKDIR_P = mkdir -p

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(FRAMEWORK) -o $@ $(OBJS)


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

## test
test: $(TEST_OBJ) $(BUILD_DIR)/test.o
	$(CXX) $(FRAMEWORK) -o $(BUILD_DIR)/$@ $^

$(BUILD_DIR)/test.o: $(TEST_DIR)/test.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)
