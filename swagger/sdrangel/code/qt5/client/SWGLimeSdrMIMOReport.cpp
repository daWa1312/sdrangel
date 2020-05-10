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


#include "SWGLimeSdrMIMOReport.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGLimeSdrMIMOReport::SWGLimeSdrMIMOReport(QString* json) {
    init();
    this->fromJson(*json);
}

SWGLimeSdrMIMOReport::SWGLimeSdrMIMOReport() {
    hw_timestamp = 0;
    m_hw_timestamp_isSet = false;
    temperature = 0.0f;
    m_temperature_isSet = false;
    gpio_dir = 0;
    m_gpio_dir_isSet = false;
    gpio_pins = 0;
    m_gpio_pins_isSet = false;
    success_rx = 0;
    m_success_rx_isSet = false;
    stream_active_rx = 0;
    m_stream_active_rx_isSet = false;
    fifo_size_rx = 0;
    m_fifo_size_rx_isSet = false;
    fifo_fill_rx = 0;
    m_fifo_fill_rx_isSet = false;
    underrun_count_rx = 0;
    m_underrun_count_rx_isSet = false;
    overrun_count_rx = 0;
    m_overrun_count_rx_isSet = false;
    dropped_packets_count_rx = 0;
    m_dropped_packets_count_rx_isSet = false;
    link_rate_rx = 0.0f;
    m_link_rate_rx_isSet = false;
    success_tx = 0;
    m_success_tx_isSet = false;
    stream_active_tx = 0;
    m_stream_active_tx_isSet = false;
    fifo_size_tx = 0;
    m_fifo_size_tx_isSet = false;
    fifo_fill_tx = 0;
    m_fifo_fill_tx_isSet = false;
    underrun_count_tx = 0;
    m_underrun_count_tx_isSet = false;
    overrun_count_tx = 0;
    m_overrun_count_tx_isSet = false;
    dropped_packets_count_tx = 0;
    m_dropped_packets_count_tx_isSet = false;
    link_rate_tx = 0.0f;
    m_link_rate_tx_isSet = false;
}

SWGLimeSdrMIMOReport::~SWGLimeSdrMIMOReport() {
    this->cleanup();
}

void
SWGLimeSdrMIMOReport::init() {
    hw_timestamp = 0;
    m_hw_timestamp_isSet = false;
    temperature = 0.0f;
    m_temperature_isSet = false;
    gpio_dir = 0;
    m_gpio_dir_isSet = false;
    gpio_pins = 0;
    m_gpio_pins_isSet = false;
    success_rx = 0;
    m_success_rx_isSet = false;
    stream_active_rx = 0;
    m_stream_active_rx_isSet = false;
    fifo_size_rx = 0;
    m_fifo_size_rx_isSet = false;
    fifo_fill_rx = 0;
    m_fifo_fill_rx_isSet = false;
    underrun_count_rx = 0;
    m_underrun_count_rx_isSet = false;
    overrun_count_rx = 0;
    m_overrun_count_rx_isSet = false;
    dropped_packets_count_rx = 0;
    m_dropped_packets_count_rx_isSet = false;
    link_rate_rx = 0.0f;
    m_link_rate_rx_isSet = false;
    success_tx = 0;
    m_success_tx_isSet = false;
    stream_active_tx = 0;
    m_stream_active_tx_isSet = false;
    fifo_size_tx = 0;
    m_fifo_size_tx_isSet = false;
    fifo_fill_tx = 0;
    m_fifo_fill_tx_isSet = false;
    underrun_count_tx = 0;
    m_underrun_count_tx_isSet = false;
    overrun_count_tx = 0;
    m_overrun_count_tx_isSet = false;
    dropped_packets_count_tx = 0;
    m_dropped_packets_count_tx_isSet = false;
    link_rate_tx = 0.0f;
    m_link_rate_tx_isSet = false;
}

void
SWGLimeSdrMIMOReport::cleanup() {




















}

SWGLimeSdrMIMOReport*
SWGLimeSdrMIMOReport::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGLimeSdrMIMOReport::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&hw_timestamp, pJson["hwTimestamp"], "qint32", "");
    
    ::SWGSDRangel::setValue(&temperature, pJson["temperature"], "float", "");
    
    ::SWGSDRangel::setValue(&gpio_dir, pJson["gpioDir"], "qint32", "");
    
    ::SWGSDRangel::setValue(&gpio_pins, pJson["gpioPins"], "qint32", "");
    
    ::SWGSDRangel::setValue(&success_rx, pJson["successRx"], "qint32", "");
    
    ::SWGSDRangel::setValue(&stream_active_rx, pJson["streamActiveRx"], "qint32", "");
    
    ::SWGSDRangel::setValue(&fifo_size_rx, pJson["fifoSizeRx"], "qint32", "");
    
    ::SWGSDRangel::setValue(&fifo_fill_rx, pJson["fifoFillRx"], "qint32", "");
    
    ::SWGSDRangel::setValue(&underrun_count_rx, pJson["underrunCountRx"], "qint32", "");
    
    ::SWGSDRangel::setValue(&overrun_count_rx, pJson["overrunCountRx"], "qint32", "");
    
    ::SWGSDRangel::setValue(&dropped_packets_count_rx, pJson["droppedPacketsCountRx"], "qint32", "");
    
    ::SWGSDRangel::setValue(&link_rate_rx, pJson["linkRateRx"], "float", "");
    
    ::SWGSDRangel::setValue(&success_tx, pJson["successTx"], "qint32", "");
    
    ::SWGSDRangel::setValue(&stream_active_tx, pJson["streamActiveTx"], "qint32", "");
    
    ::SWGSDRangel::setValue(&fifo_size_tx, pJson["fifoSizeTx"], "qint32", "");
    
    ::SWGSDRangel::setValue(&fifo_fill_tx, pJson["fifoFillTx"], "qint32", "");
    
    ::SWGSDRangel::setValue(&underrun_count_tx, pJson["underrunCountTx"], "qint32", "");
    
    ::SWGSDRangel::setValue(&overrun_count_tx, pJson["overrunCountTx"], "qint32", "");
    
    ::SWGSDRangel::setValue(&dropped_packets_count_tx, pJson["droppedPacketsCountTx"], "qint32", "");
    
    ::SWGSDRangel::setValue(&link_rate_tx, pJson["linkRateTx"], "float", "");
    
}

QString
SWGLimeSdrMIMOReport::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGLimeSdrMIMOReport::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_hw_timestamp_isSet){
        obj->insert("hwTimestamp", QJsonValue(hw_timestamp));
    }
    if(m_temperature_isSet){
        obj->insert("temperature", QJsonValue(temperature));
    }
    if(m_gpio_dir_isSet){
        obj->insert("gpioDir", QJsonValue(gpio_dir));
    }
    if(m_gpio_pins_isSet){
        obj->insert("gpioPins", QJsonValue(gpio_pins));
    }
    if(m_success_rx_isSet){
        obj->insert("successRx", QJsonValue(success_rx));
    }
    if(m_stream_active_rx_isSet){
        obj->insert("streamActiveRx", QJsonValue(stream_active_rx));
    }
    if(m_fifo_size_rx_isSet){
        obj->insert("fifoSizeRx", QJsonValue(fifo_size_rx));
    }
    if(m_fifo_fill_rx_isSet){
        obj->insert("fifoFillRx", QJsonValue(fifo_fill_rx));
    }
    if(m_underrun_count_rx_isSet){
        obj->insert("underrunCountRx", QJsonValue(underrun_count_rx));
    }
    if(m_overrun_count_rx_isSet){
        obj->insert("overrunCountRx", QJsonValue(overrun_count_rx));
    }
    if(m_dropped_packets_count_rx_isSet){
        obj->insert("droppedPacketsCountRx", QJsonValue(dropped_packets_count_rx));
    }
    if(m_link_rate_rx_isSet){
        obj->insert("linkRateRx", QJsonValue(link_rate_rx));
    }
    if(m_success_tx_isSet){
        obj->insert("successTx", QJsonValue(success_tx));
    }
    if(m_stream_active_tx_isSet){
        obj->insert("streamActiveTx", QJsonValue(stream_active_tx));
    }
    if(m_fifo_size_tx_isSet){
        obj->insert("fifoSizeTx", QJsonValue(fifo_size_tx));
    }
    if(m_fifo_fill_tx_isSet){
        obj->insert("fifoFillTx", QJsonValue(fifo_fill_tx));
    }
    if(m_underrun_count_tx_isSet){
        obj->insert("underrunCountTx", QJsonValue(underrun_count_tx));
    }
    if(m_overrun_count_tx_isSet){
        obj->insert("overrunCountTx", QJsonValue(overrun_count_tx));
    }
    if(m_dropped_packets_count_tx_isSet){
        obj->insert("droppedPacketsCountTx", QJsonValue(dropped_packets_count_tx));
    }
    if(m_link_rate_tx_isSet){
        obj->insert("linkRateTx", QJsonValue(link_rate_tx));
    }

    return obj;
}

qint32
SWGLimeSdrMIMOReport::getHwTimestamp() {
    return hw_timestamp;
}
void
SWGLimeSdrMIMOReport::setHwTimestamp(qint32 hw_timestamp) {
    this->hw_timestamp = hw_timestamp;
    this->m_hw_timestamp_isSet = true;
}

float
SWGLimeSdrMIMOReport::getTemperature() {
    return temperature;
}
void
SWGLimeSdrMIMOReport::setTemperature(float temperature) {
    this->temperature = temperature;
    this->m_temperature_isSet = true;
}

qint32
SWGLimeSdrMIMOReport::getGpioDir() {
    return gpio_dir;
}
void
SWGLimeSdrMIMOReport::setGpioDir(qint32 gpio_dir) {
    this->gpio_dir = gpio_dir;
    this->m_gpio_dir_isSet = true;
}

qint32
SWGLimeSdrMIMOReport::getGpioPins() {
    return gpio_pins;
}
void
SWGLimeSdrMIMOReport::setGpioPins(qint32 gpio_pins) {
    this->gpio_pins = gpio_pins;
    this->m_gpio_pins_isSet = true;
}

qint32
SWGLimeSdrMIMOReport::getSuccessRx() {
    return success_rx;
}
void
SWGLimeSdrMIMOReport::setSuccessRx(qint32 success_rx) {
    this->success_rx = success_rx;
    this->m_success_rx_isSet = true;
}

qint32
SWGLimeSdrMIMOReport::getStreamActiveRx() {
    return stream_active_rx;
}
void
SWGLimeSdrMIMOReport::setStreamActiveRx(qint32 stream_active_rx) {
    this->stream_active_rx = stream_active_rx;
    this->m_stream_active_rx_isSet = true;
}

qint32
SWGLimeSdrMIMOReport::getFifoSizeRx() {
    return fifo_size_rx;
}
void
SWGLimeSdrMIMOReport::setFifoSizeRx(qint32 fifo_size_rx) {
    this->fifo_size_rx = fifo_size_rx;
    this->m_fifo_size_rx_isSet = true;
}

qint32
SWGLimeSdrMIMOReport::getFifoFillRx() {
    return fifo_fill_rx;
}
void
SWGLimeSdrMIMOReport::setFifoFillRx(qint32 fifo_fill_rx) {
    this->fifo_fill_rx = fifo_fill_rx;
    this->m_fifo_fill_rx_isSet = true;
}

qint32
SWGLimeSdrMIMOReport::getUnderrunCountRx() {
    return underrun_count_rx;
}
void
SWGLimeSdrMIMOReport::setUnderrunCountRx(qint32 underrun_count_rx) {
    this->underrun_count_rx = underrun_count_rx;
    this->m_underrun_count_rx_isSet = true;
}

qint32
SWGLimeSdrMIMOReport::getOverrunCountRx() {
    return overrun_count_rx;
}
void
SWGLimeSdrMIMOReport::setOverrunCountRx(qint32 overrun_count_rx) {
    this->overrun_count_rx = overrun_count_rx;
    this->m_overrun_count_rx_isSet = true;
}

qint32
SWGLimeSdrMIMOReport::getDroppedPacketsCountRx() {
    return dropped_packets_count_rx;
}
void
SWGLimeSdrMIMOReport::setDroppedPacketsCountRx(qint32 dropped_packets_count_rx) {
    this->dropped_packets_count_rx = dropped_packets_count_rx;
    this->m_dropped_packets_count_rx_isSet = true;
}

float
SWGLimeSdrMIMOReport::getLinkRateRx() {
    return link_rate_rx;
}
void
SWGLimeSdrMIMOReport::setLinkRateRx(float link_rate_rx) {
    this->link_rate_rx = link_rate_rx;
    this->m_link_rate_rx_isSet = true;
}

qint32
SWGLimeSdrMIMOReport::getSuccessTx() {
    return success_tx;
}
void
SWGLimeSdrMIMOReport::setSuccessTx(qint32 success_tx) {
    this->success_tx = success_tx;
    this->m_success_tx_isSet = true;
}

qint32
SWGLimeSdrMIMOReport::getStreamActiveTx() {
    return stream_active_tx;
}
void
SWGLimeSdrMIMOReport::setStreamActiveTx(qint32 stream_active_tx) {
    this->stream_active_tx = stream_active_tx;
    this->m_stream_active_tx_isSet = true;
}

qint32
SWGLimeSdrMIMOReport::getFifoSizeTx() {
    return fifo_size_tx;
}
void
SWGLimeSdrMIMOReport::setFifoSizeTx(qint32 fifo_size_tx) {
    this->fifo_size_tx = fifo_size_tx;
    this->m_fifo_size_tx_isSet = true;
}

qint32
SWGLimeSdrMIMOReport::getFifoFillTx() {
    return fifo_fill_tx;
}
void
SWGLimeSdrMIMOReport::setFifoFillTx(qint32 fifo_fill_tx) {
    this->fifo_fill_tx = fifo_fill_tx;
    this->m_fifo_fill_tx_isSet = true;
}

qint32
SWGLimeSdrMIMOReport::getUnderrunCountTx() {
    return underrun_count_tx;
}
void
SWGLimeSdrMIMOReport::setUnderrunCountTx(qint32 underrun_count_tx) {
    this->underrun_count_tx = underrun_count_tx;
    this->m_underrun_count_tx_isSet = true;
}

qint32
SWGLimeSdrMIMOReport::getOverrunCountTx() {
    return overrun_count_tx;
}
void
SWGLimeSdrMIMOReport::setOverrunCountTx(qint32 overrun_count_tx) {
    this->overrun_count_tx = overrun_count_tx;
    this->m_overrun_count_tx_isSet = true;
}

qint32
SWGLimeSdrMIMOReport::getDroppedPacketsCountTx() {
    return dropped_packets_count_tx;
}
void
SWGLimeSdrMIMOReport::setDroppedPacketsCountTx(qint32 dropped_packets_count_tx) {
    this->dropped_packets_count_tx = dropped_packets_count_tx;
    this->m_dropped_packets_count_tx_isSet = true;
}

float
SWGLimeSdrMIMOReport::getLinkRateTx() {
    return link_rate_tx;
}
void
SWGLimeSdrMIMOReport::setLinkRateTx(float link_rate_tx) {
    this->link_rate_tx = link_rate_tx;
    this->m_link_rate_tx_isSet = true;
}


bool
SWGLimeSdrMIMOReport::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_hw_timestamp_isSet){
            isObjectUpdated = true; break;
        }
        if(m_temperature_isSet){
            isObjectUpdated = true; break;
        }
        if(m_gpio_dir_isSet){
            isObjectUpdated = true; break;
        }
        if(m_gpio_pins_isSet){
            isObjectUpdated = true; break;
        }
        if(m_success_rx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_stream_active_rx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_fifo_size_rx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_fifo_fill_rx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_underrun_count_rx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_overrun_count_rx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_dropped_packets_count_rx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_link_rate_rx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_success_tx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_stream_active_tx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_fifo_size_tx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_fifo_fill_tx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_underrun_count_tx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_overrun_count_tx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_dropped_packets_count_tx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_link_rate_tx_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

