CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iincludes
LDFLAGS =

PROGRAM_NAME = T9
TARGET = $(PROGRAM_NAME).x
MAIN = main

SRC_DIR = src
INC_DIR = includes
TXT_DIR = txt

WORDS = sample_words.txt
KEYS = keys.txt

SRC = $(MAIN).cpp \
      $(SRC_DIR)/T9_Trie.cpp \
      $(SRC_DIR)/MapNode.cpp \
      $(SRC_DIR)/ArrayNode.cpp \
      $(SRC_DIR)/Program.cpp \
      $(SRC_DIR)/KeyPad.cpp

OBJ = $(SRC:.cpp=.o)


all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -DPROGRAM_NAME=$(TARGET)

run: $(TARGET)
	./$(TARGET) $(TXT_DIR)/$(WORDS) $(TXT_DIR)/$(KEYS)

clean:
	rm -f $(OBJ) $(TARGET) $(PROGRAM_NAME).tar.gz

tar:
	tar -czvf $(PROGRAM_NAME).tar.gz \
	    --exclude="*.o" \
	    --exclude=".DS_Store" \
	    --exclude="$(TARGET)" \
	    $(SRC_DIR) $(INC_DIR) $(TXT_DIR) $(MAIN).cpp Makefile README.md

rebuild: clean all