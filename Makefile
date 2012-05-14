# Makefile 

TOPDIR := $(shell pwd)

#ifeq   ($(PREFIX),"")
ifeq ($(strip $(PREFIX)),)

	TARGET_PATH=$(TOPDIR)
else
	TARGET_PATH=$(PREFIX)
endif

CPPFLAGS= -I$(TOPDIR)/src/logger 
LDFLAGS= -L/usr/lib -Wl,-rpath -L$(TOPDIR)/src/logger
LIBS= 

# The target programs to build
TARGETS= \
	Logger


# The target programs to build
INSTALL_TARGETS= \
	Logger_Install


# Build all targets
all: $(TARGETS)

# Build all targets
install: $(INSTALL_TARGETS)

# Clean all files, including C++ generated from IDL
clean:
	rm -f $(TOPDIR)/src/*.o
	rm -f $(TOPDIR)/*.a


Logger:
	cd $(TOPDIR)/src; \
        /usr/bin/g++ $(CPPFLAGS) -c LogService.cpp -o LogService.o; \
	ar cr $(TOPDIR)/liblogger.a $(TOPDIR)/src/LogService.o; \
	cd $(TOPDIR); \
        ranlib liblogger.a;

Logger_Install:
	mkdir -p $(TARGET_PATH)/lib; \
	mkdir -p $(TARGET_PATH)/include; \
	cp $(TOPDIR)/src/LogService.h $(TARGET_PATH)/include; \
	cp $(TOPDIR)/src/LogService.h /usr/include; \
        cp $(TOPDIR)/conf/log4cpp.conf /etc; \
        cp liblogger.a $(TARGET_PATH)/lib ;\
        cp liblogger.a /lib

