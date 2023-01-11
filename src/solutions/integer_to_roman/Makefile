CXXFLAGS = -std=c++11
SOURCE = $(wildcard *.cpp)
TARGET = a.out
CLASS = Solution.class

all: $(TARGET) $(CLASS)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE)

%.class: %.java
	javac $<

run: $(TARGET) input.txt
	./$(TARGET) < input.txt
	java Solution < input.txt

clean:
	rm -f $(TARGET) $(CLASS)
