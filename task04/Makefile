obj-m := coding_style.o
# obj-m := hello.o

kerneldir := /lib/modules/$(shell uname -r)/build
pwd       := $(shell pwd)

all:
	make -C $(kerneldir) M=$(pwd) modules

clean:
	make -C $(kerneldir) M=$(pwd) clean
