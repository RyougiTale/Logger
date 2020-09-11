CC = g++
LD = g++

SRCS = $(wildcard *.cpp)

OBJS = $(patsubst %cpp, %o, $(SRCS))

TARGET = test

.PHONY:all clean

all: $(TARGET)

# $@表示目标文件，$^表示所有依赖文件，$<表示第一个依赖文件
$(TARGET): $(OBJS)
	$(LD) -o $@ $^

%.o:%.cpp
	$(CC) -c $^ --std=c++17

clean:
	del -f $(OBJS) $(TARGET).exe