/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SCF.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:01:07 by afont             #+#    #+#             */
/*   Updated: 2024/09/02 10:22:00 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCF_HPP
# define SCF_HPP

#include "AForm.hpp"
#include <fstream>

class Bureaucrat;

class SCF : public AForm
{
	private:
		const std::string	_target;
	public:
		SCF(const std::string &target);
		~SCF(void);
		std::string	getTarget(void) const;
		void	execute(const Bureaucrat &bureaucrat) const;
};

#endif