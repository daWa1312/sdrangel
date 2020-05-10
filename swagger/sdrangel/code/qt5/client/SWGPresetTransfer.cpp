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


#include "SWGPresetTransfer.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGPresetTransfer::SWGPresetTransfer(QString* json) {
    init();
    this->fromJson(*json);
}

SWGPresetTransfer::SWGPresetTransfer() {
    device_set_index = 0;
    m_device_set_index_isSet = false;
    preset = nullptr;
    m_preset_isSet = false;
}

SWGPresetTransfer::~SWGPresetTransfer() {
    this->cleanup();
}

void
SWGPresetTransfer::init() {
    device_set_index = 0;
    m_device_set_index_isSet = false;
    preset = new SWGPresetIdentifier();
    m_preset_isSet = false;
}

void
SWGPresetTransfer::cleanup() {

    if(preset != nullptr) { 
        delete preset;
    }
}

SWGPresetTransfer*
SWGPresetTransfer::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGPresetTransfer::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&device_set_index, pJson["deviceSetIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&preset, pJson["preset"], "SWGPresetIdentifier", "SWGPresetIdentifier");
    
}

QString
SWGPresetTransfer::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGPresetTransfer::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_device_set_index_isSet){
        obj->insert("deviceSetIndex", QJsonValue(device_set_index));
    }
    if((preset != nullptr) && (preset->isSet())){
        toJsonValue(QString("preset"), preset, obj, QString("SWGPresetIdentifier"));
    }

    return obj;
}

qint32
SWGPresetTransfer::getDeviceSetIndex() {
    return device_set_index;
}
void
SWGPresetTransfer::setDeviceSetIndex(qint32 device_set_index) {
    this->device_set_index = device_set_index;
    this->m_device_set_index_isSet = true;
}

SWGPresetIdentifier*
SWGPresetTransfer::getPreset() {
    return preset;
}
void
SWGPresetTransfer::setPreset(SWGPresetIdentifier* preset) {
    this->preset = preset;
    this->m_preset_isSet = true;
}


bool
SWGPresetTransfer::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_device_set_index_isSet){
            isObjectUpdated = true; break;
        }
        if(preset && preset->isSet()){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

