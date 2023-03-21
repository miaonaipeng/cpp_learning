//
// Created by naipe on 2023/3/21.
//

#include <iostream>

class Log {
public:
  // 定义常量增加代码可读性；
  const int LogLevelError = 0;
  const int LogLevelWarning = 1;
  const int LogLevelInfo = 2;

private:
  int m_LogLevel = LogLevelInfo; // 表示所有都应该被打印

public:
  // 设置警告级别
  void SetLevel(int level) { m_LogLevel = level; }
  // 打印消息
  void Error(const char *message) {
    if (m_LogLevel >= LogLevelError) {
      std::cout << "[ERROR]: " << message << std::endl;
    }
  }
  void Warn(const char *message) {
    if (m_LogLevel >= LogLevelWarning) {
      std::cout << "[WARNING]: " << message << std::endl;
    }
  }
  void Info(const char *message) {
    if (m_LogLevel >= LogLevelInfo) {
      std::cout << "[INFO]: " << message << std::endl;
    }
  }
};

int main() {
  Log log;
  log.SetLevel(log.LogLevelError);
  log.Error("hello");
  log.Warn("hello");
  log.Info("hello");
  return 0;
}