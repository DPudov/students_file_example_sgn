CC = gcc
CFLAGS = -std=c99 -Wall -Werror
OBJS = binary_files_example.o file_writer_example.o text_files_example.o

binary_files_example.exe: binary_files_example.o
	$(CC) $(CFLAGS) -o $@ $^

file_writer_example.exe: file_writer_example.o
	$(CC) $(CFLAGS) -o $@ $^

text_files_example.exe: text_files_example.o
	$(CC) $(CFLAGS) -o $@ $^

all: binary_files_example.exe file_writer_example.exe text_files_example.exe

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) *.o *.exe *.h.gch
