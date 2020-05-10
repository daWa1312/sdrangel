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


#include "SWGDVSerialDevices.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGDVSerialDevices::SWGDVSerialDevices(QString* json) {
    init();
    this->fromJson(*json);
}

SWGDVSerialDevices::SWGDVSerialDevices() {
    nb_devices = 0;
    m_nb_devices_isSet = false;
    dv_serial_devices = nullptr;
    m_dv_serial_devices_isSet = false;
}

SWGDVSerialDevices::~SWGDVSerialDevices() {
    this->cleanup();
}

void
SWGDVSerialDevices::init() {
    nb_devices = 0;
    m_nb_devices_isSet = false;
    dv_serial_devices = new QList<SWGDVSerialDevice*>();
    m_dv_serial_devices_isSet = false;
}

void
SWGDVSerialDevices::cleanup() {

    if(dv_serial_devices != nullptr) { 
        auto arr = dv_serial_devices;
        for(auto o: *arr) { 
            delete o;
        }
        delete dv_serial_devices;
    }
}

SWGDVSerialDevices*
SWGDVSerialDevices::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGDVSerialDevices::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&nb_devices, pJson["nbDevices"], "qint32", "");
    
    
    ::SWGSDRangel::setValue(&dv_serial_devices, pJson["dvSerialDevices"], "QList", "SWGDVSerialDevice");
}

QString
SWGDVSerialDevices::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGDVSerialDevices::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_nb_devices_isSet){
        obj->insert("nbDevices", QJsonValue(nb_devices));
    }
    if(dv_serial_devices && dv_serial_devices->size() > 0){
        toJsonArray((QList<void*>*)dv_serial_devices, obj, "dvSerialDevices", "SWGDVSerialDevice");
    }

    return obj;
}

qint32
SWGDVSerialDevices::getNbDevices() {
    return nb_devices;
}
void
SWGDVSerialDevices::setNbDevices(qint32 nb_devices) {
    this->nb_devices = nb_devices;
    this->m_nb_devices_isSet = true;
}

QList<SWGDVSerialDevice*>*
SWGDVSerialDevices::getDvSerialDevices() {
    return dv_serial_devices;
}
void
SWGDVSerialDevices::setDvSerialDevices(QList<SWGDVSerialDevice*>* dv_serial_devices) {
    this->dv_serial_devices = dv_serial_devices;
    this->m_dv_serial_devices_isSet = true;
}


bool
SWGDVSerialDevices::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_nb_devices_isSet){
            isObjectUpdated = true; break;
        }
        if(dv_serial_devices && (dv_serial_devices->size() > 0)){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

