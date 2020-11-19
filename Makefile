#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

PROJECT_NAME := camera_web_server

SOLUTION_PATH ?= $(abspath $(shell pwd))/../../..
EXTRA_COMPONENT_DIRS = $(IDF_PATH)/examples/common_components/protocol_examples_common

include $(SOLUTION_PATH)/components/component_conf.mk
include $(IDF_PATH)/make/project.mk

# Create a SPIFFS image from the contents of the 'spiffs_image' directory
# that fits the partition named 'storage'. FLASH_IN_PROJECT indicates that
# the generated image should be flashed when the entire project is flashed to
# the target with 'make flash'.
#SPIFFS_IMAGE_FLASH_IN_PROJECT := 1
#下面这一行是打开模拟片上文件路径
#$(eval $(call spiffs_create_partition_image,storage,weatherlog,FLASH_IN_PROJECT))

#$(eval $(call spiffs_create_partition_image,storage1,weatherlog,FLASH_IN_PROJECT))
#$(eval $(call spiffs_create_partition_image,storage,spiffs_image,FLASH_IN_PROJECT))
