#include "music.h"

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

static pid_t music_pid = -1;

void music_start() {
  if (music_pid > 0) return;
  music_pid = fork();
  if (music_pid < 0) {
    music_pid = -1;
    return;
  }

  if (music_pid == 0) {
    close(2);
    close(1);
    close(0);
    execlp("ffplay", "ffplay", "-nodisp", "-autoexit", "-loop", "0", "-af",
           "volume=0.1", MUSIC_PATH, (char*)NULL);
    _exit(127);
  }
}

void music_stop() {
  if (music_pid > 0) {
    kill(music_pid, SIGTERM);
    music_pid = -1;
  }
}