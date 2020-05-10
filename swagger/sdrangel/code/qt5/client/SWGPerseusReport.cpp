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


#include "SWGPerseusReport.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGPerseusReport::SWGPerseusReport(QString* json) {
    init();
    this->fromJson(*json);
}

SWGPerseusReport::SWGPerseusReport() {
    sample_rates = nullptr;
    m_sample_rates_isSet = false;
}

SWGPerseusReport::~SWGPerseusReport() {
    this->cleanup();
}

void
SWGPerseusReport::init() {
    sample_rates = new QList<SWGSampleRate*>();
    m_sample_rates_isSet = false;
}

void
SWGPerseusReport::cleanup() {
    if(sample_rates != nullptr) { 
        auto arr = sample_rates;
        for(auto o: *arr) { 
            delete o;
        }
        delete sample_rates;
    }
}

SWGPerseusReport*
SWGPerseusReport::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGPerseusReport::fromJsonObject(QJsonObject &pJson) {
    
    ::SWGSDRangel::setValue(&sample_rates, pJson["sampleRates"], "QList", "SWGSampleRate");
}

QString
SWGPerseusReport::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGPerseusReport::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(sample_rates && sample_rates->size() > 0){
        toJsonArray((QList<void*>*)sample_rates, obj, "sampleRates", "SWGSampleRate");
    }

    return obj;
}

QList<SWGSampleRate*>*
SWGPerseusReport::getSampleRates() {
    return sample_rates;
}
void
SWGPerseusReport::setSampleRates(QList<SWGSampleRate*>* sample_rates) {
    this->sample_rates = sample_rates;
    this->m_sample_rates_isSet = true;
}


bool
SWGPerseusReport::isSet(){
    bool isObjectUpdated = false;
    do{
        if(sample_rates && (sample_rates->size() > 0)){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

