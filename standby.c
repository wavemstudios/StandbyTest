/*
 * standby.c
 *
 *  Created on: 21 Sept 2016
 *      Author: steve
 *
 *      Test Standby mode
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main (void) {

	printf("Doing Standby1\n");
	fflush(stdout);

	doStandby();

	printf("Done Standby1\n");
	fflush(stdout);

	sleep(100);

	printf("Doing Standby2\n");
	fflush(stdout);

	doStandby();

	printf("Done Standby2\n");
	fflush(stdout);

	sleep(100);

	printf("Doing Standby3\n");
	fflush(stdout);

	doStandby();

	printf("Done Standby3\n");
	fflush(stdout);

}

int doStandby (void) {

	int fd = -1;
	ssize_t bytes_written = 0;

	fd = open("/sys/power/state", O_RDWR);

	if (fd < 0) {
		return -1;
	}

	bytes_written = write(fd, "standby", strlen("standby"));

	if (bytes_written < 0) {
		close(fd);
		return -1;
	}

	close(fd);
	return 0;

}
