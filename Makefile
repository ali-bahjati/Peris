#############################################################################
# Makefile for building: SimpleDrawer
# Generated by qmake (2.01a) (Qt 4.8.2) on: Tue Aug 21 00:33:32 2012
# Project:  ./SimpleDrawer.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/lib64/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile ./SimpleDrawer.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/lib64/qt4/mkspecs/linux-g++ -I../SimpleDrawer -I/usr/include/QtCore -I/usr/include/QtGui -I/usr/include -I. -I. -I../SimpleDrawer -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib64 -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = 
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = ./main.cpp \
		./drawingform.cpp \
		./drawingarea.cpp \
		./scale.cpp moc_drawingform.cpp \
		moc_drawingarea.cpp
OBJECTS       = main.o \
		drawingform.o \
		drawingarea.o \
		scale.o \
		moc_drawingform.o \
		moc_drawingarea.o
DIST          = /usr/lib64/qt4/mkspecs/common/unix.conf \
		/usr/lib64/qt4/mkspecs/common/linux.conf \
		/usr/lib64/qt4/mkspecs/common/gcc-base.conf \
		/usr/lib64/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/lib64/qt4/mkspecs/common/g++-base.conf \
		/usr/lib64/qt4/mkspecs/common/g++-unix.conf \
		/usr/lib64/qt4/mkspecs/qconfig.pri \
		/usr/lib64/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/lib64/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/lib64/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt4/mkspecs/features/qt_config.prf \
		/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt4/mkspecs/features/default_pre.prf \
		/usr/lib64/qt4/mkspecs/features/debug.prf \
		/usr/lib64/qt4/mkspecs/features/default_post.prf \
		/usr/lib64/qt4/mkspecs/features/declarative_debug.prf \
		/usr/lib64/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/lib64/qt4/mkspecs/features/warn_on.prf \
		/usr/lib64/qt4/mkspecs/features/qt.prf \
		/usr/lib64/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt4/mkspecs/features/moc.prf \
		/usr/lib64/qt4/mkspecs/features/resources.prf \
		/usr/lib64/qt4/mkspecs/features/uic.prf \
		/usr/lib64/qt4/mkspecs/features/yacc.prf \
		/usr/lib64/qt4/mkspecs/features/lex.prf \
		/usr/lib64/qt4/mkspecs/features/include_source_dir.prf \
		./SimpleDrawer.pro
QMAKE_TARGET  = SimpleDrawer
DESTDIR       = 
TARGET        = SimpleDrawer

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_drawingform.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: ./SimpleDrawer.pro  /usr/lib64/qt4/mkspecs/linux-g++/qmake.conf /usr/lib64/qt4/mkspecs/common/unix.conf \
		/usr/lib64/qt4/mkspecs/common/linux.conf \
		/usr/lib64/qt4/mkspecs/common/gcc-base.conf \
		/usr/lib64/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/lib64/qt4/mkspecs/common/g++-base.conf \
		/usr/lib64/qt4/mkspecs/common/g++-unix.conf \
		/usr/lib64/qt4/mkspecs/qconfig.pri \
		/usr/lib64/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/lib64/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/lib64/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt4/mkspecs/features/qt_config.prf \
		/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt4/mkspecs/features/default_pre.prf \
		/usr/lib64/qt4/mkspecs/features/debug.prf \
		/usr/lib64/qt4/mkspecs/features/default_post.prf \
		/usr/lib64/qt4/mkspecs/features/declarative_debug.prf \
		/usr/lib64/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/lib64/qt4/mkspecs/features/warn_on.prf \
		/usr/lib64/qt4/mkspecs/features/qt.prf \
		/usr/lib64/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt4/mkspecs/features/moc.prf \
		/usr/lib64/qt4/mkspecs/features/resources.prf \
		/usr/lib64/qt4/mkspecs/features/uic.prf \
		/usr/lib64/qt4/mkspecs/features/yacc.prf \
		/usr/lib64/qt4/mkspecs/features/lex.prf \
		/usr/lib64/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib64/libQtGui.prl \
		/usr/lib64/libQtCore.prl
	$(QMAKE) -spec /usr/lib64/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile ./SimpleDrawer.pro
/usr/lib64/qt4/mkspecs/common/unix.conf:
/usr/lib64/qt4/mkspecs/common/linux.conf:
/usr/lib64/qt4/mkspecs/common/gcc-base.conf:
/usr/lib64/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/lib64/qt4/mkspecs/common/g++-base.conf:
/usr/lib64/qt4/mkspecs/common/g++-unix.conf:
/usr/lib64/qt4/mkspecs/qconfig.pri:
/usr/lib64/qt4/mkspecs/modules/qt_phonon.pri:
/usr/lib64/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/lib64/qt4/mkspecs/features/qt_functions.prf:
/usr/lib64/qt4/mkspecs/features/qt_config.prf:
/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf:
/usr/lib64/qt4/mkspecs/features/default_pre.prf:
/usr/lib64/qt4/mkspecs/features/debug.prf:
/usr/lib64/qt4/mkspecs/features/default_post.prf:
/usr/lib64/qt4/mkspecs/features/declarative_debug.prf:
/usr/lib64/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/lib64/qt4/mkspecs/features/warn_on.prf:
/usr/lib64/qt4/mkspecs/features/qt.prf:
/usr/lib64/qt4/mkspecs/features/unix/thread.prf:
/usr/lib64/qt4/mkspecs/features/moc.prf:
/usr/lib64/qt4/mkspecs/features/resources.prf:
/usr/lib64/qt4/mkspecs/features/uic.prf:
/usr/lib64/qt4/mkspecs/features/yacc.prf:
/usr/lib64/qt4/mkspecs/features/lex.prf:
/usr/lib64/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib64/libQtGui.prl:
/usr/lib64/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/lib64/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile ./SimpleDrawer.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/SimpleDrawer1.0.0 || $(MKDIR) .tmp/SimpleDrawer1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/SimpleDrawer1.0.0/ && $(COPY_FILE) --parents ./drawingform.h ./drawingarea.h ./scale.h .tmp/SimpleDrawer1.0.0/ && $(COPY_FILE) --parents ./main.cpp ./drawingform.cpp ./drawingarea.cpp ./scale.cpp .tmp/SimpleDrawer1.0.0/ && $(COPY_FILE) --parents ./drawingform.ui .tmp/SimpleDrawer1.0.0/ && (cd `dirname .tmp/SimpleDrawer1.0.0` && $(TAR) SimpleDrawer1.0.0.tar SimpleDrawer1.0.0 && $(COMPRESS) SimpleDrawer1.0.0.tar) && $(MOVE) `dirname .tmp/SimpleDrawer1.0.0`/SimpleDrawer1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/SimpleDrawer1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_drawingform.cpp moc_drawingarea.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_drawingform.cpp moc_drawingarea.cpp
moc_drawingform.cpp: ./drawingform.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) ./drawingform.h -o moc_drawingform.cpp

moc_drawingarea.cpp: ./scale.h \
		./drawingarea.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) ./drawingarea.h -o moc_drawingarea.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_drawingform.h
compiler_uic_clean:
	-$(DEL_FILE) ui_drawingform.h
ui_drawingform.h: ./drawingform.ui \
		./drawingarea.h \
		./scale.h
	/usr/lib64/qt4/bin/uic ./drawingform.ui -o ui_drawingform.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: ./main.cpp ./drawingform.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o ./main.cpp

drawingform.o: ./drawingform.cpp ./drawingform.h \
		ui_drawingform.h \
		./drawingarea.h \
		./scale.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o drawingform.o ./drawingform.cpp

drawingarea.o: ./drawingarea.cpp ./drawingarea.h \
		./scale.h \
		ui_drawingform.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o drawingarea.o ./drawingarea.cpp

scale.o: ./scale.cpp ./scale.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o scale.o ./scale.cpp

moc_drawingform.o: moc_drawingform.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_drawingform.o moc_drawingform.cpp

moc_drawingarea.o: moc_drawingarea.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_drawingarea.o moc_drawingarea.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

