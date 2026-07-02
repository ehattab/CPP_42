/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:23:34 by ehattab           #+#    #+#             */
/*   Updated: 2026/07/02 18:15:56 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
#define DATA_H

# include <iostream>
# include <string>

class Data
{
	public:
	std::string value;
	Data();
	~Data();
	Data(std::string str);
	Data(const Data &other);
	Data& operator=(const Data &other);
};

#endif