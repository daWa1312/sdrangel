///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Edouard Griffiths, F4EXB                                   //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#ifndef PLUGINS_CHANNELTX_LOCALSOURCE_LOCALSOURCEPLUGIN_H_
#define PLUGINS_CHANNELTX_LOCALSOURCE_LOCALSOURCEPLUGIN_H_


#include <QObject>
#include "plugin/plugininterface.h"

class DeviceUISet;
class BasebandSampleSource;

class LocalSourcePlugin : public QObject, PluginInterface {
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID "sdrangel.demod.localsource")

public:
    explicit LocalSourcePlugin(QObject* parent = 0);

    const PluginDescriptor& getPluginDescriptor() const;
    void initPlugin(PluginAPI* pluginAPI);

    virtual PluginInstanceGUI* createTxChannelGUI(DeviceUISet *deviceUISet, BasebandSampleSource *txChannel) const;
    virtual BasebandSampleSource* createTxChannelBS(DeviceAPI *deviceAPI) const;
    virtual ChannelAPI* createTxChannelCS(DeviceAPI *deviceAPI) const;
    virtual ChannelWebAPIAdapter* createChannelWebAPIAdapter() const;

private:
    static const PluginDescriptor m_pluginDescriptor;

    PluginAPI* m_pluginAPI;
};

#endif /* PLUGINS_CHANNELTX_LOCALSOURCE_LOCALSOURCEPLUGIN_H_ */
