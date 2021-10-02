KERN=pagerank
ALG=naive

CFLAGS?=-O3 -Wall -Wno-unused-label

CC = gcc

SRCS=$(KERN).c local_support.c ./support.c
FILES=$(SRCS) $(KERN).h ./support.h

$(KERN): $(FILES) ./harness.c
	$(CC) $(CFLAGS) -I./ -o $(KERN) $(SRCS) ./harness.c

run: $(KERN) input.data check.data
	./$(KERN) input.data check.data

generate: $(FILES) generate.c
	$(CC) $(CFLAGS) -I./ -o generate $(SRCS) generate.c
	./generate

hls: hls.tcl
	vivado_hls hls.tcl

syn: syn.tcl
	vivado -mode tcl -source syn.tcl -log ./syn.log

clean:
	rm -f $(KERN) generate output.data
