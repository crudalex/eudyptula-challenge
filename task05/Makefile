kerneldir := /lib/modules/$(shell uname -r)/build
pwd       := $(shell pwd)
obj-m := hello.o

all:
	make -C $(kerneldir) M=$(pwd) modules

clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions modules.order Module.symvers
