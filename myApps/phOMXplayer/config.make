################################################################################
# CONFIGURE PROJECT MAKEFILE (optional)
#   This file is where we make project specific configurations.
################################################################################


# MAKEFILE_DEBUG=1

RPI = 3
#RPI = 1 # RPI=3

ifdef RPI
ifeq ($(RPI),3)
PLATFORM_ARCH=armv7l
else
IS_RASPBIAN=1
endif

GST_VERSION=1.0

TOOLCHAIN_ROOT=/mnt/LinuxData/Scripts/CrossRpi/rpi_toolchain-gcc6
RPI_ROOT=/opt/PiTopDevRootfs
#RPI_ROOT=/opt/Rpi0Rootfs
RPI_ROOT=/opt/Rpi3DevRootfs
endif

OS_RELEASE=$(shell cat $(RPI_ROOT)/etc/os-release | grep VERSION_ID= | sed "s/VERSION_ID\=\"\(.*\)\"/\1/" )
$(info OS_RELEASE=$(OS_RELEASE))

ifeq ($(OS_RELEASE),9)
PLATFORM_VARIANT=stretch
$(info PLATFORM_VARIANT=$(PLATFORM_VARIANT))
endif

################################################################################
# OF ROOT
#   The location of your root openFrameworks installation
#       (default) OF_ROOT = ../../openFrameworks
################################################################################
OF_ROOT = ../../openFrameworks
OF_ROOT=$(realpath OF_ROOT = ../../openFrameworks)
################################################################################
# PROJECT ROOT
#   The location of the project - a starting place for searching for files
#       (default) PROJECT_ROOT = . (this directory)
#
################################################################################
# PROJECT_ROOT = .

################################################################################
# PROJECT SPECIFIC CHECKS
#   This is a project defined section to create internal makefile flags to
#   conditionally enable or disable the addition of various features within
#   this makefile.  For instance, if you want to make changes based on whether
#   GTK is installed, one might test that here and create a variable to check.
################################################################################
# None
# OmxPlayer
PATH_TO_OMXPLAYER = omxplayer
$(info PATH_TO_OMXPLAYER=$(PATH_TO_OMXPLAYER))

$(shell $(PATH_TO_OMXPLAYER)/gen_version.sh > $(PATH_TO_OMXPLAYER)/version.h)
$(shell cat $(PATH_TO_OMXPLAYER)/README.md | awk '/SYNOPSIS/{p=1;print;next} p&&/KEY BINDINGS/{p=0};p' | sed -e '1,3 d' -e 's/^/"/' -e 's/$$/\\n"/' > $(PATH_TO_OMXPLAYER)/help.h)
$(shell cat $(PATH_TO_OMXPLAYER)/README.md | awk '/KEY BINDINGS/{p=1;print;next} p&&/KEY CONFIG/{p=0};p' $< | sed -e '1,3 d' -e 's/^/"/' -e 's/$$/\\n"/' > $(PATH_TO_OMXPLAYER)/keys.h)
$(shell if ( type $(PATH_TO_OMXPLAYER)/omxplayer.cpp) then mv -f $(PATH_TO_OMXPLAYER)/omxplayer.cpp $(PATH_TO_OMXPLAYER)/omxplayer.cppx; fi)

APPNAME = $(shell basename `pwd`)_$(PLATFORM_LIB_SUBPATH)
################################################################################
# PROJECT EXTERNAL SOURCE PATHS
#   These are fully qualified paths that are not within the PROJECT_ROOT folder.
#   Like source folders in the PROJECT_ROOT, these paths are subject to
#   exlclusion via the PROJECT_EXLCUSIONS list.
#
#     (default) PROJECT_EXTERNAL_SOURCE_PATHS = (blank)
#
#   Note: Leave a leading space when adding list items with the += operator
################################################################################
# PROJECT_EXTERNAL_SOURCE_PATHS =

################################################################################
# PROJECT EXCLUSIONS
#   These makefiles assume that all folders in your current project directory
#   and any listed in the PROJECT_EXTERNAL_SOURCH_PATHS are are valid locations
#   to look for source code. The any folders or files that match any of the
#   items in the PROJECT_EXCLUSIONS list below will be ignored.
#
#   Each item in the PROJECT_EXCLUSIONS list will be treated as a complete
#   string unless teh user adds a wildcard (%) operator to match subdirectories.
#   GNU make only allows one wildcard for matching.  The second wildcard (%) is
#   treated literally.
#
#      (default) PROJECT_EXCLUSIONS = (blank)
#
#		Will automatically exclude the following:
#
#			$(PROJECT_ROOT)/bin%
#			$(PROJECT_ROOT)/obj%
#			$(PROJECT_ROOT)/%.xcodeproj
#
#   Note: Leave a leading space when adding list items with the += operator
################################################################################
# PROJECT_EXCLUSIONS =
  PROJECT_EXCLUSIONS = $(PROJECT_ROOT)/src/omxplayer/ffmpeg_compiled/usr/local/include/libavutil%
 # PROJECT_EXCLUSIONS += $(PROJECT_ROOT)/src/omxplayer/omxplayer.%

################################################################################
# PROJECT LINKER FLAGS
#	These flags will be sent to the linker when compiling the executable.
#
#		(default) PROJECT_LDFLAGS = -Wl,-rpath=./libs
#
#   Note: Leave a leading space when adding list items with the += operator
#
# Currently, shared libraries that are needed are copied to the
# $(PROJECT_ROOT)/bin/libs directory.  The following LDFLAGS tell the linker to
# add a runtime path to search for those shared libraries, since they aren't
# incorporated directly into the final executable application binary.
################################################################################
# PROJECT_LDFLAGS=-Wl,-rpath=./libs

PROJECT_LDFLAGS += -ldbus-1
PROJECT_LDFLAGS += -L$(PROJECT_ROOT)/src/omxplayer/ffmpeg_compiled/usr/local/lib/
PROJECT_LDFLAGS += -lavcodec
PROJECT_LDFLAGS += -lavutil
PROJECT_LDFLAGS += -lavcodec
PROJECT_LDFLAGS += -lavformat
PROJECT_LDFLAGS += -lswscale
PROJECT_LDFLAGS += -lswresample
PROJECT_LDFLAGS += -lasound


################################################################################
# PROJECT DEFINES
#   Create a space-delimited list of DEFINES. The list will be converted into
#   CFLAGS with the "-D" flag later in the makefile.
#
#		(default) PROJECT_DEFINES = (blank)
#
#   Note: Leave a leading space when adding list items with the += operator
################################################################################
# PROJECT_DEFINES =

 #pragma message ("Using External (RPI-s) FFMpeg")
 PROJECT_DEFINES += HAVE_CMAKE_CONFIG
 PROJECT_DEFINES += __VIDEOCORE4__
 PROJECT_DEFINES += HAVE_OMXLIB
 PROJECT_DEFINES += USE_EXTERNAL_FFMPEG

 PROJECT_DEFINES += HAVE_LIBAVCODEC_AVCODEC_H
 PROJECT_DEFINES += HAVE_LIBAVUTIL_OPT_H
 PROJECT_DEFINES += HAVE_LIBAVUTIL_MEM_H
 PROJECT_DEFINES += HAVE_LIBAVUTIL_AVUTIL_H
 PROJECT_DEFINES += HAVE_LIBAVFORMAT_AVFORMAT_H
 PROJECT_DEFINES += HAVE_LIBAVFILTER_AVFILTER_H
 PROJECT_DEFINES += HAVE_LIBSWRESAMPLE_SWRESAMPLE_H

 PROJECT_DEFINES += _HAVE_SBRK
 PROJECT_DEFINES += HAVE_VMCS_CONFIG
 PROJECT_DEFINES += VCHI_BULK_ALIGN=1
 PROJECT_DEFINES +=

################################################################################
# PROJECT CFLAGS
#   This is a list of fully qualified CFLAGS required when compiling for this
#   project.  These CFLAGS will be used IN ADDITION TO the PLATFORM_CFLAGS
#   defined in your platform specific core configuration files. These flags are
#   presented to the compiler BEFORE the PROJECT_OPTIMIZATION_CFLAGS below.
#
#		(default) PROJECT_CFLAGS = (blank)
#
#   Note: Before adding PROJECT_CFLAGS, note that the PLATFORM_CFLAGS defined in
#   your platform specific configuration file will be applied by default and
#   further flags here may not be needed.
#
#   Note: Leave a leading space when adding list items with the += operator
################################################################################
# PROJECT_CFLAGS =

 # PROJECT_CFLAGS += -I$(PROJECT_ROOT)/src/omxplayer/
 # PROJECT_CFLAGS += -I$(PROJECT_ROOT)/src/omxplayer/linux
 # PROJECT_CFLAGS += -I$(PROJECT_ROOT)/src/omxplayer/ffmpeg_compiled/usr/local/include
 PROJECT_CFLAGS += -D__STDC_CONSTANT_MACROS \
-D__STDC_LIMIT_MACROS \
-DTARGET_POSIX -DTARGET_LINUX -fPIC -DPIC -D_REENTRANT \
-D_HAVE_SBRK -D_LARGEFILE64_SOURCE -DHAVE_CMAKE_CONFIG -DHAVE_VMCS_CONFIG \
-D_REENTRANT -DUSE_VCHIQ_ARM \
-DVCHI_BULK_ALIGN=1 -DVCHI_BULK_GRANULARITY=1 -DEGL_SERVER_DISPMANX -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE \
-D__VIDEOCORE4__ -DGRAPHICS_X_VG=1 -U_FORTIFY_SOURCE -Wall -DHAVE_OMXLIB -DUSE_EXTERNAL_FFMPEG  \
-DHAVE_LIBAVCODEC_AVCODEC_H -DHAVE_LIBAVUTIL_MEM_H -DHAVE_LIBAVUTIL_AVUTIL_H -DHAVE_LIBAVFORMAT_AVFORMAT_H \
-DHAVE_LIBAVFILTER_AVFILTER_H -DOMX -DOMX_SKIP64BIT
 PROJECT_CFLAGS += -I$(RPI_ROOT)/usr/include/dbus-1.0
 PROJECT_CFLAGS += -I$(RPI_ROOT)/usr/lib/arm-linux-gnueabihf/dbus-1.0/include
 PROJECT_CFLAGS += -Wno-deprecated-declarations

################################################################################
# PROJECT OPTIMIZATION CFLAGS
#   These are lists of CFLAGS that are target-specific.  While any flags could
#   be conditionally added, they are usually limited to optimization flags.
#   These flags are added BEFORE the PROJECT_CFLAGS.
#
#   PROJECT_OPTIMIZATION_CFLAGS_RELEASE flags are only applied to RELEASE targets.
#
#		(default) PROJECT_OPTIMIZATION_CFLAGS_RELEASE = (blank)
#
#   PROJECT_OPTIMIZATION_CFLAGS_DEBUG flags are only applied to DEBUG targets.
#
#		(default) PROJECT_OPTIMIZATION_CFLAGS_DEBUG = (blank)
#
#   Note: Before adding PROJECT_OPTIMIZATION_CFLAGS, please note that the
#   PLATFORM_OPTIMIZATION_CFLAGS defined in your platform specific configuration
#   file will be applied by default and further optimization flags here may not
#   be needed.
#
#   Note: Leave a leading space when adding list items with the += operator
################################################################################
# PROJECT_OPTIMIZATION_CFLAGS_RELEASE =
# PROJECT_OPTIMIZATION_CFLAGS_DEBUG =

################################################################################
# PROJECT COMPILERS
#   Custom compilers can be set for CC and CXX
#		(default) PROJECT_CXX = (blank)
#		(default) PROJECT_CC = (blank)
#   Note: Leave a leading space when adding list items with the += operator
################################################################################
# PROJECT_CXX =
# PROJECT_CC =
