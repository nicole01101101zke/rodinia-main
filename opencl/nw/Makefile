include ../../common/make.config

#Can be changed by `make TYPE=CPU`
TYPE = GPU

#Library
ifeq ($(TYPE),GPU)
	OPENCL_INC = /usr/local/cuda/include
	OPENCL_LIB = /usr/local/cuda/lib64
else
	OPENCL_INC = $(INTEL_OPENCL_INC)
	OPENCL_LIB = $(INTEL_OPENCL_LIB)
endif

#C compiler
CC = g++

CC_FLAGS = -g -O3 -Wall

EXE = nw.out

$(EXE): nw.c
	$(CC) ${KERNEL_DIM} $(CC_FLAGS) -o $(EXE) nw.c ../util/timing.c \
		-I$(OPENCL_INC) -L$(OPENCL_LIB) -lOpenCL \
		-I../util -DTIMING \
		-Wno-unused-result
run:
	./nw.out 8192 10 ./nw.cl -p 0 -d 0

clean:
	rm -f $(EXE)
