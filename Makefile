# Paweł Rusnarczyk

# dodanie używanych suffiksów
.SUFFIXES: .cpp .o .h .x

#Wczytanie nazwy katalogu do zmiennej
DIR = `basename $(CURDIR)`

NAME1 = main
NAME2 = config
NAME3 = input

NAME4 = person
NAME5 = student
NAME6 = teacher
NAME7 = staff

NAME8 = screen
NAME9 = login
NAME10 = account
NAME11 = terminal
NAME12 = tablefunctions

EXEC = $(NAME1).x

OBJS1 = $(NAME1).o
OBJS5 = $(NAME5).o
OBJS6 = $(NAME6).o
OBJS7 = $(NAME7).o
OBJS8 = $(NAME8).o
OBJS9 = $(NAME9).o
OBJS10 = $(NAME10).o
OBJS11 = $(NAME11).o
OBJS12 = $(NAME12).o

HEAD2 = $(NAME2).h
HEAD3 = $(NAME3).h
HEAD4 = $(NAME4).h
HEAD5 = $(NAME5).h
HEAD6 = $(NAME6).h
HEAD7 = $(NAME7).h
HEAD8 = $(NAME8).h
HEAD9 = $(NAME9).h
HEAD10 = $(NAME10).h
HEAD11 = $(NAME11).h
HEAD12 = $(NAME12).h

CO = g++
LD = $(CO)

CPPFLAGS = -g –Wall

OBJS = $(OBJS1) $(OBJS5) $(OBJS6) $(OBJS7) $(OBJS8) $(OBJS9) $(OBJS10) $(OBJS11) $(OBJS12)

%.o: %.cpp %.h
	$(CO) $(CFLAGS) -c $< 

%.o: %.cpp
	$(CO) $(CFLAGS) -c $<

$(EXEC): $(OBJS) 
	$(LD) -o $@ $(LFLAGS) $^ $(FLAGS)

.PHONY: all
all: $(EXEC)

program: $(EXEC) 
	./$(EXEC)

clean:                                                     
	rm -f *.o *.x