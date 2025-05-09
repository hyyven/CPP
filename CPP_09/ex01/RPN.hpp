#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <vector>
# include <iostream>
# include <sstream>
# include <cstdlib>

class RPN {
	private:
    	std::vector<int> _stack;
	public:
		RPN();
		RPN(const RPN &other);
		~RPN();
		
		bool isOperator(char c) const;
		void processOperator(char op);
		RPN &operator=(const RPN &other);
		int calculate(const std::string &expression);
		class InvalidExpressionException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class DivisionByZeroException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif