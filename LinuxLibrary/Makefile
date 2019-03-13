#自定义变量
CC		= g++
MAKE	= make
#静态链接选项，-g生成调试信息、-I指定头文件搜索路径，-L指定库文件搜索路径、-l静态库名、-static不共享
LDAFLAG	= -g -I./lib -L./lib -lstaticmath -static
#动态编译选项,-g生成调试信息、-I指定头文件搜索路径，-L指定库文件搜索路径、-l动态库名
LDSOFLAG= -g -I./lib -L./lib -ldynamicmath
#显式链接选项，-ldl显式加载动态库的动态函数库
LDEXFLAG= -g -ldl

SRCIMP	= implicit.cpp
SRCEXP	= explicit.cpp
INCLUDE	= ./lib
LIBA	= $(INCLUDE)/libstaticmath.a
LIBSO	= $(INCLUDE)/libdynamicmath.so

RM		= rm -f

#默认任务
default:
#默认任务要执行的命令，按上面的变量名替换为变量值后执行
	$(MAKE) testa
	$(MAKE) testso
	$(MAKE) testexp

#模式匹配,冒号前者为目标项，冒号后面为依赖项
testa: $(LIBA) $(SRCIMP)
	$(CC) $(SRCIMP) $(LDAFLAG) -o $@
#如果执行报错，提示找不到动态库，需要添加环境变量export LD_LIBRARY_PATH=`pwd`/lib
testso: $(LIBSO) $(SRCIMP)
	$(CC) $(SRCIMP) $(LDSOFLAG) -o $@

testexp: $(LIBSO) $(SRCEXP)
	$(CC) $(SRCEXP) $(LDEXFLAG) -o $@
#make -C后跟目标目录，读取目标目录下的Makefile
$(LIBA): $(INCLUDE)
	$(MAKE) -C $(INCLUDE) liba

$(LIBSO): $(INCLUDE)
	$(MAKE) -C $(INCLUDE) libso
#伪目标，声明clean为伪目标或标签，为了避免该清理任务与文件名相同而被错识别
.PHONY: clean
clean:
#清理之前的目标文件，以便下次完整的重新编译
	$(RM) testa testso testexp
	$(MAKE) -C $(INCLUDE) clean