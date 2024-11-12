/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:06:00 by afont             #+#    #+#             */
/*   Updated: 2024/08/07 14:36:22 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class	Contact
{
	private:
		std::string	FirstName;
		std::string	LastName;
		std::string	NickName;
		std::string	PhoneNumber;
		std::string	DarkestSecret;
	public:
		Contact();
		~Contact();
		std::string&	GetFname(void);
		std::string&	GetLname(void);
		std::string&	GetNname(void);
		std::string&	GetPnumber(void);
		std::string&	GetDsecret(void);
		int				Init(void);
		void			DisplayOne(int index);
		void			Glimpse(int index);
		int				IsEmpty(void);
		int				OneEmpty(std::string _Contacts[5]);
};

#endif