///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2018 Edouard Griffiths, F4EXB                                   //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#include <QtPlugin>

#include "plugin/pluginapi.h"
#include "util/simpleserializer.h"
#include "device/devicesourceapi.h"
#include "soapysdr/devicesoapysdr.h"

#include "soapysdroutputplugin.h"

#ifdef SERVER_MODE
#include "soapysdroutput.h"
#else
#include "soapysdroutputgui.h"
#endif

const PluginDescriptor SoapySDROutputPlugin::m_pluginDescriptor = {
    QString("SoapySDR Output"),
    QString("4.3.0"),
    QString("(c) Edouard Griffiths, F4EXB"),
    QString("https://github.com/f4exb/sdrangel"),
    true,
    QString("https://github.com/f4exb/sdrangel")
};

const QString SoapySDROutputPlugin::m_hardwareID = "SoapySDR";
const QString SoapySDROutputPlugin::m_deviceTypeID = SOAPYSDROUTPUT_DEVICE_TYPE_ID;

SoapySDROutputPlugin::SoapySDROutputPlugin(QObject* parent) :
    QObject(parent)
{
}

const PluginDescriptor& SoapySDROutputPlugin::getPluginDescriptor() const
{
    return m_pluginDescriptor;
}

void SoapySDROutputPlugin::initPlugin(PluginAPI* pluginAPI)
{
    pluginAPI->registerSampleSink(m_deviceTypeID, this);
}

PluginInterface::SamplingDevices SoapySDROutputPlugin::enumSampleSinks()
{
    SamplingDevices result;
    DeviceSoapySDR& deviceSoapySDR = DeviceSoapySDR::instance();
    const std::vector<DeviceSoapySDRScan::SoapySDRDeviceEnum>& devicesEnumeration = deviceSoapySDR.getDevicesEnumeration();
    qDebug("SoapySDRInputPlugin::enumSampleSources: found %lu devices", devicesEnumeration.size());
    std::vector<DeviceSoapySDRScan::SoapySDRDeviceEnum>::const_iterator it = devicesEnumeration.begin();

    for (int idev = 0; it != devicesEnumeration.end(); ++it, idev++)
    {
        unsigned int nbTxChannels = it->m_nbTx;

        for (unsigned int ichan = 0; ichan < nbTxChannels; ichan++)
        {
            qDebug("SoapySDROutputPlugin::enumSampleSinks: device #%d (%s) channel %u", idev, it->m_label, ichan);
            QString displayedName(QString("SoapySDR[%1:%2] %3").arg(idev).arg(ichan).arg(it->m_label));
            result.append(SamplingDevice(displayedName,
                    m_hardwareID,
                    m_deviceTypeID,
                    it->m_idValue,
                    idev,
                    PluginInterface::SamplingDevice::PhysicalDevice,
                    false,
                    nbTxChannels,
                    ichan));
        }
    }

    return result;
}

#ifdef SERVER_MODE
PluginInstanceGUI* SoapySDROutputPlugin::createSampleSinkPluginInstanceGUI(
        const QString& sinkId __attribute__((unused)),
        QWidget **widget __attribute__((unused)),
        DeviceUISet *deviceUISet __attribute__((unused)))
{
    return 0;
}
#else
PluginInstanceGUI* SoapySDROutputPlugin::createSampleSinkPluginInstanceGUI(
        const QString& sinkId,
        QWidget **widget,
        DeviceUISet *deviceUISet)
{
    if(sinkId == m_deviceTypeID)
    {
        SoapySDROutputGui* gui = new SoapySDROutputGui(deviceUISet);
        *widget = gui;
        return gui;
    }
    else
    {
        return 0;
    }
}
#endif

DeviceSampleSink* SoapySDROutputPlugin::createSampleSinkPluginInstanceOutput(const QString& sinkId, DeviceSinkAPI *deviceAPI)
{
    if(sinkId == m_deviceTypeID)
    {
        SoapySDROutput* output = new SoapySDROutput(deviceAPI);
        return output;
    }
    else
    {
        return 0;
    }
}





