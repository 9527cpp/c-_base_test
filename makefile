.PHONY	= clean
GCC		= cl.exe

INCLUDES	= -I.
CFLAGS		= $(INCLUDES) 
LDFLAGS		= 
#TARGET �����ڴ���
EXE			= $(TARGET).exe
SRCS		= $(TARGET).cpp
OBJS		= $(SRCS:%.cpp=%.obj)

$(EXE):$(OBJS)
	$(GCC)  $(CFLAGS)  -o $@ $^ $(LDFLAGS)
$(OBJS):%.obj:%.cpp
	$(GCC) $(CFLAGS) -d -c $< -o $@
clean:
	rm -rf $(OBJS) $(EXE)
