#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syslog.h>
#include <syslog.h>
#include <unistd.h>

int main(int argc, char **argv) {
  openlog(NULL, 0, LOG_USER);
  if (argc < 3) {
    syslog(LOG_ERR, "Invalid number of arguments %d", argc - 1);
    return 1;
  }

  const char *file_path = argv[1];
  const char *write_str = argv[2];

  int fd;
  ssize_t bytes_writtern;

  fd = open(file_path, O_WRONLY | O_CREAT, 0644);
  if (fd == -1) {
    perror("open failed");
    syslog(LOG_ERR, "Couldn't open file %s", file_path);
    return 1;
  }

  bytes_writtern = write(fd, write_str, strlen(write_str));
  if (bytes_writtern == -1) {
    perror("write failed");
    syslog(LOG_ERR, "Couldn't write %s to file %s", write_str, file_path);
    close(fd);
    return 1;
  }

  syslog(LOG_DEBUG, "Writing %s to %s", write_str, file_path);
  close(fd);

  return 0;
}
