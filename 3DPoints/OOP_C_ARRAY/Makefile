#CC=x86_64-w64-mingw32-g++
CC=g++
CCFLAGS = -c -g -MMD -std=c++17 -Wall -O2
LDFLAGS = -g -static -static-libgcc -static-libstdc++ -O2

OBJDIR = build
SRCDIR = src

SRC = $(shell find $(SRCDIR) -name "*.cpp")
OBJ = $(SRC:$(SRCDIR)%.cpp=$(OBJDIR)%.o)
DEPENDENCIES = $(SRC:$(SRCDIR)%.cpp=$(OBJDIR)%.d)

APP = main

$(APP): $(OBJ)
	@echo "== LINKING EXECUTABLE $(OBJDIR)/$(APP)"
	@$(CC) $(LDFLAGS) $^ -o $(OBJDIR)/$(APP)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp 
	@echo "== COMPILING SOURCE $< INTO $@"
	@mkdir -p $(@D)
	@$(CC) $(CCFLAGS) -o $@ $<

-include $(DEPENDENCIES)

clean:
	@rm -rf $(OBJDIR)
	@rm -f $(APP)