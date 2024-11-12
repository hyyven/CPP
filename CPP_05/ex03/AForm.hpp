/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:01:00 by afont             #+#    #+#             */
/*   Updated: 2024/09/02 10:02:03 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
// #include "SCF.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
	public:
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		virtual ~AForm();
		std::string		getName(void) const;
		bool			getSigned(void) const;
		int				getGradeToSign(void) const;
		int				getGradeToExecute(void) const;
		void			beSigned(const Bureaucrat &bureaucrat);
		virtual void	execute(const Bureaucrat &bureaucrat) const = 0;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade is too high");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade is too low");
				}
		};
		class AlreadySignedException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Form's already signed");
				}
		};
		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Form isn't signed");
				}
		};
};

std::ostream &operator<<(std::ostream &o, AForm const &i);

#endif