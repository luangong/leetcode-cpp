CXXFLAGS = -std=c++11
SOURCE = $(wildcard *.cpp)
TARGET = a.out

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE)

clean:
	rm -f $(TARGET)
