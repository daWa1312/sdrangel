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


#include "SWGRtlSdrSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGRtlSdrSettings::SWGRtlSdrSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGRtlSdrSettings::SWGRtlSdrSettings() {
    dev_sample_rate = 0;
    m_dev_sample_rate_isSet = false;
    low_sample_rate = 0;
    m_low_sample_rate_isSet = false;
    center_frequency = 0L;
    m_center_frequency_isSet = false;
    gain = 0;
    m_gain_isSet = false;
    lo_ppm_correction = 0;
    m_lo_ppm_correction_isSet = false;
    log2_decim = 0;
    m_log2_decim_isSet = false;
    fc_pos = 0;
    m_fc_pos_isSet = false;
    dc_block = 0;
    m_dc_block_isSet = false;
    iq_imbalance = 0;
    m_iq_imbalance_isSet = false;
    agc = 0;
    m_agc_isSet = false;
    no_mod_mode = 0;
    m_no_mod_mode_isSet = false;
    offset_tuning = 0;
    m_offset_tuning_isSet = false;
    transverter_mode = 0;
    m_transverter_mode_isSet = false;
    transverter_delta_frequency = 0L;
    m_transverter_delta_frequency_isSet = false;
    rf_bandwidth = 0;
    m_rf_bandwidth_isSet = false;
    file_record_name = nullptr;
    m_file_record_name_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = nullptr;
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
}

SWGRtlSdrSettings::~SWGRtlSdrSettings() {
    this->cleanup();
}

void
SWGRtlSdrSettings::init() {
    dev_sample_rate = 0;
    m_dev_sample_rate_isSet = false;
    low_sample_rate = 0;
    m_low_sample_rate_isSet = false;
    center_frequency = 0L;
    m_center_frequency_isSet = false;
    gain = 0;
    m_gain_isSet = false;
    lo_ppm_correction = 0;
    m_lo_ppm_correction_isSet = false;
    log2_decim = 0;
    m_log2_decim_isSet = false;
    fc_pos = 0;
    m_fc_pos_isSet = false;
    dc_block = 0;
    m_dc_block_isSet = false;
    iq_imbalance = 0;
    m_iq_imbalance_isSet = false;
    agc = 0;
    m_agc_isSet = false;
    no_mod_mode = 0;
    m_no_mod_mode_isSet = false;
    offset_tuning = 0;
    m_offset_tuning_isSet = false;
    transverter_mode = 0;
    m_transverter_mode_isSet = false;
    transverter_delta_frequency = 0L;
    m_transverter_delta_frequency_isSet = false;
    rf_bandwidth = 0;
    m_rf_bandwidth_isSet = false;
    file_record_name = new QString("");
    m_file_record_name_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = new QString("");
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
}

void
SWGRtlSdrSettings::cleanup() {















    if(file_record_name != nullptr) { 
        delete file_record_name;
    }

    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }


}

SWGRtlSdrSettings*
SWGRtlSdrSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGRtlSdrSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&dev_sample_rate, pJson["devSampleRate"], "qint32", "");
    
    ::SWGSDRangel::setValue(&low_sample_rate, pJson["lowSampleRate"], "qint32", "");
    
    ::SWGSDRangel::setValue(&center_frequency, pJson["centerFrequency"], "qint64", "");
    
    ::SWGSDRangel::setValue(&gain, pJson["gain"], "qint32", "");
    
    ::SWGSDRangel::setValue(&lo_ppm_correction, pJson["loPpmCorrection"], "qint32", "");
    
    ::SWGSDRangel::setValue(&log2_decim, pJson["log2Decim"], "qint32", "");
    
    ::SWGSDRangel::setValue(&fc_pos, pJson["fcPos"], "qint32", "");
    
    ::SWGSDRangel::setValue(&dc_block, pJson["dcBlock"], "qint32", "");
    
    ::SWGSDRangel::setValue(&iq_imbalance, pJson["iqImbalance"], "qint32", "");
    
    ::SWGSDRangel::setValue(&agc, pJson["agc"], "qint32", "");
    
    ::SWGSDRangel::setValue(&no_mod_mode, pJson["noModMode"], "qint32", "");
    
    ::SWGSDRangel::setValue(&offset_tuning, pJson["offsetTuning"], "qint32", "");
    
    ::SWGSDRangel::setValue(&transverter_mode, pJson["transverterMode"], "qint32", "");
    
    ::SWGSDRangel::setValue(&transverter_delta_frequency, pJson["transverterDeltaFrequency"], "qint64", "");
    
    ::SWGSDRangel::setValue(&rf_bandwidth, pJson["rfBandwidth"], "qint32", "");
    
    ::SWGSDRangel::setValue(&file_record_name, pJson["fileRecordName"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_device_index, pJson["reverseAPIDeviceIndex"], "qint32", "");
    
}

QString
SWGRtlSdrSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGRtlSdrSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_dev_sample_rate_isSet){
        obj->insert("devSampleRate", QJsonValue(dev_sample_rate));
    }
    if(m_low_sample_rate_isSet){
        obj->insert("lowSampleRate", QJsonValue(low_sample_rate));
    }
    if(m_center_frequency_isSet){
        obj->insert("centerFrequency", QJsonValue(center_frequency));
    }
    if(m_gain_isSet){
        obj->insert("gain", QJsonValue(gain));
    }
    if(m_lo_ppm_correction_isSet){
        obj->insert("loPpmCorrection", QJsonValue(lo_ppm_correction));
    }
    if(m_log2_decim_isSet){
        obj->insert("log2Decim", QJsonValue(log2_decim));
    }
    if(m_fc_pos_isSet){
        obj->insert("fcPos", QJsonValue(fc_pos));
    }
    if(m_dc_block_isSet){
        obj->insert("dcBlock", QJsonValue(dc_block));
    }
    if(m_iq_imbalance_isSet){
        obj->insert("iqImbalance", QJsonValue(iq_imbalance));
    }
    if(m_agc_isSet){
        obj->insert("agc", QJsonValue(agc));
    }
    if(m_no_mod_mode_isSet){
        obj->insert("noModMode", QJsonValue(no_mod_mode));
    }
    if(m_offset_tuning_isSet){
        obj->insert("offsetTuning", QJsonValue(offset_tuning));
    }
    if(m_transverter_mode_isSet){
        obj->insert("transverterMode", QJsonValue(transverter_mode));
    }
    if(m_transverter_delta_frequency_isSet){
        obj->insert("transverterDeltaFrequency", QJsonValue(transverter_delta_frequency));
    }
    if(m_rf_bandwidth_isSet){
        obj->insert("rfBandwidth", QJsonValue(rf_bandwidth));
    }
    if(file_record_name != nullptr && *file_record_name != QString("")){
        toJsonValue(QString("fileRecordName"), file_record_name, obj, QString("QString"));
    }
    if(m_use_reverse_api_isSet){
        obj->insert("useReverseAPI", QJsonValue(use_reverse_api));
    }
    if(reverse_api_address != nullptr && *reverse_api_address != QString("")){
        toJsonValue(QString("reverseAPIAddress"), reverse_api_address, obj, QString("QString"));
    }
    if(m_reverse_api_port_isSet){
        obj->insert("reverseAPIPort", QJsonValue(reverse_api_port));
    }
    if(m_reverse_api_device_index_isSet){
        obj->insert("reverseAPIDeviceIndex", QJsonValue(reverse_api_device_index));
    }

    return obj;
}

qint32
SWGRtlSdrSettings::getDevSampleRate() {
    return dev_sample_rate;
}
void
SWGRtlSdrSettings::setDevSampleRate(qint32 dev_sample_rate) {
    this->dev_sample_rate = dev_sample_rate;
    this->m_dev_sample_rate_isSet = true;
}

qint32
SWGRtlSdrSettings::getLowSampleRate() {
    return low_sample_rate;
}
void
SWGRtlSdrSettings::setLowSampleRate(qint32 low_sample_rate) {
    this->low_sample_rate = low_sample_rate;
    this->m_low_sample_rate_isSet = true;
}

qint64
SWGRtlSdrSettings::getCenterFrequency() {
    return center_frequency;
}
void
SWGRtlSdrSettings::setCenterFrequency(qint64 center_frequency) {
    this->center_frequency = center_frequency;
    this->m_center_frequency_isSet = true;
}

qint32
SWGRtlSdrSettings::getGain() {
    return gain;
}
void
SWGRtlSdrSettings::setGain(qint32 gain) {
    this->gain = gain;
    this->m_gain_isSet = true;
}

qint32
SWGRtlSdrSettings::getLoPpmCorrection() {
    return lo_ppm_correction;
}
void
SWGRtlSdrSettings::setLoPpmCorrection(qint32 lo_ppm_correction) {
    this->lo_ppm_correction = lo_ppm_correction;
    this->m_lo_ppm_correction_isSet = true;
}

qint32
SWGRtlSdrSettings::getLog2Decim() {
    return log2_decim;
}
void
SWGRtlSdrSettings::setLog2Decim(qint32 log2_decim) {
    this->log2_decim = log2_decim;
    this->m_log2_decim_isSet = true;
}

qint32
SWGRtlSdrSettings::getFcPos() {
    return fc_pos;
}
void
SWGRtlSdrSettings::setFcPos(qint32 fc_pos) {
    this->fc_pos = fc_pos;
    this->m_fc_pos_isSet = true;
}

qint32
SWGRtlSdrSettings::getDcBlock() {
    return dc_block;
}
void
SWGRtlSdrSettings::setDcBlock(qint32 dc_block) {
    this->dc_block = dc_block;
    this->m_dc_block_isSet = true;
}

qint32
SWGRtlSdrSettings::getIqImbalance() {
    return iq_imbalance;
}
void
SWGRtlSdrSettings::setIqImbalance(qint32 iq_imbalance) {
    this->iq_imbalance = iq_imbalance;
    this->m_iq_imbalance_isSet = true;
}

qint32
SWGRtlSdrSettings::getAgc() {
    return agc;
}
void
SWGRtlSdrSettings::setAgc(qint32 agc) {
    this->agc = agc;
    this->m_agc_isSet = true;
}

qint32
SWGRtlSdrSettings::getNoModMode() {
    return no_mod_mode;
}
void
SWGRtlSdrSettings::setNoModMode(qint32 no_mod_mode) {
    this->no_mod_mode = no_mod_mode;
    this->m_no_mod_mode_isSet = true;
}

qint32
SWGRtlSdrSettings::getOffsetTuning() {
    return offset_tuning;
}
void
SWGRtlSdrSettings::setOffsetTuning(qint32 offset_tuning) {
    this->offset_tuning = offset_tuning;
    this->m_offset_tuning_isSet = true;
}

qint32
SWGRtlSdrSettings::getTransverterMode() {
    return transverter_mode;
}
void
SWGRtlSdrSettings::setTransverterMode(qint32 transverter_mode) {
    this->transverter_mode = transverter_mode;
    this->m_transverter_mode_isSet = true;
}

qint64
SWGRtlSdrSettings::getTransverterDeltaFrequency() {
    return transverter_delta_frequency;
}
void
SWGRtlSdrSettings::setTransverterDeltaFrequency(qint64 transverter_delta_frequency) {
    this->transverter_delta_frequency = transverter_delta_frequency;
    this->m_transverter_delta_frequency_isSet = true;
}

qint32
SWGRtlSdrSettings::getRfBandwidth() {
    return rf_bandwidth;
}
void
SWGRtlSdrSettings::setRfBandwidth(qint32 rf_bandwidth) {
    this->rf_bandwidth = rf_bandwidth;
    this->m_rf_bandwidth_isSet = true;
}

QString*
SWGRtlSdrSettings::getFileRecordName() {
    return file_record_name;
}
void
SWGRtlSdrSettings::setFileRecordName(QString* file_record_name) {
    this->file_record_name = file_record_name;
    this->m_file_record_name_isSet = true;
}

qint32
SWGRtlSdrSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGRtlSdrSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGRtlSdrSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGRtlSdrSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGRtlSdrSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGRtlSdrSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGRtlSdrSettings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGRtlSdrSettings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}


bool
SWGRtlSdrSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_dev_sample_rate_isSet){
            isObjectUpdated = true; break;
        }
        if(m_low_sample_rate_isSet){
            isObjectUpdated = true; break;
        }
        if(m_center_frequency_isSet){
            isObjectUpdated = true; break;
        }
        if(m_gain_isSet){
            isObjectUpdated = true; break;
        }
        if(m_lo_ppm_correction_isSet){
            isObjectUpdated = true; break;
        }
        if(m_log2_decim_isSet){
            isObjectUpdated = true; break;
        }
        if(m_fc_pos_isSet){
            isObjectUpdated = true; break;
        }
        if(m_dc_block_isSet){
            isObjectUpdated = true; break;
        }
        if(m_iq_imbalance_isSet){
            isObjectUpdated = true; break;
        }
        if(m_agc_isSet){
            isObjectUpdated = true; break;
        }
        if(m_no_mod_mode_isSet){
            isObjectUpdated = true; break;
        }
        if(m_offset_tuning_isSet){
            isObjectUpdated = true; break;
        }
        if(m_transverter_mode_isSet){
            isObjectUpdated = true; break;
        }
        if(m_transverter_delta_frequency_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rf_bandwidth_isSet){
            isObjectUpdated = true; break;
        }
        if(file_record_name && *file_record_name != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_use_reverse_api_isSet){
            isObjectUpdated = true; break;
        }
        if(reverse_api_address && *reverse_api_address != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_reverse_api_port_isSet){
            isObjectUpdated = true; break;
        }
        if(m_reverse_api_device_index_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

