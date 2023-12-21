/**
 * @file Log.cpp
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-11-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <Utils/Log.h>
#include <Config.h>
#include <string>

using namespace krw;

const std::string Logger::DEFAULT_LOG_FILENAME = std::string(PROJECT_NAME) +
                                                 std::string(".log");
std::string Logger::m_filename = DEFAULT_LOG_FILENAME;
std::ofstream Logger::m_file(m_filename);

void Logger::setLogFile() { Logger::setLogFile(DEFAULT_LOG_FILENAME); }

void Logger::setLogFile(const std::string &filename) {
  // m_filename = filename;
  m_file.open(m_filename, std::ios::out | std::ios::app);
}

void Logger::log(LogLevel level, const std::string &message) {
  std::string logLevelString;
  switch (level) {
  case LogLevel::Debug:
    logLevelString = "DEBUG";
    break;
  case LogLevel::Info:
    logLevelString = "INFO";
    break;
  case LogLevel::Warning:
    logLevelString = "WARNING";
    break;
  case LogLevel::Error:
    logLevelString = "ERROR";
    break;
  }

  std::time_t currentTime = std::time(nullptr);
  std::string timestamp = std::ctime(&currentTime);
  timestamp.pop_back(); // Remove the newline character from the timestamp

  std::string logEntry =
      "[" + timestamp + "] [" + logLevelString + "] " + message;

  // std::cout << logEntry << std::endl;
  if (!m_file.is_open()) {
    m_file.open(m_filename, std::ios::out | std::ios::app);
  }
  m_file << logEntry << std::endl;
  m_file.close();
}

void Logger::debug(const std::string &message) {
  log(LogLevel::Debug, message);
}

void Logger::info(const std::string &message) { log(LogLevel::Info, message); }

void Logger::warning(const std::string &message) {
  log(LogLevel::Warning, message);
}

void Logger::error(const std::string &message) {
  log(LogLevel::Error, message);
}