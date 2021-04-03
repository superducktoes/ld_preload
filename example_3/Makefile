TARGET = example_3

all: main.c
	@gcc main.c -o ${TARGET}
run:
	@./${TARGET}

readelf:
	readelf -h ./{$TARGET}
ldd:
	ldd ./${TARGET}
strace:
	strace ./${TARGET}
clean:
	rm -f *~
