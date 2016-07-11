/*
 * caesar_ext - extended caesar symmetric crypt
 *
 * Copyright (C) 2016  xdevelnet (xdevelnet at xdevelnet dot org)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "0.1"
#define IObuffersize 4096

char *user_key;
unsigned int seek = 0;

char current_seek (char *key, unsigned int keysize) {//TODO: Need decrypt subroutine
	if (seek == keysize+1) seek = 0;
	char retval = *(key+seek++);//TODO: it also would be good if every iteration increasing value will be incremented just for avoiding showing key at ZERO values
	return retval;
}

int main(int argc, char **argv) {
	if (argc < 2) { //TODO: getopt_long()
		fprintf(stderr, "%s\n", "Please, provide key.");
		exit(EXIT_FAILURE);
	}
	user_key = argv[1];
	FILE *fsource = stdin;
	FILE *frecord = stdout;
	if (argc > 2) {
		fsource = fopen(argv[2], "rb");
	}
	if (argc == 4) {
		frecord = fopen(argv[3], "wb");
	}

	setvbuf(stdout, NULL, _IOFBF, IObuffersize);
	setvbuf(stdin, NULL, _IOFBF, IObuffersize);

	unsigned int keylen = (int) strlen(argv[1]);
	int character;

	while ((character = getc(fsource)) != EOF) {
		putc(character+current_seek(user_key, keylen), frecord);
	}

	return EXIT_SUCCESS;
}
