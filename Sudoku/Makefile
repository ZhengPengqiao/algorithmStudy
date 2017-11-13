CC = gcc
CXX = g++
# 可执行文件
TARGET = sudoku
# C文件
SRCS = sudoku.cpp
# 目标文件
OBJS = $(SRCS:.cpp=.o)
# 库文件
DLIBS = 
# 链接为可执行文件
$(TARGET):$(OBJS)
	$(CC) -o $@ $^ $(DLIBS)  
clean:
	rm -rf $(TARGET) $(OBJS)
# 编译规则 $@代表目标文件 $< 代表第一个依赖文件
%.o:%.cpp
	$(CXX) -o $@ -c $<

# 编译规则 $@代表目标文件 $< 代表第一个依赖文件
%.o:%.c
	$(CC) -o $@ -c $<