# esphome-jk-bms-can

![GitHub stars](https://img.shields.io/github/stars/Sleeper85/esphome-jk-bms-can)
![GitHub forks](https://img.shields.io/github/forks/Sleeper85/esphome-jk-bms-can)
![GitHub watchers](https://img.shields.io/github/watchers/Sleeper85/esphome-jk-bms-can)

**ESPHome component to monitor a Jikong Battery Management System (JK-BMS) and communicate with inverters supporting CAN bus protocol compatible with Pylontech V1.3 and Goodwe V1.5.**

**Note: Pylontech uses 15s/48v and many others uses 16s/51.2v @3.2v/cell nominal.**
Other battery profiles that utilise the **PYLON** protocol with different cell counts may also work, eg Alpha Ess Smile, BYD Battery-Box LV Flex Lite.
Select the correct battery profile in the inverter to match your battery pack!

The ESP32 communicates with the JK-BMS using the RS485 port (GPS) which is in fact not RS485 but 3.3V UART-TTL, so it can be directly connected to the ESP32.
The ESP32 then sends the required CAN bus data to the inverter via a TJA1050 or TJA1051T CAN bus transceiver.

**Sends over CAN bus to inverter:**
  - Battery Voltage
  - Battery Current (+charge, -discharge)
  - State of Charge (SOC)
  - State of health (SOH)
  - BMS Temperature
  - Charging Voltage
  - Charging Amps
  - Discharge min Voltage
  - Battery name 'PYLON'
  - Alarms: Cell over/under voltage, Charge/discharge over current, High/low Temp, BMS fault
  - Charging logic: Bulk charge with absorption timer followed or not by a float charge. Everything is easily configurable in Home Assistant.
  
**Note: This code support only one BMS connection per inverter and should work with inverters that support the Pylontech 1.3 CAN bus protocol.
I'm only testing it with my Deye SUN-6K-SG03-LP1-EU inverter.<br>
The CAN bus support is still in development and testing...<br>**

Tested with Deye inverter using the battery mode 'Lithium 00'.<br>
Tested with Goodwe inverter using the Goodwe LX U5.4-L battery profile.<br>
Each LX U5.4-L battery has 5.4kWh of storage, so select the number that is the closest match to your battery's total capacity.<br>

## Home Assistant integration

![Lovelace entities card](images/HA_Dashboard.png "HA Dashboard")

## Changelog

* V1.14.2 Sleeper85 : Improve 'Charging Voltage' behavior
* V1.14.1 Sleeper85 : Add 'Float charge function'
* V1.13.6 Sleeper85 : Add 'Absorption time' and 'Absorption Offset V.' slider
* V1.13.5 Sleeper85 : Set CAN manufacter to "PYLON" for improve compatibility with Deye and other inverters
* V1.13.4 Sleeper85 : Improve 'Charge Status' behavior + add 'Rebulk Offset V.' slider
* V1.13.3 uksa007   : Improve compatibility with Deye and other inverters
* V1.13.2 uksa007   : Send Max Temperature of T1, T2 to inverter
* V1.13.1 uksa007   : Fix compile issues with new version of ESPhome 2023.4.0, set rebulk offset to 2.5

## Supported devices

Inverters supporting CAN Pylon/Goodwe Low Voltage protocol should work, check your inverter manual to confirm.

The following are confirmed and known to work:
* Deye SUN-6k-SG03LP1-EU (reported by [@Sleeper85](https://github.com/Sleeper85/esphome-jk-bms-can))
* Deye SUN-5k-SG03LP1-EU (reported by [@vdiex](https://github.com/Uksa007/esphome-jk-bms-can/discussions/1#discussioncomment-4481364))
* Deye SUN-12K-SG04LP3-EU (reported by [@lucize](https://github.com/Uksa007/esphome-jk-bms-can/discussions/25#discussioncomment-5890844))
* Goodwe 3648-ES (GW5048-ES) (reported by [@jirdol](https://github.com/Uksa007/esphome-jk-bms-can/discussions/1#discussioncomment-5498743))
* Goodwe GW5000S-BP (reported by [@Uksa007](https://github.com/Uksa007/esphome-jk-bms-can/discussions/2#discussion-4469605) using the "Goodwe LX U5.4-L * 3" battery profile)
* Sofar solar me3000sp (reported by [@starman](https://diysolarforum.com/threads/jk-bms-can-bus-comms-now-possible-for-inverters-that-support-goodwe-and-pylontech-batteries.48963/post-755539))
* Turbo energy (reported by [@ibikku](https://github.com/Uksa007/esphome-jk-bms-can/discussions/13#discussion-4823950))

<br>All JK-BMS models with software version `>=6.0` are using the implemented protocol and should be supported.

* JK-BD4A8S4P, hw 11.xw, sw 11.24, using `JK02_32S` (reported by [@austin202220](https://github.com/syssi/esphome-jk-bms/issues/297))
* JK-BD6A17S6P, hw 7.2, sw 7.1.0H
* JK-BD6A17S8P, hw 9.x, sw 9.01G (reported by [@jonadis](https://github.com/syssi/esphome-jk-bms/issues/35#issuecomment-1035312712))
* JK-BD6A20S10P, hw 10.XW, sw 10.07 (reported by [@adadrag](https://github.com/syssi/esphome-jk-bms/issues/123))
* JK-BD6A20S12P, hw 11.XW, sw 11.281, using UART-TTL (reported by [@asiridissa](https://github.com/syssi/esphome-jk-bms/discussions/339))
* JK-BD6A24S6P, hw 6.x, sw 6.10S (reported by [@ziporah](https://github.com/syssi/esphome-jk-bms/issues/41))
* JK-BD6A24S10P, hw 8.x, sw 8.0.6G (reported by [@spoonwzd](https://github.com/syssi/esphome-jk-bms/issues/67#issuecomment-1093844076))
* JK-BD6A24S10P, hw 10.xw, sw 10.09 (reported by [@PMPoulsen](https://github.com/syssi/esphome-jk-bms/discussions/261#discussioncomment-5091812))
* JK-BD4A17S4P, hw 11.xw, sw 11.01 (reported by [@Condor-XYZ](https://github.com/syssi/esphome-jk-bms/issues/221))
* JK-BD4A17S4P, hw 11.xw, sw 11.27, using `JK02_32S` and/or UART-TTL (reported by [@hemskgren](https://github.com/syssi/esphome-jk-bms/issues/359))
* JK-B1A8S10P, hw 11.XW, sw 11.261, using `JK02_32S` (reported by [@Chickenbreast0](https://github.com/syssi/esphome-jk-bms/issues/346))
* JK-B1A24S15P, hw 8.x, sw 8.1.0H (reported by [@killee](https://github.com/syssi/esphome-jk-bms/discussions/4))
* JK-B1A20S15P, hw 8.x, sw 8.14U (reported by  [@trippfam07](https://github.com/syssi/esphome-jk-bms/issues/31))
* JK-B1A20S15P, hw 10.xw, sw 10.07 (reported by [@romeox44](https://github.com/syssi/esphome-jk-bms/discussions/125))
* JK-B1A20S15P, hw 10.xw, sw 10.10, using `JK02` (reported by [@austin202220](https://github.com/syssi/esphome-jk-bms/issues/297#issuecomment-1510685683))
* JK-B1A20S15P, hw 11.xw, sw 11.26, using UART-TTL (reported by [@Tesla72PL](https://github.com/syssi/esphome-jk-bms/issues/309))
* JK-B2A24S15P, hw 6.x, sw 6.1.3S (reported by [@miguel300477](https://github.com/syssi/esphome-jk-bms/issues/57))
* JK-B2A24S15P, hw 8.x, sw 8.21W (reported by [@mariusvaida](https://github.com/syssi/esphome-jk-bms/issues/120))
* JK-B2A24S15P, hw 10.xw, sw 10.07
* JK-B2A24S15P, hw 10.xw, sw 10.08 (reported by [@meccip](https://github.com/syssi/esphome-jk-bms/discussions/175#discussioncomment-3687287))
* JK-B2A24S150P, hw 10.xw, sw 10.10 (reported by [@nayias](https://github.com/syssi/esphome-jk-bms/discussions/257#discussioncomment-5062807))
* JK-B2A24S20P, hw 8.x, sw 8.1.2H (reported by [@KlausLi](https://github.com/syssi/esphome-jk-bms/issues/15#issuecomment-961447064))
* JK-B2A24S20P, hw 8.x, sw 8.20G (reported by [@rob-oravec](https://github.com/syssi/esphome-jk-bms/discussions/46))
* JK-B2A24S20P, hw 10.X-W, sw 10.02 (reported by [@SeByDocKy](https://github.com/syssi/esphome-jk-bms/issues/37#issuecomment-1040569576))
* JK-B2A24S20P, hw 10.XG, sw 10.07D30 (reported by [@TheSmartGerman](https://github.com/syssi/esphome-jk-bms/discussions/122))
* JK-B2A24S20P, hw 10.XW, sw 10.07 (reported by [@amagr0](https://github.com/syssi/esphome-jk-bms/issues/124#issuecomment-1166366196))
* JK-B2A8S20P,  hw 9.x, sw 9.01M3, using `JK02` (reported by [@EasilyBoredEngineer](https://github.com/syssi/esphome-jk-bms/discussions/110))
* JK-B2A8S20P, hw 9.x, sw 9.08W (reported by [@vrabi-cv](https://github.com/syssi/esphome-jk-bms/discussions/144#discussioncomment-3285901))
* JK-B2A8S20P, hw 11.XW, sw 11.17, using `JK02_32S` (reported by [@senfkorn](https://github.com/syssi/esphome-jk-bms/issues/147))
* JK-B2A8S20P, hw 11.XW, sw 11.26, using `JK02_32S` (reported by [@riker65](https://github.com/syssi/esphome-jk-bms/issues/276))
* JK-B2A20S20P, hw 10.XW, sw 10.09 (reported by [@markusgg84](https://github.com/syssi/esphome-jk-bms/discussions/173))
* JK-B2A20S20P, hw 10.XW, sw 11.21h, using `JK02_32S` (reported by [@Salve87](https://github.com/syssi/esphome-jk-bms/issues/308#issuecomment-1505614325))
* JK-B2A20S20P, hw 11.XW, sw 11.24H, using `JK02_32S` (reported by [@austin202220](https://github.com/syssi/esphome-jk-bms/discussions/232))
* JK-B2A20S20P, hw 11.XW, sw 11.25H, using `JK02_32S` (reported by [@iovcharyk](https://github.com/syssi/esphome-jk-bms/issues/249))
* JK-B5A24S, hw 8.x, sw 8.0.3M, using `JK04` (reported by [@JSladen](https://github.com/syssi/esphome-jk-bms/issues/213))
* JK-B2A16S, hw 3.0, sw 3.3.0, using `JK04` (reported by [@magnetus26](https://github.com/syssi/esphome-jk-bms/discussions/48))
* GW-24S4EB (NEEY/Heltec 4A Smart Active Balancer), hw HW-2.8.0, sw ZH-1.2.3 (reported by [@cristi2005](https://github.com/syssi/esphome-jk-bms/issues/109))
* GW-24S4EB (NEEY 4A Smart Active Balancer 4th generation), hw HW-3.2.0, sw ZH-1.2.4 (reported by [@fabhund](https://github.com/syssi/esphome-jk-bms/issues/310))

## Untested devices

* JK-BD6A20S6P

## Requirements

* [ESPHome 2022.11.0 or higher](https://github.com/esphome/esphome/releases).
* Generic ESP32, I use an ESP32 DevKit-v1 30 pin board ( NOTE: ESP32-S2 currently has issues with CAN BUS and does not work! )
* TJA1050 or TJA1051T CAN controller interface module and 4.7K resistor for 5v to 3.3v level shifing.
* Optional: JK RS485 Adaptor and RS484 to TTL3.3v Adaptor (see optional schematic below)

## Schematics

![Lovelace entities card](images/PCB_ESP32_JK-BMS-CAN_powered_by_JK-BMS.png "PCB ESP32 JK-BMS-CAN powered by JK-BMS")

![Lovelace entities card](images/PCB_ESP32_JK-BMS-CAN_Prototype.jpg "PCB ESP32 JK-BMS-CAN powered by JK-BMS")

![Lovelace entities card](images/JK-BMS_24S_GPS_port.png "PCB ESP32 JK-BMS-CAN powered by JK-BMS")


```
                RS485-TTL                   RS232-TTL                CAN BUS
┌──────────┐            ┌─────────┐             ┌─────────┐              ┌──────────┐
│          │<TX------RX>│16     23│<TX-------TX>|         |              |          |
│  JK-BMS  │<RX------TX>│17     22│<RX--4K7--RX>| TJA1050 |<---CAN H --->| Inverter |
│          │<----GND--->│         │<----GND---->|   CAN   |<---CAN L --->|          |
│          │  3.3V ---->│  ESP32  │<----5V----->|         |              |          |
└──────────┘            └─────────┘             └─────────┘              └──────────┘



Optional below, as seen in pic above: RS485 between JK-BMS GPS port and ESP32, uses JK RS485 adaptor and RS485 to TTL3.3v adaptor.

              RS485-TTL                  RS485             RS485-TTL               RS232-TTL                CAN BUS
┌──────────┐            ┌───────────┐           ┌────────┐           ┌─────────┐             ┌─────────┐              ┌──────────┐
│          │<--- TX --->│Y    JK   Y│<A------A+>│        │<TX-----RX>│16     23│<TX-------TX>|         |              |          |
│  JK-BMS  │<--- RX --->│W  RS485  W│<B------B->│ RS485  │<RX-----TX>│17     22│<RX--4K7--RX>| TJA1050 |<---CAN H --->| Inverter |
│          │<--- GND -->│B Adaptor B│<---GND--->│To 3.3V │<---GND--->|         |<----GND---->|   CAN   |<---CAN L --->|          |
│          │<--Bat V -->│R          │           │        │<---3.3V-->|  ESP32  |<----5V----->|         |              |          |
└──────────┘            └───────────┘           └────────┘           └─────────┘             └─────────┘              └──────────┘



# RS485-TTL jack on JK-BMS (4 Pin, JST 1.25mm pitch)
┌─── ─────── ────┐
│                │
│ O   O   O   O  │
│GND  RX  TX VBAT│ 
└────────────────┘
  │   │   │   | VBAT is full battery volatge eg 51.2V (No connect)
  │   │   └──── ESP32 GPIO16 (`rx_pin`)
  │   └──────── ESP32 GPIO17 (`tx_pin`)
  └──────────── GND
```


The UART-TTL (labeled as `RS485`) socket of the BMS can be attached to any UART pins of the ESP. A hardware UART should be preferred because of the high baudrate (115200 baud). The connector is called 4 Pin JST with 1.25mm pitch.

## Installation

This YAML file is based on the [@syssi](https://github.com/syssi) [esphome-jk-bms](https://github.com/syssi/esphome-jk-bms) repository.

```yaml
external_components:
  - source: github://syssi/esphome-jk-bms@main
```

**Installation procedure:**

```bash
# Install esphome
pip3 install esphome

# Clone this external component
git clone https://github.com/Sleeper85/esphome-jk-bms-can.git
cd esphome-jk-bms-can

# Create a secrets.yaml containing some setup specific secrets
cat > secrets.yaml <<EOF
wifi_ssid: MY_WIFI_SSID
wifi_password: MY_WIFI_PASSWORD

# Validate the configuration, create a binary, upload it, and start logs
esphome run esp32-jk-bms-can.yaml

# Optional add to Home Assistant
In Home Assistant under settings->Intergration "Add Intergration" select ESPHome add device jk-bms-can if found or supply ip address of ESP32

```

## ESPHome bash command

```bash
# test the config
esphome config esp32-jk-bms-can.yaml

# install the config in ESP32
esphome run esp32-jk-bms-can.yaml

# check the logs	
esphome logs esp32-jk-bms-can.yaml
```

## Known issues

* ESP32 has a bug that causes WDT reboot if no other devices on CAN bus to ACK the packets. If you try to run without inverter it will not work as it will constantly WDT reboot!
* Probably daily reboots if the ESP32 is not connected to Home Assistant.
* The battery type sensor is pretty useless because the BMS reports always the same value (`Ternary Lithium`). Regardless of which battery type was set / parameter set was loaded via the android app. ([#9][i9])
* ESP32: Adding all supported sensors can lead to a stack overflow / boot loop. This can be solved by increasing the stack size. ([#63][i63])

[i9]: https://github.com/syssi/esphome-jk-bms/issues/9
[i63]: https://github.com/syssi/esphome-jk-bms/issues/63

## Goodies

A user of the [@syssi](https://github.com/syssi) [esphome-jk-bms](https://github.com/syssi/esphome-jk-bms) project ([@dr3amr](https://github.com/dr3amr)) shared some [Home Assistant Lovelace UI cards for a beautiful dashboard here](https://github.com/syssi/esphome-jk-bms/discussions/230).

![Lovelace entities card](images/lovelace-cards-contribution.png "Home Assistant Lovelace UI cards")

## Debugging

If this component doesn't work out of the box for your device please update your configuration to enable the debug output of the UART component and increase the log level to the see outgoing and incoming serial traffic:

```
logger:
  level: DEBUG

uart:
  id: uart_0
  baud_rate: 115200
  rx_buffer_size: 384
  tx_pin: ${tx_pin}
  rx_pin: ${rx_pin}
  debug:
    direction: BOTH
```

## References

* https://www.patreon.com/Uksa007Codedevelopment Thanks to @uksa007 for making the original CAN code.
* https://github.com/syssi/esphome-jk-bms Thanks go to @syssi for help and making the original RS485 code.

