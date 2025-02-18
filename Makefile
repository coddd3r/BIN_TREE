#web server make file 
# httpd:
# 	gcc httpd.c -o 	rundaemon			
BINARY=runner
CODEDIRS=.
INCDIRS=. #can be list

CC=gcc
OPT=-O2	
#generate files to make rules for .h dependencies
DEPFLAGS=-MP -MD -MMD
#foreach dir in include directories include it using -I 
CFLAGS=-Wall -Wextra  -g $(foreach D, $(INCDIRS), -I$(D)) $(OPT) $(DEPFLAGS)
# LDFLAGS=

ALL_CFILES=$(foreach D, $(CODEDIRS), $(wildcard $(D)/*.c))
CFILES=$(filter-out $(CODEDIRS)/test.c, $(ALL_CFILES))
# OBJECTS=$(patsubst %.c, %.o, $(CFILES))
# DEPFILES=$(patsubst %.c, %.d, $(CFILES))

OBJECTS = $(CFILES:.c=.o)
DEPFILES = $(CFILES:.c=.d) 
# .PHONY: all clean 

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $< 
clean: 
	clear; trash $(BINARY) $(OBJECTS) $(DEPFILES) *.out