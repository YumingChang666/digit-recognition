# Set kernel name
KERNEL_NAME = DigitRec

# Set host source and headers
HOST_SRC_CPP = ./src/host/digit_recognition.c ./src/host/utils.c ./src/host/check_result.c
HOST_SRC_H   = ./src/host/utils.h ./src/host/check_result.h ./src/host/typedefs.h ./src/host/testing_data.h \
               ./src/host/training_data.h
DATA         = ./196data/*.dat

# Set host code include paths
HOST_INC =
HOST_LIB =

# Set kernel file
SW_KERNEL_SRC = ./src/sw/digitrec_sw.c
SW_KERNEL_H = ./src/host/typedefs.h ./src/sw/digitrec_sw.h

#-------------------------
# Leave the rest to harness
#-------------------------
include harness/harness.mk