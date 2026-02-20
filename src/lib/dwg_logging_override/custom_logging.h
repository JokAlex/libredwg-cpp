#ifndef CUSTOM_LOGGING_H
#define CUSTOM_LOGGING_H

#include <dwg_logging.h>

#include <stdio.h>
#include <string.h>

#undef LOG
#undef LOG_ERROR
#undef LOG_WARN

extern Logger dwg_logger;

#define LOG(level, ...)                                                        \
  {                                                                            \
    dwg_logger(DWG_LOGLEVEL_##level, DWG_LOGLEVEL, false, __VA_ARGS__);        \
  }
#define LOG_ERROR(...)                                                         \
  {                                                                            \
    dwg_logger(DWG_LOGLEVEL_ERROR, DWG_LOGLEVEL, true, __VA_ARGS__);           \
  }
#define LOG_WARN(...)                                                          \
  {                                                                            \
    dwg_logger(DWG_LOGLEVEL_ERROR, DWG_LOGLEVEL, false, __VA_ARGS__);          \
  }

#endif
