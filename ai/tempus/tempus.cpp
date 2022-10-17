#include "tempus.h"

// 19:00:00PM
// 1666026014

int tempo() {
  // timer object and year 2k (2000).
  time_t timer;
  struct tm y2k = {0};
  y2k.tm_hour = 19;   y2k.tm_min = 0; y2k.tm_sec = 0;
  y2k.tm_year = 122; y2k.tm_mon = 10; y2k.tm_mday = 17;
  time(&timer);  /* get current time; same as: timer = time(NULL)  */
  seconds = difftime(timer,mktime(&y2k));
  minutes = seconds / 60.0;
  timer = time(NULL);
  std::cout << std::endl;
  std::cout << timer << std::endl;
  std::cout << int(seconds) << "(seconds) since January 17, 2022 in the current timezone" << std::endl;
  std::cout << std::endl;
  return 0;
}