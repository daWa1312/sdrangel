///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2012 maintech GmbH, Otto-Hahn-Str. 15, 97204 Hoechberg, Germany //
// written by Christian Daniel                                                   //
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

#ifndef INCLUDE_MAINWINDOW_H
#define INCLUDE_MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QList>

#include "settings/mainsettings.h"
#include "util/message.h"
#include "util/messagequeue.h"
#include "export.h"
#include "mainparser.h"

class QLabel;
class QTreeWidgetItem;
class QDir;

class DSPEngine;
class DSPDeviceSourceEngine;
class DSPDeviceSinkEngine;
class Indicator;
class GLSpectrumGUI;
class PluginAPI;
class PluginInstanceGUI;
class ChannelGUI;
class ChannelMarker;
class PluginManager;
class DeviceAPI;
class DeviceUISet;
class FeatureUISet;
class PluginInterface;
class QWidget;
class WebAPIRequestMapper;
class WebAPIServer;
class WebAPIAdapterGUI;
class Preset;
class Command;
class FeatureSetPreset;
class CommandKeyReceiver;

namespace qtwebapp {
    class LoggerWithFile;
}

namespace Ui {
	class MainWindow;
}

class SDRGUI_API MainWindow : public QMainWindow {
	Q_OBJECT

public:
	class MsgDeviceSetFocus : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        int getDeviceSetIndex() const { return m_deviceSetIndex; }

        static MsgDeviceSetFocus* create(int deviceSetIndex)
        {
            return new MsgDeviceSetFocus(deviceSetIndex);
        }

    private:
        int m_deviceSetIndex;

        MsgDeviceSetFocus(int deviceSetIndex) :
            Message(),
            m_deviceSetIndex(deviceSetIndex)
        { }
    };

	explicit MainWindow(qtwebapp::LoggerWithFile *logger, const MainParser& parser, QWidget* parent = 0);
	~MainWindow();
	static MainWindow *getInstance() { return m_instance; } // Main Window is de facto a singleton so this just returns its reference

	MessageQueue* getInputMessageQueue() { return &m_inputMessageQueue; }

	void addViewAction(QAction* action);

	void setDeviceGUI(int deviceTabIndex, QWidget* gui, const QString& deviceDisplayName, int deviceType = 0);

	const QTimer& getMasterTimer() const { return m_masterTimer; }
	const MainSettings& getMainSettings() const { return m_settings; }
    const PluginManager *getPluginManager() const { return m_pluginManager; }
    std::vector<DeviceUISet*>& getDeviceUISets() { return m_deviceUIs; }
    void commandKeysConnect(QObject *object, const char *slot);
    void commandKeysDisconnect(QObject *object, const char *slot);
    const QString& getAPIHost() const { return m_apiHost; }
	int getAPIPort() const { return m_apiPort; }

	friend class WebAPIAdapterGUI;

private:
    class MsgLoadPreset : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const Preset *getPreset() const { return m_preset; }
        int getDeviceSetIndex() const { return m_deviceSetIndex; }

        static MsgLoadPreset* create(const Preset *preset, int deviceSetIndex)
        {
            return new MsgLoadPreset(preset, deviceSetIndex);
        }

    private:
        const Preset *m_preset;
        int m_deviceSetIndex;

        MsgLoadPreset(const Preset *preset, int deviceSetIndex) :
            Message(),
            m_preset(preset),
            m_deviceSetIndex(deviceSetIndex)
        { }
    };

    class MsgSavePreset : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        Preset *getPreset() const { return m_preset; }
        int getDeviceSetIndex() const { return m_deviceSetIndex; }
        bool isNewPreset() const { return m_newPreset; }

        static MsgSavePreset* create(Preset *preset, int deviceSetIndex, bool newPreset)
        {
            return new MsgSavePreset(preset, deviceSetIndex, newPreset);
        }

    private:
        Preset *m_preset;
        int m_deviceSetIndex;
        bool m_newPreset;

        MsgSavePreset(Preset *preset, int deviceSetIndex, bool newPreset) :
            Message(),
            m_preset(preset),
            m_deviceSetIndex(deviceSetIndex),
            m_newPreset(newPreset)
        { }
    };

    class MsgDeletePreset : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const Preset *getPreset() const { return m_preset; }

        static MsgDeletePreset* create(const Preset *preset)
        {
            return new MsgDeletePreset(preset);
        }

    private:
        const Preset *m_preset;

        MsgDeletePreset(const Preset *preset) :
            Message(),
            m_preset(preset)
        { }
    };

    class MsgLoadFeatureSetPreset : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const FeatureSetPreset *getPreset() const { return m_preset; }
        int getFeatureSetIndex() const { return m_featureSetIndex; }

        static MsgLoadFeatureSetPreset* create(const FeatureSetPreset *preset, int featureSetIndex)
        {
            return new MsgLoadFeatureSetPreset(preset, featureSetIndex);
        }

    private:
        const FeatureSetPreset *m_preset;
        int m_featureSetIndex;

        MsgLoadFeatureSetPreset(const FeatureSetPreset *preset, int featureSetIndex) :
            Message(),
            m_preset(preset),
            m_featureSetIndex(featureSetIndex)
        { }
    };

    class MsgSaveFeatureSetPreset : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        FeatureSetPreset *getPreset() const { return m_preset; }
        int getFeatureSetIndex() const { return m_featureSetIndex; }
        bool isNewPreset() const { return m_newPreset; }

        static MsgSaveFeatureSetPreset* create(FeatureSetPreset *preset, int featureSetIndex, bool newPreset)
        {
            return new MsgSaveFeatureSetPreset(preset, featureSetIndex, newPreset);
        }

    private:
        FeatureSetPreset *m_preset;
        int m_featureSetIndex;
        bool m_newPreset;

        MsgSaveFeatureSetPreset(FeatureSetPreset *preset, int featureSetIndex, bool newPreset) :
            Message(),
            m_preset(preset),
            m_featureSetIndex(featureSetIndex),
            m_newPreset(newPreset)
        { }
    };

    class MsgDeleteFeatureSetPreset : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const FeatureSetPreset *getPreset() const { return m_preset; }

        static MsgDeleteFeatureSetPreset* create(const FeatureSetPreset *preset)
        {
            return new MsgDeleteFeatureSetPreset(preset);
        }

    private:
        const FeatureSetPreset *m_preset;

        MsgDeleteFeatureSetPreset(const FeatureSetPreset *preset) :
            Message(),
            m_preset(preset)
        { }
    };

    class MsgAddDeviceSet : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        int getDirection() const { return m_direction; }

        static MsgAddDeviceSet* create(int direction)
        {
            return new MsgAddDeviceSet(direction);
        }

    private:
        int m_direction;

        MsgAddDeviceSet(int direction) :
            Message(),
            m_direction(direction)
        { }
    };

    class MsgRemoveLastDeviceSet : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        static MsgRemoveLastDeviceSet* create()
        {
            return new MsgRemoveLastDeviceSet();
        }

    private:
        MsgRemoveLastDeviceSet() :
            Message()
        { }
    };

    class MsgSetDevice : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        int getDeviceSetIndex() const { return m_deviceSetIndex; }
        int getDeviceIndex() const { return m_deviceIndex; }
        int getDeviceType() const { return m_deviceType; }

        static MsgSetDevice* create(int deviceSetIndex, int deviceIndex, int deviceType)
        {
            return new MsgSetDevice(deviceSetIndex, deviceIndex, deviceType);
        }

    private:
        int m_deviceSetIndex;
        int m_deviceIndex;
        int m_deviceType;

        MsgSetDevice(int deviceSetIndex, int deviceIndex, int deviceType) :
            Message(),
            m_deviceSetIndex(deviceSetIndex),
            m_deviceIndex(deviceIndex),
            m_deviceType(deviceType)
        { }
    };

    class MsgAddChannel : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        int getDeviceSetIndex() const { return m_deviceSetIndex; }
        int getChannelRegistrationIndex() const { return m_channelRegistrationIndex; }
        bool isTx() const { return m_tx; }

        static MsgAddChannel* create(int deviceSetIndex, int channelRegistrationIndex, bool tx)
        {
            return new MsgAddChannel(deviceSetIndex, channelRegistrationIndex, tx);
        }

    private:
        int m_deviceSetIndex;
        int m_channelRegistrationIndex;
        bool m_tx;

        MsgAddChannel(int deviceSetIndex, int channelRegistrationIndex, bool tx) :
            Message(),
            m_deviceSetIndex(deviceSetIndex),
            m_channelRegistrationIndex(channelRegistrationIndex),
            m_tx(tx)
        { }
    };

    class MsgDeleteChannel : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        int getDeviceSetIndex() const { return m_deviceSetIndex; }
        int getChannelIndex() const { return m_channelIndex; }

        static MsgDeleteChannel* create(int deviceSetIndex, int channelIndex)
        {
            return new MsgDeleteChannel(deviceSetIndex, channelIndex);
        }

    private:
        int m_deviceSetIndex;
        int m_channelIndex;

        MsgDeleteChannel(int deviceSetIndex, int channelIndex) :
            Message(),
            m_deviceSetIndex(deviceSetIndex),
            m_channelIndex(channelIndex)
        { }
    };

    class MsgAddFeature : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        int getFeatureSetIndex() const { return m_featureSetIndex; }
        int getFeatureRegistrationIndex() const { return m_featureRegistrationIndex; }

        static MsgAddFeature* create(int featureSetIndex, int featureRegistrationIndex)
        {
            return new MsgAddFeature(featureSetIndex, featureRegistrationIndex);
        }

    private:
        int m_featureSetIndex;
        int m_featureRegistrationIndex;

        MsgAddFeature(int featureSetIndex, int featureRegistrationIndex) :
            Message(),
            m_featureSetIndex(featureSetIndex),
            m_featureRegistrationIndex(featureRegistrationIndex)
        { }
    };

    class MsgDeleteFeature : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        int getFeatureSetIndex() const { return m_featureSetIndex; }
        int getFeatureIndex() const { return m_featureIndex; }

        static MsgDeleteFeature* create(int m_featureSetIndex, int m_featureIndex) {
            return new MsgDeleteFeature(m_featureSetIndex, m_featureIndex);
        }

    private:
        int m_featureSetIndex;
        int m_featureIndex;

        MsgDeleteFeature(int m_featureSetIndex, int m_featureIndex) :
            Message(),
            m_featureSetIndex(m_featureSetIndex),
            m_featureIndex(m_featureIndex)
        { }
    };

    enum {
		PGroup,
		PItem
	};

	struct DeviceWidgetTabData
	{
	    QWidget *gui;
	    QString displayName;
	    QString tabName;
	};

    class MsgApplySettings : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        static MsgApplySettings* create() {
            return new MsgApplySettings();
        }

    private:
        MsgApplySettings() :
            Message()
        { }
    };

	static MainWindow *m_instance;
	Ui::MainWindow* ui;
	MessageQueue m_inputMessageQueue;
	MainSettings m_settings;
	std::vector<DeviceUISet*> m_deviceUIs;
    std::vector<FeatureUISet*> m_featureUIs;
	QList<DeviceWidgetTabData> m_deviceWidgetTabs;
	int m_masterTabIndex;

	DSPEngine* m_dspEngine;
	PluginManager* m_pluginManager;

	QTimer m_masterTimer;
	QTimer m_statusTimer;
	int m_lastEngineState;

	QLabel* m_dateTimeWidget;
	QLabel* m_showSystemWidget;

	QWidget* m_inputGUI;

	int m_sampleRate;
	quint64 m_centerFrequency;
	std::string m_sampleFileName;

	qtwebapp::LoggerWithFile *m_logger;

	WebAPIRequestMapper *m_requestMapper;
	WebAPIServer *m_apiServer;
	WebAPIAdapterGUI *m_apiAdapter;
	QString m_apiHost;
	int m_apiPort;

	CommandKeyReceiver *m_commandKeyReceiver;

	void loadSettings();
	void loadPresetSettings(const Preset* preset, int tabIndex);
	void savePresetSettings(Preset* preset, int tabIndex);
	void loadFeatureSetPresetSettings(const FeatureSetPreset* preset, int featureSetIndex);
	void saveFeatureSetPresetSettings(FeatureSetPreset* preset, int featureSetIndex);
	void saveCommandSettings();

	void createStatusBar();
	void closeEvent(QCloseEvent*);
	void updatePresetControls();
	QTreeWidgetItem* addPresetToTree(const Preset* preset);
	QTreeWidgetItem* addCommandToTree(const Command* command);
	void applySettings();

	void addSourceDevice(int deviceIndex);
	void addSinkDevice();
    void removeLastDevice();
    void addFeatureSet();
    void removeFeatureSet(int tabIndex);
    void removeAllFeatureSets();
    void deleteChannel(int deviceSetIndex, int channelIndex);
    void sampleSourceChanged(int tabIndex, int newDeviceIndex);
	void sampleSinkChanged(int tabIndex, int newDeviceIndex);
    void deleteFeature(int featureSetIndex, int featureIndex);

    void setLoggingOptions();

    bool handleMessage(const Message& cmd);

private slots:
	void handleMessages();
	void updateStatus();
	void on_action_View_Fullscreen_toggled(bool checked);
	void on_presetSave_clicked();
	void on_presetUpdate_clicked();
    void on_presetEdit_clicked();
	void on_presetExport_clicked();
	void on_presetImport_clicked();
	void on_settingsSave_clicked();
	void on_presetLoad_clicked();
	void on_presetDelete_clicked();
	void on_presetTree_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);
	void on_presetTree_itemActivated(QTreeWidgetItem *item, int column);
	void on_commandNew_clicked();
    void on_commandDuplicate_clicked();
    void on_commandEdit_clicked();
    void on_commandDelete_clicked();
    void on_commandRun_clicked();
    void on_commandOutput_clicked();
    void on_commandsSave_clicked();
    void on_commandKeyboardConnect_toggled(bool checked);
	void on_action_Audio_triggered();
    void on_action_Logging_triggered();
    void on_action_AMBE_triggered();
    void on_action_LimeRFE_triggered();
	void on_action_My_Position_triggered();
    void on_action_DeviceUserArguments_triggered();
    void samplingDeviceChanged(int deviceType, int tabIndex, int newDeviceIndex);
    void channelAddClicked(int channelIndex);
    void featureAddClicked(int featureIndex);
	void on_action_Loaded_Plugins_triggered();
	void on_action_About_triggered();
	void on_action_addSourceDevice_triggered();
	void on_action_addSinkDevice_triggered();
    void on_action_addMIMODevice_triggered();
	void on_action_removeLastDevice_triggered();
	void tabInputViewIndexChanged();
    void tabChannelsIndexChanged();
	void commandKeyPressed(Qt::Key key, Qt::KeyboardModifiers keyModifiers, bool release);
    void handleClosingRxChannelGUI(DeviceUISet *deviceUISet, ChannelGUI *gui);
    void handleClosingTxChannelGUI(DeviceUISet *deviceUISet, ChannelGUI *gui);
    void handleClosingMIMOChannelGUI(DeviceUISet *deviceUISet, ChannelGUI *gui);
};

#endif // INCLUDE_MAINWINDOW_H
