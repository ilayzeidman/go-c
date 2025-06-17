CC = gcc
AR = ar
PKG_CONFIG = pkg-config
CFLAGS = $(shell $(PKG_CONFIG) --cflags gstreamer-1.0)
LDFLAGS = $(shell $(PKG_CONFIG) --libs gstreamer-1.0)

all: libgstwrapper.a

libgstwrapper.a: gst_wrapper.o
	$(AR) rcs $@ $^

gst_wrapper.o: gst_wrapper.c gst_wrapper.h
	$(CC) -c gst_wrapper.c -o $@ $(CFLAGS)

test: libgstwrapper.a
	go test -v

clean:
	rm -f *.o *.a
