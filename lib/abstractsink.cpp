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


#include "abstractsink.h"

AbstractSink::AbstractSink()
{

}

void AbstractSink::setProperty(VehicleProperty::Property prop, boost::any value)
{
	setPropertyCb(prop, value);
}

void AbstractSink::setSupported(PropertyList properties)
{
	mSupported = properties;
}

void AbstractSink::subscribeToProperty(VehicleProperty::Property property)
{
	subscribeToPropertyCb(property,this);
}

PropertyList AbstractSink::supported()
{
	return mSupported;
}

void AbstractSink::unsubscribeToProperty(VehicleProperty::Property property)
{
	unsubscribeToPropertyCb(property, this);
}

void AbstractSinkManager::sinkCreated(AbstractSink* sink)
{
	sinkCreatedCb(sink);
}

void AbstractSinkManager::sinkRemoved(AbstractSink* sink)
{
	sinkRemovedCb(sink);
}

void AbstractSink::setSetPropertyCb(SetPropertySignal cb)
{
	setPropertyCb = cb;
}

void AbstractSink::setSubcribeToPropertyCb(SubscriptionSignal cb)
{
	subscribeToPropertyCb = cb;
}

void AbstractSink::setUnsubscribeToPropertyCb(SubscriptionSignal cb)
{
	unsubscribeToPropertyCb = cb;
}
