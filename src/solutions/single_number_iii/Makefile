CXXFLAGS += -std=c++11 -stdlib=libc++

EXE    = a.out
CLASS  = $(patsubst %.java,%.class, $(wildcard *.java))
PYTHON = $(wildcard *.py)

all: $(EXE) $(CLASS)

$(EXE): $(wildcard *.cpp)
	$(CXX) $(CXXFLAGS) $<

%.class: %.java
	javac $<

run: $(EXE) $(CLASS) $(PYTHON) input.txt
	./$(EXE) < input.txt
	java $(basename $(CLASS)) < input.txt
	./$(PYTHON) < input.txt

clean:
	rm -f $(EXE) $(CLASS)
