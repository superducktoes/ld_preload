TARGET = example_4

all: main.c
	@gcc main.c -o ${TARGET}
	@gcc -shared -fPIC inject.c -o inject.so
run:
	@LD_PRELOAD=./inject.so ./${TARGET}
readelf:
	readelf -h ./{$TARGET}
ldd:
	ldd ./${TARGET}
strace:
	strace ./${TARGET}
clean:
	rm -f *~
