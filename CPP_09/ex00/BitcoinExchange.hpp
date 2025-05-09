/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:33:14 by afont             #+#    #+#             */
/*   Updated: 2025/04/16 12:33:14 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <limits>

class BitcoinExchange {
    private:
        std::map<std::string, float> _database;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        bool isValidDate(const std::string& date) const;
        bool isValidValue(const float value) const;
        std::string findClosestLowerDate(const std::string& date) const;
        void loadDatabase(const std::string& filename);
        void processInputFile(const std::string& filename);
};

#endif