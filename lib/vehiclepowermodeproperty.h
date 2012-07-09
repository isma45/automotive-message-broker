/*
    Copyright (C) 2012  Intel Corporation

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/


#ifndef VEHICLEPOWERMODEPROPERTY_H
#define VEHICLEPOWERMODEPROPERTY_H

#include <abstractproperty.h>


class VehiclePowerModeProperty : public AbstractProperty
{

public:
	enum VehiclePowerMode
	{
		Off = 0,
		Accessory1 = 1,
		Accessory2 = 2,
		Run = 3
	};

	operator VehiclePowerMode()
	{
		return value();
	}

	VehiclePowerModeProperty& operator = (VehiclePowerMode const & mode)
	{
		setValue(mode);
		return *this;
	}

	void setValue(VehiclePowerMode mode);
	VehiclePowerMode value();

	virtual void fromGVariant(GVariant* value);
	virtual GVariant* toGVariant();
	VehiclePowerModeProperty();
	
private:
	
	VehiclePowerMode mMode;
	
};

#endif // VEHICLEPOWERMODEPROPERTY_H