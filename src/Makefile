# rRootage makefile
# gcc version 7.2.0 (Rev1, Built by MSYS2 project)
#  Target: i686-w64-mingw32

NAME = rr
O    = o
RM   = rm -f
CC   = gcc
CXX  = g++
AR	 = ar

PROG = $(NAME).exe
SILENT = @
CONFIG = release
BULLET_DIR = libbulletml
BULLET_OBJ_DIR = $(BULLET_DIR)/obj/$(CONFIG)/libbulletml
BULLET_TARGET_DIR = $(BULLET_DIR)/bin/$(CONFIG)
BULLET_TARGET = $(BULLET_TARGET_DIR)/libbulletml.a
BULLET_INCLUDE = $(BULLET_DIR)/include
BULLET_SRC = $(BULLET_DIR)/src

BULLET_DEFINES += -DNDEBUG
BULLET_INCLUDES += -I$(BULLET_INCLUDE) -I$(BULLET_SRC)

DEFAULT_CFLAGS = `sdl2-config --cflags`
LDFLAGS = -static-libgcc -static-libstdc++ -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive -L/mingw64/lib -lglu32 -lopengl32 -lmingw32 -lSDL2main -L./libbulletml/bin/$(CONFIG)/ -lbulletml -Wl,-Bdynamic -L.. -lSDL2 -lSDL2_mixer -mwindows

MORE_CFLAGS = -O2 -Wall

CFLAGS = $(DEFAULT_CFLAGS) $(MORE_CFLAGS)
CXXFLAGS = $(DEFAULT_CFLAGS) $(MORE_CFLAGS) -I$(BULLET_TARGET_DIR)

BULLET_OBJECTS = \
	$(BULLET_OBJ_DIR)/bulletmlparser-tinyxml.$(O) \
	$(BULLET_OBJ_DIR)/bulletmlparser.$(O) \
	$(BULLET_OBJ_DIR)/bulletmlrunner.$(O) \
	$(BULLET_OBJ_DIR)/bulletmlrunnerimpl.$(O) \
	$(BULLET_OBJ_DIR)/bulletmltree.$(O) \
	$(BULLET_OBJ_DIR)/calc.$(O) \
	$(BULLET_OBJ_DIR)/formula-variables.$(O)

TINY_XML_OBJECTS = \
	$(BULLET_OBJ_DIR)/tinyxml.$(O) \
	$(BULLET_OBJ_DIR)/tinyxmlerror.$(O) \
	$(BULLET_OBJ_DIR)/tinyxmlparser.$(O) \
	$(BULLET_OBJ_DIR)/xmltest.$(O)

OBJS = $(NAME).$(O) \
	foe.$(O) foecommand.$(O) barragemanager.$(O) boss.$(O) ship.$(O) laser.$(O) \
	frag.$(O) background.$(O) letterrender.$(O) shot.$(O) \
	screen.$(O) vector.$(O) degutil.$(O) rand.$(O) mt19937int.$(O) \
	soundmanager.$(O) attractmanager.$(O) \
	$(NAME)_res.$(O)

LINK_CMD = $(AR) -rcs "$@" $(BULLET_OBJECTS) $(TINY_XML_OBJECTS)

all: $(BULLET_TARGET) $(BULLET_TARGET_DIR) $(BULLET_OBJ_DIR) $(PROG) $(NAME)_res.o
	@:

$(BULLET_TARGET): $(BULLET_OBJECTS) $(BULLET_TARGET_DIR) $(TINY_XML_OBJECTS)
	@echo "[ AR       ] $@"
	$(SILENT) $(LINK_CMD)

$(BULLET_OBJECTS): $(BULLET_OBJ_DIR)
	@echo "[ CXX      ] $@"
	$(SILENT) $(CXX) $(BULLET_DEFINES) -MMD -MP $(MORE_CFLAGS) -std=c++11 $(BULLET_INCLUDES) -g -o "$@" -MF "$(@:%.o=%.d)" -c "$(BULLET_SRC)/$(@F:%.o=%.cpp)"

$(TINY_XML_OBJECTS): $(BULLET_OBJ_DIR)
	@echo "[ CXX      ] $@"
	$(SILENT) $(CXX) $(BULLET_DEFINES) -MMD -MP $(MORE_CFLAGS) -std=c++11 $(BULLET_INCLUDES) -g -o "$@" -MF "$(@:%.o=%.d)" -c "$(BULLET_SRC)/tinyxml/$(@F:%.o=%.cpp)"

$(BULLET_TARGET_DIR):
	@echo "[ MKDIR     ] $@"
	$(SILENT) mkdir -p $(BULLET_TARGET_DIR)

$(BULLET_OBJ_DIR):
	@echo "[ MKDIR     ] $@"
	$(SILENT) mkdir -p $(BULLET_OBJ_DIR)

$(PROG): $(OBJS) $(BULLET_TARGET)
	@echo "[ EXE      ] $@"
	$(SILENT) $(CXX) -o $(PROG) $(OBJS) $(LDFLAGS)
	$(SILENT) mv $(PROG) ..

$(NAME)_res.o: $(NAME).rc
	@echo "[ RES      ] $@"
	$(SILENT) windres -i $(NAME).rc -o $(NAME)_res.o

%.o: %.cpp
	@echo "[ CXX      ] $@"
	$(SILENT) $(CXX) $(CXXFLAGS) $(LDFLAGS) '$@' -c -o '$@' '$<'

%.o: %.c
	@echo "[ CC       ] $@"
	$(SILENT) $(CC) $(CFLAGS) $(LDFLAGS) -o '$@' -c '$<'

clean:
	@echo Cleaning libBulletML
	$(SILENT) $(RM) -f $(BULLET_TARGET)
	$(SILENT) $(RM) -rf $(BULLET_OBJ_DIR)
	@echo Cleaning rRootage
	$(SILENT) $(RM) ../$(PROG) *.$(O)
