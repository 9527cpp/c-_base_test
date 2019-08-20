SUBDIRS=$(shell dir /ad/b)
CUR_SOURCE=${wildcard *.c}
CUR_OBJS=${patsubst %.c, %.obj, $(CUR_SOURCE)}
all:$(SUBDIRS) $(CUR_OBJS)
$(SUBDIRS):ECHO
	make -C $@
$(CUR_OBJS):%.obj:%.c
	$(GCC) -c $^ /Fo$(ROOT_DIR)\$(OBJS_DIR)\$@
ECHO:
	@echo $(SUBDIRS)
