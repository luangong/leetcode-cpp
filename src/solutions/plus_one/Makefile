CXXFLAGS = -std=c++11
SOURCE = $(wildcard *.cpp)
TARGET = a.out

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE)

run: $(TARGET) input.txt
	./$(TARGET) < input.txt

clean:
	rm -f $(TARGET)
