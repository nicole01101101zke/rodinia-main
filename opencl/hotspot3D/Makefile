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

ifndef CC
	CC = gcc
endif

OUTPUT = *.txt
CCFLAGS=-O3 -lm 

LIBS = -lOpenCL 

hotspot3D.out: 3D.c CL_helper.c ../util/timing.c
	$(CC) $^ $(CCFLAGS) -I$(OPENCL_INC) -L$(OPENCL_LIB) $(LIBS) \
		-I../util -DTIMING \
		-o $@

run:
	./hotspot3D.out -n 512 -l 8 -i 500 -f ../../data/hotspot3D/power_512x8 ../../data/hotspot3D/temp_512x8 output.txt $@

clean:
	rm -f hotspot3D.out $(OUTPUT) 
