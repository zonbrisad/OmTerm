# Hey Emacs, this is a -*- makefile -*-
#----------------------------------------------------------------------------
# 
# Makeplate example project
#
# author: Peter Malmberg <peter.malmberg@gmail.com>
#
#  
#----------------------------------------------------------------------------
# On command line:
# >make help 
#----------------------------------------------------------------------------

# Target platform
# linux win32 avr arm osx
TARGET_PLATFORM = linux

# Project Licence (GPL, GPLv2, MIT, BSD, Apache, etc.) 
LICENCE = GPLv2

# Target file name (without extension).
TARGET = omTerm

# List C, C++ and assembler source files here. (C/C++ dependencies are automatically generated.)
SRC = src/main.cpp       \
      src/mainForm.cpp   \
			src/console.cpp    \
			src/aboutForm.cpp  \

MOCS = src/mainForm.h src/console.h src/aboutForm.h

MOCSRC = $(patsubst %.h,%_moc.cpp,$(MOCS))           # Generate moc source files
SRC += $(MOCSRC)


# List C, C++ and assembler library/3rd partry source files here. (C/C++ dependencies are automatically generated.)
LSRC =	

# Include directories
INCLUDE = inc \
          src \

# Libraries to link
LIB   = -lm 
LIB  += -lpthread

# Libraries to use in pkg-config system
PKGLIBS  = Qt5Core 
PKGLIBS += Qt5Gui 
PKGLIBS += Qt5Widgets
PKGLIBS += Qt5SerialPort
#PKGLIBS += glib-2.0
#PKGLIBS += gthread-2.0
#PKGLIBS += ncurses
#PKGLIBS += lua5.1
#PKGLIBS += sqlite3

# Object files directory
#     To put object files in current directory, use a dot (.), do NOT make
#     this an empty or blank macro!
OBJDIR = .

# Source code directory
SRCDIR=src

# Build directory
BUILDDIR=build

# Output directory
OUTDIR = output

# Optimization level, can be [0, 1, 2, 3, s]. 
#     0 = turn off optimization. s = optimize for size.
OPT = 2

# Compiler flag to set the C Standard level.
# [ gnu99 gnu11 c++98 c++03 c++11 c++14 ] 
CSTANDARD   = gnu99
CPPSTANDARD = c++11

# C Macro definitions
CDEFS = DEBUGPRINT   \
        WARNINGPRINT \
        ERRORPRINT   \
        INFOPRINT   

# C++ Macro definitions
CPPDEFS = 

# Debug information --------------------------------------------------------- 
# 0 = no debug information 
# 1 = minimal debug information
# 2 = normal debug information 
# 3 = maximal debug information
DEBUG=0

#
# Compiler and Linker options
#============================================================================

# Compiler Options C --------------------------------------------------------
CFLAGS = -g$(DEBUG)                            # Debugging information
CFLAGS += -O$(OPT)                             # Optimisation level
CFLAGS += -std=$(CSTANDARD)                    # C standard
CFLAGS += $(patsubst %,-I%,$(INCLUDE))         # Include directories 
CFLAGS += $(patsubst %,-D%,$(CDEFS))           # Macro definitions
CFLAGS += -Wa,-adhlns=$(<:$(SRCDIR)/%.c=$(BUILDDIR)/%.lst) # Generate assembler listing

# Compiler Tuning C ---------------------------------------------------------
CFLAGS += -funsigned-char
#CFLAGS += -funsigned-bitfields
#CFLAGS += -fpack-struct
#CFLAGS += -fshort-enums
#CFLAGS += -fno-unit-at-a-time
#CFLAGS += -mshort-calls

# Compiler Warnings C -------------------------------------------------------
CFLAGS += -Wall                  # Standard warnings
CFLAGS += -Wextra                # Some extra warnings
CFLAGS += -Wmissing-braces 
CFLAGS += -Wmissing-declarations # Warn if global function is not declared
CFLAGS += -Wmissing-prototypes   # if a function is missing its prototype
CFLAGS += -Wstrict-prototypes    # non correct prototypes i.e. void fun() => void fun(void) 
CFLAGS += -Wredundant-decls      # Warn if something is declared more than ones
CFLAGS += -Wunreachable-code     # if code is not used
CFLAGS += -Wshadow               # if local variable has same name as global
CFLAGS += -Wformat=2             # check printf and scanf for problems
#CFLAGS += -Wno-format-nonliteral # 
CFLAGS += -Wpointer-arith        # warn if trying to do aritmethics on a void pointer
#CFLAGS += -Wsign-compare
#CFLAGS += -Wundef
#CFLAGS += -Werror               # All warnings will be treated as errors

# Library compiler flags C --------------------------------------------------
CFLAGS += $(foreach X, $(PKGLIBS), $(shell pkg-config --cflags $(X)) )


# Compiler Options C++ ------------------------------------------------------
CPPFLAGS = -g$(DEBUG)                              # Debugging information
CPPFLAGS += -O$(OPT)                               # Optimisation level
CPPFLAGS += -std=$(CPPSTANDARD)                    # C++ standard
CPPFLAGS += $(patsubst %,-I%,$(INCLUDE))           # Include directories
CPPFLAGS += $(patsubst %,-D%,$(CPPDEFS))           # Macro definitions
CPPFLAGS += -Wa,-adhlns=$(<:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.lst) # Generate assembler listing

# Compiler Tuning C++ -------------------------------------------------------
CPPFLAGS += -funsigned-char
CPPFLAGS += -funsigned-bitfields
#CPPFLAGS += -fpack-struct
CPPFLAGS += -fshort-enums
CPPFLAGS += -fno-exceptions
#CPPFLAGS += -mshort-calls
#CPPFLAGS += -fno-unit-at-a-time
CPPFLAGS += -fPIC                  # Position independet code

# Compiler Warnings C++ -----------------------------------------------------
CPPFLAGS += -Wall                  # Standard warnings
CPPFLAGS += -Wextra                # Some extra warnings
CPPFLAGS += -Wmissing-braces 
CPPFLAGS += -Wmissing-declarations # Warn if global function is not declared
CPPFLAGS += -Wredundant-decls      # Warn if something is declared more than ones
CPPFLAGS += -Wunreachable-code     # if code is not used
#CPPFLAGS += -Wshadow               # if local variable has same name as global (problematic?)
CPPFLAGS += -Wformat=2             # check printf and scanf for problems
#CPPFLAGS += -Wno-format-nonliteral # 
CPPFLAGS += -Wpointer-arith        # warn if trying to do aritmethics on a void pointer
#CPPFLAGS += -Wsign-compare
#CPPFLAGS += -Wundef
#CPPFLAGS += -Werror              # All warnings will be treated as errors

# Library compiler flags C++ ------------------------------------------------
CPPFLAGS += $(foreach X, $(PKGLIBS), $(shell pkg-config --cflags $(X)) )

# Qt Specific
#CPPFLAGS += -pipe
#CPPFLAGS += -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
#CPPFLAGS += -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore
#CPPFLAGS += -Iobjs -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64


# Linker Options ------------------------------------------------------------
#  -Wl,...:     tell GCC to pass this to linker.
#    -Map:      create map file
#    --cref:    add cross reference to  map file
LDFLAGS = -Wl,-Map=$(OUTDIR)/$(TARGET).map,--cref
LDFLAGS += $(EXTMEMOPTS)
LDFLAGS += $(patsubst %,-L%,$(INCLUDE))
LDFLAGS += -g
LDFLAGS += $(foreach X, $(PKGLIBS), $(shell pkg-config --libs $(X)) )

#
# Platform specific options
#============================================================================

# Linux options -------------------------------------------------------------
ifeq ($(TARGET_PLATFORM), linux)

# Target filename
TRGFILE=$(OUTDIR)/$(TARGET)

# Toolchain base directory
TCHAIN_BASE=/usr/bin

# Toolchain prefix 
TCHAIN_PREFIX=

endif
# Windows options -----------------------------------------------------------
ifeq ($(TARGET_PLATFORM), win32)

# Target filename
TRGFILE=$(OUTDIR)/$(TARGET).exe

# Toolchain base directory
TCHAIN_BASE=/usr/bin

# Toolchain prefix 
TCHAIN_PREFIX=

endif

#
# Tool settings
#============================================================================

# Define programs and commands ----------------------------------------------
SHELL     = bash
REMOVE    = rm -f
REMOVEDIR = rm -rf
COPY      = cp -f 
MOVE      = mv -f
WINSHELL  = cmd
MKDIR     = mkdir -p
SED       = sed
MOC       = moc
QMAKE     = qmake
CTEMPLATE = python3 tools/ctemplate.py
BIN2ARRAY = python3 tools/bin2array.py
MPTOOL    = tools/mkptools
CPPCHECK  = cppcheck
INSTALL   = install
ASTYLE    = astyle
DOXYGEN   = doxygen

TCHAIN = $(TCHAIN_BASE)/$(TCHAIN_PREFIX)

CC        = ${TCHAIN}gcc
CPP       = ${TCHAIN}g++
OBJCOPY   = ${TCHAIN}objcopy
OBJDUMP   = ${TCHAIN}objdump
SIZE      = ${TCHAIN}size
AR        = ${TCHAIN}ar rcs
NM        = ${TCHAIN}nm
AS        = ${TCHAIN}as
GDB       = ${TCHAIN}gdb

#
# Message/Filter settings
#============================================================================

# Color definitions ---------------------------------------------------------
E_BLACK        = \033[0;300m
E_RED          = \033[0;31m
E_GREEN        = \033[0;32m
E_YELLOW       = \033[0;33m
E_BLUE         = \033[0;34m
E_MAGENTA      = \033[0;35m
E_CYAN         = \033[0;36m
E_GRAY         = \033[0;37m
E_DARKGRAY     = \033[1;30m
E_BR_RED       = \033[1;31m
E_BR_GREEN     = \033[1;32m
E_BR_YELLOW    = \033[1;33m
E_BR_BLUE      = \033[1;34m
E_BR_MAGENTA   = \033[1;35m
E_BR_CYAN      = \033[1;36m
E_WHITE        = \033[1;37m
E_END          = \033[0m
E_ON_BLACK     = \033[40m
E_ON_RED       = \033[41m
E_ON_GREEN     = \033[42m
E_ON_YELLOW    = \033[43m
E_ON_BLUE      = \033[44m
E_ON_MAGENTA   = \033[45m
E_ON_CYAN      = \033[46m
E_ON_WHITE     = \033[47m

# ANSI Text attributes
E_ATTR_BOLD=\e[1m
E_ATTR_LOWI=\e[2m
E_ATTR_UNDERLINE=\e[4m
E_ATTR_BLINK=\e[5m
E_ATTR_REVERSE=\e[7m

# System color definitions
C_OK=$(E_BR_GREEN)
C_WARNING=$(E_BR_YELLOW)
C_ERROR=$(E_BR_RED)
C_FILE=$(E_BR_CYAN)
C_DIR=$(E_CYAN)
C_NOTE=$(E_BR_GREEN)
C_MSG=$(E_BR_GREEN)
C_ACTION=$(E_BR_MAGENTA)
C_VALUE=$(E_WHITE)$(E_ON_BLUE)
C_IDENTIFIER=$(E_WHITE)

# Messages ------------------------------------------------------------------
MSG_LINE             = "$(E_WHITE)------------------------------------------------------------------$(E_END)"
MSG_BEGIN            = "${E_WHITE}-------------------------------- Begin ---------------------------${E_END}"
MSG_END              = "${E_WHITE}-------------------------------- End -----------------------------${E_END}"
MSG_ERRORS_NONE      = "${C_OK}Errors: none ${E_END}"
MSG_LINKING          = "${C_ACTION}Linking:${E_END}"
MSG_COMPILING        = "${C_ACTION}Compiling C:  ${E_END}"
MSG_COMPILING_CPP    = "${C_ACTION}Compiling C++:${E_END}"
MSG_ASSEMBLING       = "${C_ACTION}Assembling:${E_END}"
MSG_CLEANING         = "$(C_ACTION)Cleaning project:$(E_END)"
MSG_EXTENDED_LISTING = "${C_ACTION}Creating Extended Listing/Disassembly:$(E_END)"
MSG_SYMBOL_TABLE     = "${C_ACTION}Creating Symbol Table:$(E_END)"
MSG_HEX_FILE         = "${C_ACTION}Creating Hex file:$(E_END)"
MSG_FORMATERROR      = "${C_ERROR}Can not handle output-format${E_END}"
MSG_ASMFROMC         = "${C_ACTION}Creating asm-File from C-Source:$(E_END)"
MSG_SIZE_BEFORE      = "${C_ACTION}Size before:${E_END}"
MSG_SIZE_AFTER       = "${C_ACTION}Size after build:${E_END}"
MSG_LOAD_FILE        = "${C_ACTION}Creating load file:${E_END}"
MSG_ARCHIVING        = "${C_ACTION}Creating tar archive:${E_END}"
MSG_CREATING_LIBRARY = "${C_ACTION}Creating library:${E_END}"
MSG_FLASH            = "${C_ACTION}Creating load file for Flash:${E_END}"
MSG_EEPROM           = "${C_ACTION}Creating load file for EEPROM:${E_END}"
MSG_COFF             = "${C_ACTION}Converting to AVR COFF:${E_END}"
MSG_EXTENDED_COFF    = "${C_ACTION}Converting to AVR Extended COFF:${E_END}"
MSG_MOC              = "${C_ACTION}Creating MOC file:${E_END}"	
MSG_BACKUP           = "${E_BR_GREEN}Making incremental backup of project:${E_END}"
MSG_SRC              = "${C_MSG}Source files $(E_GREEN)-----------------------------------------------------${E_END}"
MSG_FLAGS            = "${C_MSG}Compiler Flags $(E_GREEN)---------------------------------------------------${E_END}"
MSG_LINKER           = "${C_MSG}Linker Flags $(E_GREEN)-----------------------------------------------------${E_END}"
MSG_PROJECT          = "${C_MSG}Project info $(E_GREEN)-----------------------------------------------------${E_END}"
MSG_INCLUDES         = "${C_MSG}Include directories $(E_GREEN)----------------------------------------------${E_END}"
MSG_DEFS             = "${C_MSG}Macro definitions $(E_GREEN)------------------------------------------------${E_END}"
MSG_INSTALL_INFO     = "${C_MSG}Install settings $(E_GREEN)-------------------------------------------------${E_END}"
MSG_INSTALLING       = "${C_ACTION}Installing:   ${E_END}"
MSG_BUILDING         = "$(C_ACTION)Building:     "
	
# Compiler output colorizer filter ------------------------------------------
F_SOURCE=| sed -e "s/\(.*\/\)\(.*\)/$$(printf "$(C_DIR)")\1$$(printf "$(C_FILE)")\2$$(printf "$(E_END)")/"
F_INF="s/In function/$$(printf "$(E_BR_GREEN)")&$$(printf "$(E_END)")/i"
F_NOTE="s/note:/$$(printf "$(C_NOTE)")&$$(printf "$(E_END)")/i"
F_WARNING="s/warning:/$$(printf "$(C_WARNING)")&$$(printf "$(E_END)")/i"
F_ERROR="s/error:/$$(printf "$(C_ERROR)")&$$(printf "$(E_END)")/i"
F_FATAL_ERROR="s/fatal error:/$$(printf "$(C_ERROR)")&$$(printf "$(E_END)")/i"
F_WARNING1="s/defined but not used/$$(printf "$(C_WARNING)")&$$(printf "$(E_END)")/i"
F_WARNING2="s/unused variable/$$(printf "$(C_WARNING)")&$$(printf "$(E_END)")/i"
F_WARNING3="s/may be used uninitialized in this function/$$(printf "$(C_WARNING)")&$$(printf "$(E_END)")/i"
F_WARNING4="s/implicit declaration of function/$$(printf "$(C_WARNING)")&$$(printf "$(E_END)")/i"
F_WARNING5="s/value computed is not used/$$(printf "$(C_WARNING)")&$$(printf "$(E_END)")/i"
F_BRACKET="s/\[\(.*\)\]/[$$(printf "$(E_GREEN)")\1$$(printf "$(E_END)")]/"	
F_VARIABLE="s/\‘\(.*\)[\’\‘]/'$$(printf "$(C_IDENTIFIER)")\1$$(printf "$(E_END)")'/g"
F_FILE="s/[^: ]*/$$(printf "$(C_FILE)")&$$(printf "$(E_END)")/"
#F_FILE="s/\(.*\/\)\(.*\):/$$(printf "$(C_DIR)")\1$$(printf "$(C_FILE)")\2$$(printf "$(E_END)"):/1"
F_ROWNR="s/:\([0-9]*\):\([0-9]*\):/:$$(printf "$(C_VALUE)")\1$$(printf "$(E_END)"):$$(printf "$(C_VALUE)")\2$$(printf "$(E_END)"):/"

C_FILTER   = | sed -u -e $(F_BRACKET) -e $(F_FILE) -e $(F_ROWNR)          \
                      -e $(F_INF) -e $(F_NOTE)                            \
 	                  -e $(F_WARNING) -e $(F_ERROR) -e $(F_FATAL_ERROR)   \
                      -e $(F_WARNING1) -e $(F_WARNING2) -e $(F_WARNING3)  \
                      -e $(F_WARNING4) -e $(F_WARNING5)                   \
                      -e $(F_VARIABLE)

CPP_FILTER = $(C_FILTER)

LD_ERROR1="s/undefined reference/$$(printf "$(C_ERROR)")&$$(printf "$(E_END)")/i"
LD_ERROR2="s/No such file or directory/$$(printf "$(C_ERROR)")&$$(printf "$(E_END)")/i"
LD_FILTER = | sed -ru -e $(LD_ERROR1) -e $(LD_ERROR2)
	
#
# Build rules	
#============================================================================

# Compiler flags to generate dependency files.
GENDEPFLAGS = -MMD -MP -MF .dep/$(@F).d

# Combine all necessary flags and optional flags.
# Add target processor to flags.
ALL_CFLAGS   =  -I. $(CFLAGS) $(GENDEPFLAGS)
ALL_CPPFLAGS =  -I. -x c++ $(CPPFLAGS) $(GENDEPFLAGS)

# Filter out C sources
CSRC_1 = $(patsubst $(SRCDIR)/%.cpp,  , $(SRC) $(LSRC))
CSRC   = $(patsubst $(SRCDIR)/%.S,    , $(CSRC_1))

# Filter out C++ sources
CPPSRC_1 = $(patsubst $(SRCDIR)/%.c,  , $(SRC) $(LSRC))
CPPSRC   = $(patsubst $(SRCDIR)/%.S,  , $(CPPSRC_1))

# Define all object files.
COBJS    = $(patsubst $(SRCDIR)/%.c,   $(BUILDDIR)/%.o, $(CSRC)) 
CPPOBJS  = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(CPPSRC))

OBJS    = $(COBJS) $(CPPOBJS) 

# Define all listing files.
LST = $(patsubst src/%.c, $(OBJDIR)/%.lst, $(CSRC)) $(patsubst src/%.cpp, $(OBJDIR)/%.lst, $(CPPSRC))

# Default target.
all:	begin build finished end

# Remove colorfilter
nocolor:
	$(eval C_FILTER:= )
	
#
# Build with no color filter on compiler output
# Useful for Netbeans, Eclipse builds etc. 
#	
nc: nocolor all   ## Build with no color on compiler output


build: elf lss sym size

elf: $(TRGFILE)
lss: $(OUTDIR)/$(TARGET).lss
sym: $(OUTDIR)/$(TARGET).sym
hex: $(OUTDIR)/$(TARGET).hex
bin: $(OUTDIR)/$(TARGET).bin
eep: $(OUTDIR)/$(TARGET).eep

# Eye candy.
begin:
	@echo -e $(MSG_BEGIN)
	@echo -e ${MSG_BUILDING}" $(E_BR_GREEN)$(TARGET) $(E_END)"
 
end:
	@echo
	@echo -e $(MSG_END)
	
finished:
	@echo


# Link target
#.SECONDARY : $(TARGET)
.PRECIOUS : $(OBJS)
$(TRGFILE): $(OBJS) $(OUTDIR)
	@echo -en "\n"$(MSG_LINKING)"\n               "
	@echo -e $@ $(F_SOURCE) 
	@$(CPP) $(ALL_CFLAGS) $(OBJS) --output $@ $(LDFLAGS) $(LIB) 2>&1 $(LD_FILTER)
	
# Create extended listing file/disassambly from ELF output file.
# using objdump testing: option -C
%.lss:	$(TRGFILE)
	@echo -en "\n"$(MSG_EXTENDED_LISTING) "\n               "
	@echo -e $@ $(F_SOURCE)
	@$(OBJDUMP) -h -S -C -r $< > $@
	
# Create a symbol table from ELF output file.
%.sym: $(TRGFILE)
	@echo -en "\n"${MSG_SYMBOL_TABLE}"\n               "
	@echo -e $@ $(F_SOURCE)
	@$(NM) -n $< > $@

# Create hex file from ELF output file.
%.hex: $(TRGFILE)
	@echo
	@echo -e $(MSG_HEX_FILE) "\n               $(C_FILE)" $@ "$(E_END)"
	@$(OBJCOPY) -O ihex $< $@

# Compile: create object files from C source files.
$(COBJS): $(BUILDDIR)/%.o : src/%.c
	@$(MKDIR) $(@D)                                       # Create directory for object file
	@echo -en $(MSG_COMPILING)" "
	@echo -e $< $(F_SOURCE)
	@$(CC) -c $(ALL_CFLAGS) $< -o $@ 2>&1  $(C_FILTER)

# Compile: create object files from C++ source files.
$(CPPOBJS): $(BUILDDIR)/%.o : src/%.cpp
	@$(MKDIR) $(@D)                                       # Create directory for object file
	@echo -en $(MSG_COMPILING_CPP)" " 
	@echo -e $< $(F_SOURCE)
	@$(CPP) -c $(ALL_CPPFLAGS) $< -o $@ 2>&1  $(CPP_FILTER)
	
# Compile: create assembler files from C source files.
$(OBJDIR)/%.s : %.c
	@$(CC) -S $(ALL_CFLAGS) $< -o $@

# Compile: create assembler files from C++ source files.
$(OBJDIR)/%.s : %.cpp
	@$(CC) -S $(ALL_CPPFLAGS) $< -o $@

# Generate cc from h via Qt's Meta Object Compiler, rule to change postfix
#%_moc.cc: %.h
$(MOCSRC): %_moc.cpp : %.h 	
	@echo -en $(MSG_MOC) "\n               "
	@echo -e $@ $(F_SOURCE)
	@$(MOC) $(INCDIRS) $< -o $@

# Create output dir
$(OUTDIR):
	@$(MKDIR) $@

# Create build dir
$(BUILDDIR):
	@$(MKDIR) $@

# Print information about target binary 
size: $(TRGFILE)
	@echo
	@echo -e $(MSG_SIZE_AFTER)
	@$(SIZE) $(TRGFILE)


# 
# Debug rules
#============================================================================
debug: ## Debug program
	@$(GDB) $(TRGFILE) 

	
#
# Various utility rules	
#============================================================================


clean:  ## Remove all build files
	@echo
	@echo -e $(MSG_CLEANING)
	@$(REMOVE) $(OUTDIR)/$(TARGET)
	@$(REMOVE) $(OUTDIR)/$(TARGET).elf
	@$(REMOVE) $(OUTDIR)/$(TARGET).hex
	@$(REMOVE) $(OUTDIR)/$(TARGET).lss
	@$(REMOVE) $(OUTDIR)/$(TARGET).map
	@$(REMOVE) $(OUTDIR)/$(TARGET).sym
	@$(REMOVE) $(OUTDIR)/$(TARGET).bin
	@$(REMOVE) $(OUTDIR)/$(TARGET).eep
	@$(REMOVE) $(OUTDIR)/$(TARGET).cof
	@$(REMOVE) $(OBJS)
	@$(REMOVE) $(LST)
	@$(REMOVE) $(MOCSRC)
	@$(REMOVEDIR) .dep
	@$(REMOVEDIR) $(BUILDDIR)	
	@find . -name "*~" -delete
	@find . -name "*.orig" -delete


archive: ## Make a tar archive of the source code
	@echo
	@echo -e $(MSG_ARCHIVING)
	@$(eval DT=$(shell date +"%Y%m%d-%H%M%S"))
	@$(MKDIR) archive
	@tar -cvzf archive/$(TARGET)_${DT}.tar.gz *  \
		--exclude='archive'  \
		--exclude='backup'   \
		--exclude='output'   \
		--exclude='*.a'      \
		--exclude='*.o'      \
		--exclude='*.ko'     \
		--exclude='*.obj'    \
		--exclude='*.a'      \
		--exclude='*.la'     \
		--exclude='*.lo'     \
		--exclude='*.slo'    \
		--exclude='*.lib'    \
		--exclude='*.so'     \
		--exclude='*.so*'    \
		--exclude='.dep'     \
		--exclude='.svn'     \
		--exclude='.git'     \
		--exclude='*.elf'    \
		--exclude='*.hex'    \
		--exclude='*.bin'    \
		--exclude='*.exe'    \
		--exclude='*.sym'    \
		--exclude='*.lss'    \
		--exclude='*.map'    \
		--exclude='*.app'    \
		--exclude='*.i*86'   \
		--exclude='*.x86_64' \
		--exclude='*~'       \
		--exclude="*.old"    \
		--exclude="*.tmp"    \

# Backup directory
BACKUP_DIR=backup

# Nr of backups
BACKUPS=100

backup: ## Make an incremental backup
	@echo
	@echo -e $(MSG_BACKUP)
	@$(MKDIR) $(BACKUP_DIR)
  # remove oldest backup
	@$(RM) -rf $(BACKUP_DIR)/backup_$(BACKUPS) 
  # rotate backups 
	@for ((x=$(BACKUPS);x>0;x--)); do                 \
	  bdir=$(BACKUP_DIR)/backup_`expr $${x} - 1` ;    \
	  # check if directory exist before renameing  it \
	  if [ -d $${bdir} ]; then                        \
	    mv -f $${bdir}  $(BACKUP_DIR)/backup_$${x} ;  \
	  fi ;                                            \
	done 
	@rsync --archive             \
	      --delete               \
				--relative             \
				--exclude="backup"     \
				--exclude="archive"    \
				--exclude="output"     \
				--exclude="*.o"        \
				--exclude=".git"       \
				--exclude=".svn"       \
				--exclude="*~"         \
				--exclude="*.old"      \
				--exclude="*.tmp"      \	
				--link-dest=$(CURDIR)/$(BACKUP_DIR)/backup_1 \
				.                      \
				$(BACKUP_DIR)/backup_0 


edit:   ## Open source and makefile in editor
	@$(EDITOR) Makefile $(SRC)

run:    ## Run application
	@$(OUTDIR)/$(TARGET)

# Include the dependency files.
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)


# Project options -----------------------------------------------------------

newfile:  ## Create a new C file
	@${CTEMPLATE} --newc --dir src --author "$(AUTHOR)" --licence "$(LICENCE)"

newclass:  ## Create a new C++ class
	@${CTEMPLATE} --newclass --dir src --author "$(AUTHOR)" --licence "$(LICENCE)"	
		
#newproj:  ## Create a new project
#	@${PROJECT} newproj


# Install options -----------------------------------------------------------

# Install directory
INSTALL_DIR      = ~/bin

# Owner of binary
INSTALL_OWNER    = $${USER}

# Group owner of binary
# #INSTALL_GROUP    = $${USER}
INSTALL_GROUP    = users

# Install options
INSTALL_OPTIONS =  --owner ${INSTALL_OWNER}
INSTALL_OPTIONS += --group ${INSTALL_GROUP}
INSTALL_OPTIONS += -D
INSTALL_OPTIONS += --preserve-timestamps
#INSTALL_OPTIONS += --verbose

install: $(TRGFILE) ## Install program
	@echo -e $(MSG_INSTALLING) "$(E_BR_GREEN)$(TARGET) $(E_END)"
	@${INSTALL} ${INSTALL_OPTIONS} $(TRGFILE) ${INSTALL_DIR}

#
# Help information
#============================================================================

help: ## This help information
	@printf "%-30s %s\n" "target" "help"
	@echo -e $(MSG_LINE)
	@IFS=$$'\n' ;                                    \
	help_lines=(`fgrep -h "##" $(MAKEFILE_LIST) | fgrep -v fgrep | sed -e 's/\\$$//' | sed -e 's/##/:/'`); \
	for help_line in $${help_lines[@]}; do                                     \
	  IFS=$$':' ;                                                              \
		help_split=($$help_line) ;                                               \
		help_command=`echo $${help_split[0]} | sed -e 's/^ *//' -e 's/ *$$//'` ; \
		help_info=`echo $${help_split[2]} | sed -e 's/^ *//' -e 's/ *$$//'` ;    \
		printf "$(E_BR_CYAN)%-15s %s$(E_END)" $$help_command ;                 \
		printf "$(E_BR_GREEN)%s$(E_END)\n" $$help_info ;                       \
	done ; 
	@echo -e $(MSG_LINE)

list-src: ## List all source files
	@echo -e $(MSG_SRC)
	@export IFS=" "
	@for f in $(SRC); do      \
	  echo $${f} ;            \
	done                      \
	
list-flags: ## List compiler flags
	@echo -e $(MSG_FLAGS)
	@export IFS=" "
	@for f in $(CFLAGS); do   \
	  echo $${f} ;            \
	done                      \

list-ldflags: ## List linker flags
	@echo -e $(MSG_LINKER)
	@export IFS=" "
	@for f in $(LDFLAGS); do   \
	  echo $${f} ;             \
	done                       \

list-objs: ## List objects 
	@echo -e $(MSG_INCLUDES)
	@export IFS=" "
	@for f in $(OBJS); do   \
	  echo $${f} ;             \
	done        


check: ## Check if tools and libraries are present 
	@$(MPTOOL) ce $(CC)
	@$(MPTOOL) ce $(OBJCOPY)
	@$(MPTOOL) ce $(OBJDUMP)
	@$(MPTOOL) ce $(SIZE)
	@$(MPTOOL) ce $(AR)
	@$(MPTOOL) ce $(NM)
	@$(MPTOOL) ce $(AS)
	@$(MPTOOL) ce $(QMAKE)
	@$(MPTOOL) ce $(MOC)
	@$(MPTOOL) ce $(GDB)
	@$(MPTOOL) ce python3
	@$(MPTOOL) ce $(CPPCHECK)
	@$(MPTOOL) ce $(INSTALL)
	@$(MPTOOL) ce $(ASTYLE)
	@for f in $(LIB); do               \
		${MPTOOL} cl ${CC} $${f};      \
	done                               \
	
list-info: 
	@echo -e $(MSG_PROJECT)
	@echo "Target:     $(TARGET)"
	@echo "Platform:   $(TARGET_PLATFORM)"
	@echo "Licence:    $(LICENCE)"
	@echo "Outdir:     $(OUTDIR)"
	@echo "C standard: $(CSTANDARD)"
	@echo "MCU:        $(MCU)"
	@echo "F_CPU:      $(F_CPU)"

	
list-includes: 
	@echo -e $(MSG_INCLUDES)
	@export IFS=" "
	@for f in $(INCLUDE); do   \
	  echo $${f} ;             \
	done        

list-defs: 
	@echo -e $(MSG_DEFS)
	@export IFS=" "
	@for f in $(CDEFS); do     \
	  echo $${f} ;             \
	done        

	@for f in $(CPPDEFS); do   \
	  echo $${f} ;             \
	done        

	@for f in $(ASDEFS); do    \
	  echo $${f} ;             \
	done        


list-installinfo:
	@echo -e $(MSG_INSTALL_INFO)
	@echo "Install dir:   $(INSTALL_DIR)"
	@echo "Install user:  $(INSTALL_USER)"
	@echo "Install group: $(INSTALL_GROUP)"


info: list-info list-includes list-defs list-flags list-ldflags list-installinfo ## Print information about project

files: list-src ## List source files

gccversion :    ## Display compiler version
	@$(CC) --version
	
#
# Personal settings
#============================================================================

# Only for default settings. Change value in settings.mk
AUTHOR=Your Name <your.name@yourdomain.org>
EDITOR=jed
US:=$$USER
#PERSONAL=personal_$${USER}.mk
PERSONAL=personal.mk

# Include some external settings
# If file does not exist it will be generated.
include  ${PERSONAL}

$(PERSONAL):	# Create a settings file
	@echo "#" > ${PERSONAL}
	@echo "# This file is for personal settings only." >> ${PERSONAL}
	@echo "#" >> ${PERSONAL}
	@echo "EDITOR=${EDITOR}" >> ${PERSONAL}
	@echo "AUTHOR=${AUTHOR}" >> ${PERSONAL}



#
# CppCheck static code analysis
#============================================================================
.PHONY: ccheck acheck

# Filter rules to colorize output from cppcheck (eye candy)
F_CPPC_FILE="s/\[\(.*\):\(.*\)\]/[$$(printf "$(C_FILE)")\1$$(printf "$(E_END)"):\2]/i"
F_CPPC_ROWNR="s/:\([0-9]*\)\]/:$$(printf "$(C_VALUE)")\1$$(printf "$(E_END)")]/"
F_CPPC_VAR="s/'\(.*\)'/'$$(printf "$(C_IDENTIFIER)")\1$$(printf "$(E_END)")'/g"
F_CPPC_STYLE="s/style/$$(printf "$(C_WARNING)")&$$(printf "$(E_END)")/i"
F_CPPC_PORTABILITY="s/portability/$$(printf "$(C_CYAN)")&$$(printf "$(E_END)")/i"
F_CPPC_ERROR="s/error/$$(printf "$(C_ERROR)")&$$(printf "$(E_END)")/i"
F_CPPC_CHECK="s/\(Checking \)\(.*\)/$$(printf "$(C_ACTION)")\1$$(printf "$(E_END)")$$(printf "$(C_FILE)")\2$$(printf "$(E_END)")/i"	
CPPCHECK_FILTER   = 2>&1 | sed -u -e $(F_CPPC_ROWNR) -e $(F_CPPC_FILE) -e $(F_CPPC_STYLE) -e $(F_CPPC_ERROR) -e $(F_CPPC_PORTABILITY) -e $(F_CPPC_VAR)  -e $(F_CPPC_CHECK)

ccheck: ## Static code analysis using cppcheck(errors only)
	@$(CPPCHECK) --inline-suppr $(SRC)  $(CPPCHECK_FILTER)

acheck: ## Static code analysis using cppcheck(all warnings)
	@$(CPPCHECK) --inline-suppr --enable=all $(SRC) $(CPPCHECK_FILTER)

#
# Artistic Style (astyle) Format source code to a standard
#============================================================================
.PHONY: astyle

TABSIZE=4

# Bracket style options
AST  = --style=java

# Tab options
AST += --indent=spaces=$(TABSIZE)

# Indentation options
AST += --indent-switches
AST += --indent-cases
#AST += --indent-preproc-cond
AST += --indent-col1-comments
AST += --max-instatement-indent=40
 
# C++ specific indentation
AST += --indent-modifiers

# Padding options
AST += --break-blocks
AST += --pad-oper
#AST += --pad-comma
AST += --pad-header
AST += --align-pointer=name
AST += --align-reference=name 

# Formatting options
AST += --add-brackets 
AST += --convert-tabs

# Other options
AST += --lineend=linux
#AST += --recursive
#AST += --exclude=
AST +=--preserve-date

PSRCH = $(PSRC:%.c=%.h) 

astyle: ## Format source to conform to a standard
	@$(ASTYLE) $(AST) src/*.c src/*.cpp src/*.h

	
# Listing of phony targets.
.PHONY : all clean gccversion build begin finished end elf lss sym archive edit help backup list-src list-flags newproj run install