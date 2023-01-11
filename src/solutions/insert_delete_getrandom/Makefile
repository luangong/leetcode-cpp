CLASS = $(patsubst %,%.class, $(basename $(wildcard *.java)))
CXXFLAGS = -std=c++11
SOURCE = $(wildcard *.cpp)
TARGET = a.out

all: $(TARGET) $(CLASS)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE)

%.class: %.java
	javac $<

run: $(TARGET) $(CLASS) input.txt
	./$(TARGET) < input.txt
	java $(basename $(CLASS)) < input.txt

clean:
	rm -f $(TARGET)
	rm -f $(CLASS)
