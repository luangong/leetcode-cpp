GTEST_DIR = $(HOME)/Documents/Code/googletest
CXXFLAGS = \
    -std=c++11 -stdlib=libc++ \
    -DGTEST_HAS_PTHREAD=1 \
    -I$(GTEST_DIR)/googletest/include \
    -Wl,-L$(GTEST_DIR)/lib -lgtest -lgtest_main

EXE    = a.out
CLASS  = $(patsubst %.java,%.class, $(wildcard *.java))
PYTHON = $(wildcard *.py)

all: $(EXE) $(CLASS)

$(EXE): $(wildcard *.cpp)
	$(CXX) $(CXXFLAGS) $<

%.class: %.java
	javac $<

run: $(CLASS) $(PYTHON) input.txt
	java $(basename $(CLASS)) < input.txt
	./$(PYTHON) < input.txt

test: $(EXE)
	./$(EXE)

clean:
	rm -f $(EXE) $(CLASS)
