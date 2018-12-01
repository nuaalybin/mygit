SRCS = $(wildcard ./platmain/source/*.c ../lib/*.c)    #wildcard把 指定目录 ./ 和 ../lib 下的所有后缀是c的文件全部展开。

OBJS = $(SRCS:.c = .o)    #OBJS将$(SRCS)下的.c文件转化为.o文件

CC = gcc   #代表所使用的编译器

INCLUDES = -I../include    #头文件查找路径
INCLUDES += -I./include 

LINKLIBS = -L../lib   #链接库查找地址

LIBS = -lpthread
LIBS +=-lsqlite3

CCFLAGS = -g -Wall -O0   #附加参数

OUTPUT = plat.out   #输出程序名称

all:$(OUTPUT)
	echo "compling ${OUTPUT}"
$(OUTPUT) : $(OBJS)
	$(CC) $^ -o $@ $(INCLUDES) $(LIBS) $(LINKLIBS)

%.o : %.c
	$(CC) -c $< $(CCFLAGS)

clean:
	rm -rf *.out *.o    #清除中间文件及生成文件

.PHONY:clean