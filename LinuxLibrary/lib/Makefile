#自定义变量
CC		= g++
AR		= ar
MAKE	= make
#静态库编译选项，-Wall生成所有警告、-O0不优化、-std=c++11采用c++11标准、-g输出调试信息、-c只编译汇编不链接
CAFLAGS	= -Wall -O0 -std=c++11 -g -c
#动态库编译选项，-fPIC(Position Independent Code)、-shared生成共享目标文件
CSOFLAGS= -fPIC -shared -g
#打包选项，-c创建一个库，-r在库中加入或替换成员文件， -v显示操作的附加信息
ARFLAGS	= -crv

#wildcard为Makefile模式匹配关键字，获取目标目录符合匹配模式的所有文件名
LIBSRCS	= $(wildcard ./*.cpp)
#patsubst为Makefile模式替换关键字，查找字符串SRCS中按空格分开的单词，并将符合模式%.cpp的字符串全部替换成%.o
LIBOBJS	= $(patsubst ./%.cpp, ./%.o, $(LIBSRCS))
LIBA	= libstaticmath.a
LIBSO	= libdynamicmath.so

RM		= rm -f

#默认任务
default:
#默认任务要执行的命令，按上面的变量名替换为变量值后执行
	$(MAKE) liba
	$(MAKE) libso

#模式匹配,冒号前者为目标项，冒号后面为依赖项
liba: $(LIBOBJS)
	$(AR) $(ARFLAGS) $(LIBA) $(LIBOBJS)

libso: $(LIBSRCS)
	$(CC) $(CSOFLAGS) $(LIBSRCS) -o $(LIBSO)

# %模式自动匹配符
%.obj: %.cpp
# $<表示规则中的第一个依赖项、$@表示规则中的目标项
	$(CC) $(CAFLAGS) $< -o $@

#伪目标，声明clean为伪目标或标签，为了避免该清理任务与文件名相同而被错识别
.PHONY: clean
clean:
#清理之前的目标文件，以便下次完整的重新编译
	$(RM) $(LIBOBJS) $(LIBA) $(LIBSO)