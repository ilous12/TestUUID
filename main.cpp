#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

unsigned char random_char() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 255);
  return static_cast<unsigned char>(dis(gen));
}

std::string generate_hex(const unsigned int len) {
  std::stringstream ss;
  for (auto i = 0; i < len; i++) {
    const auto rc = random_char();
    std::stringstream hexstream;
    hexstream << std::hex << int(rc);
    auto hex = hexstream.str();
    ss << (hex.length() < 2 ? '0' + hex : hex);
  }
  return ss.str();
}

std::string generate_uuid() {
  std::stringstream ss;
  ss << generate_hex(4) << "-";
  ss << generate_hex(2) << "-";
  ss << generate_hex(2) << "-";
  ss << generate_hex(2) << "-";
  ss << generate_hex(6);
  return ss.str();
}

int main() {
  for (auto i = 0; i < 5; i++) {
    std::cout << generate_uuid() << std::endl;
  }
}