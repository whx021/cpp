CXX = g++
TARGET = a.out
OBJS = 
CXXFLAGS = -c -Wall

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^

%.o: %.c
	$(CXX) $(CXXFLAGS) $< -o $@

.PYONE: clean
clean:
	rm -f *.o $(TARGET)