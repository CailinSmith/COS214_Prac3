CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRC = \
	TestingMain.cpp \
	ChatRoom.cpp \
	LogMessageCommand.cpp \
	SendMessageCommand.cpp \
	BroadcastCommand.cpp \
	User.cpp 

OBJS = $(SRC:.cpp=.o)

TARGET = demo


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET) *.gcov *.gcda *.gcno *.o

run: $(TARGET)
	./$(TARGET)

val: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

cov:
	$(MAKE) clean
	$(MAKE) CXXFLAGS="$(CXXFLAGS) --coverage" LDFLAGS="--coverage"
	./$(TARGET)
	gcov *.cpp