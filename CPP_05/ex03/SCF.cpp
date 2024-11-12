/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SCF.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:01:22 by afont             #+#    #+#             */
/*   Updated: 2024/09/02 10:14:08 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SCF.hpp"

SCF::SCF(const std::string &target) : AForm("SCF", 145, 137), _target(target)
{
}

SCF::~SCF(void)
{
}

std::string	SCF::getTarget(void) const
{
	return (this->_target);
}

void	SCF::execute(const Bureaucrat &bureaucrat) const
{
	if (!getSigned())
		throw AForm::NotSignedException();
	if (bureaucrat.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream file((getTarget() + "_shrubbery").c_str());
	if (file.is_open())
	{
		file << "    /\\" << std::endl;
		file << "   /  \\" << std::endl;
		file << "  /    \\" << std::endl;
		file << " /______\\" << std::endl;
		file << "    ||" << std::endl;
		file << "    ||" << std::endl;
		file.close();
	}
	else
		throw std::runtime_error("Unable to open file");
}
