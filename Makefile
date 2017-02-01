CC=arm-linux-gcc

all:executable

debug: CC += -g -DDEBUG
debug: executable

executable: standby.c
	$(CC) standby.c -o standby
	fesign --module opensc-pkcs11.so --pin 648219 --slotid 1 --keyid 00a0 --infile standby
	
.PHONY: clean
clean:
	rm -f standby standby.backup
