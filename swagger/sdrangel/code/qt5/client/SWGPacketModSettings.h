/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 5.9.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

/*
 * SWGPacketModSettings.h
 *
 * PacketMod
 */

#ifndef SWGPacketModSettings_H_
#define SWGPacketModSettings_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGSDRangel {

class SWG_API SWGPacketModSettings: public SWGObject {
public:
    SWGPacketModSettings();
    SWGPacketModSettings(QString* json);
    virtual ~SWGPacketModSettings();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGPacketModSettings* fromJson(QString &jsonString) override;

    qint64 getInputFrequencyOffset();
    void setInputFrequencyOffset(qint64 input_frequency_offset);

    float getRfBandwidth();
    void setRfBandwidth(float rf_bandwidth);

    float getFmDeviation();
    void setFmDeviation(float fm_deviation);

    float getGain();
    void setGain(float gain);

    qint32 getChannelMute();
    void setChannelMute(qint32 channel_mute);

    qint32 getRepeat();
    void setRepeat(qint32 repeat);

    float getRepeatDelay();
    void setRepeatDelay(float repeat_delay);

    qint32 getRepeatCount();
    void setRepeatCount(qint32 repeat_count);

    qint32 getAx25PreFlags();
    void setAx25PreFlags(qint32 ax25_pre_flags);

    qint32 getAx25PostFlags();
    void setAx25PostFlags(qint32 ax25_post_flags);

    qint32 getPreEmphasis();
    void setPreEmphasis(qint32 pre_emphasis);

    float getPreEmphasisTau();
    void setPreEmphasisTau(float pre_emphasis_tau);

    float getPreEmphasisHighFreq();
    void setPreEmphasisHighFreq(float pre_emphasis_high_freq);

    qint32 getRgbColor();
    void setRgbColor(qint32 rgb_color);

    QString* getTitle();
    void setTitle(QString* title);

    qint32 getStreamIndex();
    void setStreamIndex(qint32 stream_index);

    qint32 getUseReverseApi();
    void setUseReverseApi(qint32 use_reverse_api);

    QString* getReverseApiAddress();
    void setReverseApiAddress(QString* reverse_api_address);

    qint32 getReverseApiPort();
    void setReverseApiPort(qint32 reverse_api_port);

    qint32 getReverseApiDeviceIndex();
    void setReverseApiDeviceIndex(qint32 reverse_api_device_index);

    qint32 getReverseApiChannelIndex();
    void setReverseApiChannelIndex(qint32 reverse_api_channel_index);


    virtual bool isSet() override;

private:
    qint64 input_frequency_offset;
    bool m_input_frequency_offset_isSet;

    float rf_bandwidth;
    bool m_rf_bandwidth_isSet;

    float fm_deviation;
    bool m_fm_deviation_isSet;

    float gain;
    bool m_gain_isSet;

    qint32 channel_mute;
    bool m_channel_mute_isSet;

    qint32 repeat;
    bool m_repeat_isSet;

    float repeat_delay;
    bool m_repeat_delay_isSet;

    qint32 repeat_count;
    bool m_repeat_count_isSet;

    qint32 ax25_pre_flags;
    bool m_ax25_pre_flags_isSet;

    qint32 ax25_post_flags;
    bool m_ax25_post_flags_isSet;

    qint32 pre_emphasis;
    bool m_pre_emphasis_isSet;

    float pre_emphasis_tau;
    bool m_pre_emphasis_tau_isSet;

    float pre_emphasis_high_freq;
    bool m_pre_emphasis_high_freq_isSet;

    qint32 rgb_color;
    bool m_rgb_color_isSet;

    QString* title;
    bool m_title_isSet;

    qint32 stream_index;
    bool m_stream_index_isSet;

    qint32 use_reverse_api;
    bool m_use_reverse_api_isSet;

    QString* reverse_api_address;
    bool m_reverse_api_address_isSet;

    qint32 reverse_api_port;
    bool m_reverse_api_port_isSet;

    qint32 reverse_api_device_index;
    bool m_reverse_api_device_index_isSet;

    qint32 reverse_api_channel_index;
    bool m_reverse_api_channel_index_isSet;

};

}

#endif /* SWGPacketModSettings_H_ */
