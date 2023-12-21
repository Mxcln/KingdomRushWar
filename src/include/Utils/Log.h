/**
 * @file Log.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-11-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef LOG_H
#define LOG_H

#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

namespace krw {

enum class LogLevel { Debug, Info, Warning, Error };

class Logger {

public:
  static const std::string DEFAULT_LOG_FILENAME;

private:
public:
  static void setLogFile();

  static void setLogFile(const std::string &filename);

  static void log(LogLevel level, const std::string &message);

  static void debug(const std::string &message);

  static void info(const std::string &message);

  static void warning(const std::string &message);

  static void error(const std::string &message);

private:

  static std::string m_filename;
  static std::ofstream m_file;
};

} // namespace krw::utils
#endif // LOG_H