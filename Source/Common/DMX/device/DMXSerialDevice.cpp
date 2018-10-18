/*
  ==============================================================================

    DMXSerialDevice.cpp
    Created: 10 Apr 2017 10:58:01am
    Author:  Ben

  ==============================================================================
*/

#include "DMXSerialDevice.h"


DMXSerialDevice::DMXSerialDevice(const String &name, Type type, bool canReceive) :
	DMXDevice(name, type, canReceive),
	Thread("dmxRead"),
	dmxPort(nullptr),
	shouldSendData(false)
{
	startThread();

	portParam = new SerialDeviceParameter("Port", "USB Port for the DMX device", true);
	addParameter(portParam);
}

DMXSerialDevice::~DMXSerialDevice()
{
	signalThreadShouldExit(); 
	while (isThreadRunning());
	setCurrentPort(nullptr);
	
}

void DMXSerialDevice::setCurrentPort(SerialDevice * port)
{
	if (port == dmxPort) return;

	if (dmxPort != nullptr)
	{
		dmxPort->removeSerialDeviceListener(this);
	}

	dmxPort = port;

	if (dmxPort != nullptr)
	{
		dmxPort->addSerialDeviceListener(this);
		dmxPort->setMode(SerialDevice::PortMode::RAW);
		dmxPort->open();
		if (!port->isOpen())
		{
			NLOG(niceName, "Could not open port : " << port->info->port);
			dmxDeviceListeners.call(&DMXDeviceListener::dmxDeviceDisconnected);
		}
		else
		{
			NLOG(niceName, "Port connected : " << port->info->port);
			lastOpenedPortID = port->info->port;
			setPortConfig();
			dmxDeviceListeners.call(&DMXDeviceListener::dmxDeviceConnected);
		}
	}
	else
	{
		dmxDeviceListeners.call(&DMXDeviceListener::dmxDeviceDisconnected);
	}
}

void DMXSerialDevice::processIncomingData()
{
	DBG("Incoming data, process function not overriden, doing nothing.");
}

void DMXSerialDevice::sendDMXValue(int channel, int value)
{
	DMXDevice::sendDMXValue(channel, value);
	shouldSendData = true;
}


void DMXSerialDevice::run()
{
	while (!threadShouldExit())
	{
		if (dmxPort != nullptr && dmxPort->port->isOpen())
		{
			//DBG("send " << (int)dmxDataOut[0] << " / " << (int)dmxDataOut[1] << " / " << (int)dmxDataOut[2]);

			if (shouldSendData)
			{
				try
				{
					sendDMXData();
					shouldSendData = false;
				} catch (std::exception e)
				{
					DBG("Error sending DMX Data " << e.what());
				}
			}
		}

		sleep(23);
	}
}

void DMXSerialDevice::onContainerParameterChanged(Parameter * p)
{
	if (p == portParam)
	{
		setCurrentPort(portParam->getDevice());
	}
}

void DMXSerialDevice::portAdded(SerialDeviceInfo * info)
{
	if (dmxPort == nullptr && lastOpenedPortID == info->port)
	{
		setCurrentPort(SerialManager::getInstance()->getPort(info));
	}
}

void DMXSerialDevice::portRemoved(SerialDeviceInfo * /*info*/)
{
	setCurrentPort(nullptr);
}

void DMXSerialDevice::portOpened(SerialDevice *)
{
}

void DMXSerialDevice::portClosed(SerialDevice *)
{
}

void DMXSerialDevice::portRemoved(SerialDevice *)
{
	setCurrentPort(nullptr);
}

void DMXSerialDevice::serialDataReceived(const var &)
{
}