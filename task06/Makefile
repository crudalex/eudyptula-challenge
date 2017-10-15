#kerneldir   :=    /lib/modules/$(shell uname -r)/build
kerneldir   :=    /usr/src/kernels/3.10.0-693.2.2.el7.x86_64
pwd         :=    $(shell pwd)
obj-m       :=    eudyptula.o

modules:
	make -C $(kerneldir) M=$(pwd) modules

clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions modules.order Module.symvers
