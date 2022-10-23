encrypt_user.o: encrypt_user.c
	gcc -c encrypt_user.c

xor_encrypt.o: xor_encrypt.c
	gcc -c xor_encrypt.c

launch: encrypt_user.o xor_encrypt.o
	gcc encrypt_user.o xor_encrypt.o -o launch