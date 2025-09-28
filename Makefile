CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRC = \
    User.cpp \
    TestingMain.cpp \
    SendMessageCommand.cpp \
    LogMessageCommand.cpp \
    Decorator.cpp \
    ChatRoom.cpp \
    Chataholic.cpp \
    BroadcastCommand.cpp \
    AnimalLover.cpp \
	DogWhisperer.cpp \
	VIPUser.cpp

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

coverage:
	$(MAKE) clean
	$(MAKE) CXXFLAGS="$(CXXFLAGS) --coverage" LDFLAGS="--coverage"
	./$(TARGET)
	gcov *.cpp