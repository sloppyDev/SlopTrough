#### COMPILE FLAGS ####
CC			 = g++
CFLAGS	 = -pedantic-errors -Wall -Wextra -Werror
CENDFLAGS =	$(foreach d, $(IDIR), -I$d)
LIBFLAGS  = -lGL  -lglfw3

TARGET = SlopTrough

#### DIRECTORY DEFINITIONS ####
IDIR 	 = ./include ./include/tests ./include/math ./include/graphics
BDIR	 = ./build
ODIR	 = $(BDIR)/obj
APPDIR = $(BDIR)/apps


#### SRC and OBJ ####
SRC = $(wildcard src/*.cpp) \
		$(wildcard src/math/*.cpp)
OBJ = $(SRC:%.cpp=$(ODIR)/%.o)

#### BUILD OBJECTS ####
$(ODIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $< $(CENDFLAGS) $(LIBFLAGS)

#### BUILD TARGET ####
$(APPDIR)/$(TARGET): $(OBJ)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $^ $(CENDFLAGS) $(LIBFLAGS)

.PHONY: all build debug release clean
#### ALL ####
all: build $(APPDIR)/$(TARGET)

#### BUILD ####
build:
	@mkdir -p $(APPDIR)
	@mkdir -p $(ODIR)

#### DEBUG ####
debug: CFLAGS += -DDEBUG -g
debug: all

#### RELEASE ####
release: CFLAGS += -O2
release: all

#### CLEAN ####
clean:
	-@rm -rvf $(ODIR)/*
	-@rm -rvf $(APPDIR)/*
