#
# embedXcode
# ----------------------------------
# Embedded Computing on Xcode 4
#
# Created by Rei VILO 
# Copyright © 2012-2013 http://embedxcode.weebly.com
#
#

# Arduino specifics
# ----------------------------------
# Automatic 0023 or 1. selection based on version.txt
#
ifneq ($(shell grep 1. $(ARDUINO_PATH)/lib/version.txt),)
    include $(MAKEFILE_PATH)/Arduino1.mk	
else
    include $(MAKEFILE_PATH)/Arduino23.mk	
endif

