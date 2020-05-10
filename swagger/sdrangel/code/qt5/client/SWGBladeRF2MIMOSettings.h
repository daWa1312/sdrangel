/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 5.6.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

/*
 * SWGBladeRF2MIMOSettings.h
 *
 * BladeRF2
 */

#ifndef SWGBladeRF2MIMOSettings_H_
#define SWGBladeRF2MIMOSettings_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGSDRangel {

class SWG_API SWGBladeRF2MIMOSettings: public SWGObject {
public:
    SWGBladeRF2MIMOSettings();
    SWGBladeRF2MIMOSettings(QString* json);
    virtual ~SWGBladeRF2MIMOSettings();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGBladeRF2MIMOSettings* fromJson(QString &jsonString) override;

    qint32 getDevSampleRate();
    void setDevSampleRate(qint32 dev_sample_rate);

    qint32 getLOppmTenths();
    void setLOppmTenths(qint32 l_oppm_tenths);

    qint64 getRxCenterFrequency();
    void setRxCenterFrequency(qint64 rx_center_frequency);

    qint32 getLog2Decim();
    void setLog2Decim(qint32 log2_decim);

    qint32 getFcPosRx();
    void setFcPosRx(qint32 fc_pos_rx);

    qint32 getRxBandwidth();
    void setRxBandwidth(qint32 rx_bandwidth);

    qint32 getRx0GainMode();
    void setRx0GainMode(qint32 rx0_gain_mode);

    qint32 getRx0GlobalGain();
    void setRx0GlobalGain(qint32 rx0_global_gain);

    qint32 getRx1GainMode();
    void setRx1GainMode(qint32 rx1_gain_mode);

    qint32 getRx1GlobalGain();
    void setRx1GlobalGain(qint32 rx1_global_gain);

    qint32 getRxBiasTee();
    void setRxBiasTee(qint32 rx_bias_tee);

    qint32 getDcBlock();
    void setDcBlock(qint32 dc_block);

    qint32 getIqCorrection();
    void setIqCorrection(qint32 iq_correction);

    qint32 getRxTransverterMode();
    void setRxTransverterMode(qint32 rx_transverter_mode);

    qint64 getRxTransverterDeltaFrequency();
    void setRxTransverterDeltaFrequency(qint64 rx_transverter_delta_frequency);

    qint64 getTxCenterFrequency();
    void setTxCenterFrequency(qint64 tx_center_frequency);

    qint32 getLog2Interp();
    void setLog2Interp(qint32 log2_interp);

    qint32 getFcPosTx();
    void setFcPosTx(qint32 fc_pos_tx);

    qint32 getTxBandwidth();
    void setTxBandwidth(qint32 tx_bandwidth);

    qint32 getTx0GlobalGain();
    void setTx0GlobalGain(qint32 tx0_global_gain);

    qint32 getTx1GlobalGain();
    void setTx1GlobalGain(qint32 tx1_global_gain);

    qint32 getTxBiasTee();
    void setTxBiasTee(qint32 tx_bias_tee);

    qint32 getTxTransverterMode();
    void setTxTransverterMode(qint32 tx_transverter_mode);

    qint64 getTxTransverterDeltaFrequency();
    void setTxTransverterDeltaFrequency(qint64 tx_transverter_delta_frequency);

    QString* getFileRecordName();
    void setFileRecordName(QString* file_record_name);

    qint32 getUseReverseApi();
    void setUseReverseApi(qint32 use_reverse_api);

    QString* getReverseApiAddress();
    void setReverseApiAddress(QString* reverse_api_address);

    qint32 getReverseApiPort();
    void setReverseApiPort(qint32 reverse_api_port);

    qint32 getReverseApiDeviceIndex();
    void setReverseApiDeviceIndex(qint32 reverse_api_device_index);


    virtual bool isSet() override;

private:
    qint32 dev_sample_rate;
    bool m_dev_sample_rate_isSet;

    qint32 l_oppm_tenths;
    bool m_l_oppm_tenths_isSet;

    qint64 rx_center_frequency;
    bool m_rx_center_frequency_isSet;

    qint32 log2_decim;
    bool m_log2_decim_isSet;

    qint32 fc_pos_rx;
    bool m_fc_pos_rx_isSet;

    qint32 rx_bandwidth;
    bool m_rx_bandwidth_isSet;

    qint32 rx0_gain_mode;
    bool m_rx0_gain_mode_isSet;

    qint32 rx0_global_gain;
    bool m_rx0_global_gain_isSet;

    qint32 rx1_gain_mode;
    bool m_rx1_gain_mode_isSet;

    qint32 rx1_global_gain;
    bool m_rx1_global_gain_isSet;

    qint32 rx_bias_tee;
    bool m_rx_bias_tee_isSet;

    qint32 dc_block;
    bool m_dc_block_isSet;

    qint32 iq_correction;
    bool m_iq_correction_isSet;

    qint32 rx_transverter_mode;
    bool m_rx_transverter_mode_isSet;

    qint64 rx_transverter_delta_frequency;
    bool m_rx_transverter_delta_frequency_isSet;

    qint64 tx_center_frequency;
    bool m_tx_center_frequency_isSet;

    qint32 log2_interp;
    bool m_log2_interp_isSet;

    qint32 fc_pos_tx;
    bool m_fc_pos_tx_isSet;

    qint32 tx_bandwidth;
    bool m_tx_bandwidth_isSet;

    qint32 tx0_global_gain;
    bool m_tx0_global_gain_isSet;

    qint32 tx1_global_gain;
    bool m_tx1_global_gain_isSet;

    qint32 tx_bias_tee;
    bool m_tx_bias_tee_isSet;

    qint32 tx_transverter_mode;
    bool m_tx_transverter_mode_isSet;

    qint64 tx_transverter_delta_frequency;
    bool m_tx_transverter_delta_frequency_isSet;

    QString* file_record_name;
    bool m_file_record_name_isSet;

    qint32 use_reverse_api;
    bool m_use_reverse_api_isSet;

    QString* reverse_api_address;
    bool m_reverse_api_address_isSet;

    qint32 reverse_api_port;
    bool m_reverse_api_port_isSet;

    qint32 reverse_api_device_index;
    bool m_reverse_api_device_index_isSet;

};

}

#endif /* SWGBladeRF2MIMOSettings_H_ */
