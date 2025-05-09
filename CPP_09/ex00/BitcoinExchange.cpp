/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:33:18 by afont             #+#    #+#             */
/*   Updated: 2025/04/16 12:33:18 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <sstream>
#include <cctype>
#include <iomanip>
#include <cmath>
#include <limits>

BitcoinExchange::BitcoinExchange() {
    loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    this->_database = other._database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool isDigitsOnly(const std::string& str) {
    return str.find_first_not_of("0123456789") == std::string::npos;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    if (!isDigitsOnly(yearStr) || !isDigitsOnly(monthStr) || !isDigitsOnly(dayStr))
        return false;

    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeapYear ? 29 : 28))
            return false;
    }

    return true;
}

bool tryParseFloat(const std::string& str, float& result) {
    std::string trimmed = str;
    trimmed.erase(0, trimmed.find_first_not_of(" \t"));
    trimmed.erase(trimmed.find_last_not_of(" \t") + 1);
    
    if (trimmed.empty())
        return false;

    std::istringstream iss(trimmed);
    double temp;
    
    if (!(iss >> temp))
        return false;
        
    std::string remaining;
    if (iss >> remaining)
        return false;
        
    if (temp > std::numeric_limits<float>::max())
        return false;
        
    result = static_cast<float>(temp);
    return true;
}

bool BitcoinExchange::isValidValue(const float value) const {
    return value >= 0.0f && value <= 1000.0f;
}

std::string BitcoinExchange::findClosestLowerDate(const std::string& date) const {
    // std::cout << "????????: " << date << std::endl;
    if (_database.empty())
        return "";
        
    std::map<std::string, float>::const_iterator last = _database.end();
    if (!_database.empty()) {
        last--;
        if (date > last->first)
        {
            // std::cout << "!: " << (last->first) << std::endl;
            return last->first;
        }
    }
    
    std::map<std::string, float>::const_iterator it = _database.upper_bound(date);
    if (it == _database.begin())
        return "";
    --it;
    // std::cout << "?: " << (it->first) << std::endl;
    return it->first;
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;

        std::string date = line.substr(0, comma);
        std::string valueStr = line.substr(comma + 1);
        float value;

        if (!isValidDate(date) || !tryParseFloat(valueStr, value))
        {
            // std::cout << "date: " << date << ", value: " << value << std::endl;
            continue;
        }

        _database[date] = value;
    }
}

bool isWholeNumber(float num) {
    float intPart;
    return std::modf(num, &intPart) == 0.0f;
}

void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    if (_database.empty()) {
        std::cerr << "Error: database is empty." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t") + 1);

        size_t pipe = line.find('|');
        if (pipe == std::string::npos || line.empty()) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pipe);
        std::string valueStr = line.substr(pipe + 1);

        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));
        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

        if (date.empty() || valueStr.empty()) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        float value;
        if (!tryParseFloat(valueStr, value)) {
            std::cerr << "Error: invalid number." << std::endl;
            continue;
        }

        if (value < 0.0f) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000.0f) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        std::string useDate = date;
        if (_database.find(date) == _database.end()) {
            useDate = findClosestLowerDate(date);
            if (useDate.empty()) {
                std::cerr << "Error: no valid exchange rate found for " << date << std::endl;
                continue;
            }
        }

        float rate = _database[useDate];
        
        if (rate <= 0.0f || rate > std::numeric_limits<unsigned long long>::max()) {
            // std::cout << "rate: " << rate << std::endl;
            std::cerr << "Error: invalid exchange rate for " << date << std::endl;
            continue;
        }
        
        long double test = value * rate;
        if (std::isnan(test) || std::isinf(test) || test < 0.0f || test > std::numeric_limits<unsigned long long>::max()) {
            std::cerr << "Error: calculation result is invalid or unreasonable for " << date << std::endl;
            continue;
        }
        float result = value * rate;
        
        std::cout << date << " => ";
        if (isWholeNumber(value))
            std::cout << static_cast<int>(value);
        else {
            std::ostringstream oss;
            oss << std::fixed << std::setprecision(1) << value;
            std::string valueStr = oss.str();
            if (valueStr[valueStr.length() - 1] == '0' && valueStr[valueStr.length() - 2] == '.')
                std::cout << static_cast<int>(value);
            else
                std::cout << valueStr;
        }

        std::cout << " = ";
        if (isWholeNumber(result))
            std::cout << static_cast<unsigned long long>(result);
        else {
            std::ostringstream oss;
            oss << std::fixed << std::setprecision(2) << result;
            std::string resultStr = oss.str();
            
            size_t lastNonZero = resultStr.find_last_not_of('0');
            if (lastNonZero != std::string::npos && resultStr[lastNonZero] == '.')
                std::cout << resultStr.substr(0, lastNonZero);
            else if (lastNonZero != std::string::npos)
                std::cout << resultStr.substr(0, lastNonZero + 1);
            else
                std::cout << resultStr;
        }
        std::cout << std::endl;
    }
}