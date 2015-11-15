try: hospital.o
	cc hospital.o -o project
	clear
hospital.o: hospital.c
	cc hospital.c -c

