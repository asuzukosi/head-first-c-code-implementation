 main.o: main.c
	gcc -c main.c
arduino_commands.o: arduino_commands.c
	gcc -c arduino_commands.c
soil_status_reader.o: soil_status_reader.c
	gcc -c soil_status_reader.c
warnging_message_printer.o: warnging_message_printer.c
	gcc -c warnging_message_printer.c
launch: main.o arduino_commands.o soil_status_reader.o warnging_message_printer.o
	gcc main.o arduino_commands.o soil_status_reader.o warnging_message_printer.o -o launch